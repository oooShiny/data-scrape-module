<?php

/**
 * Check if ESPN league is set to private.
 *
 * @param $html
 *    Page being scraped.
 * @return bool $is_private
 *
 */
function _espn_is_private($html) {
  // TODO: If the page title is "Log In," this is a private league.
  if (strpos($html->data, '<title>Log In - Free Fantasy Football -  ESPN</title>') !== FALSE) {
    $is_private = TRUE;
  } else {
    $is_private = FALSE;
  }
  return $is_private;
}

/**
 * @param $league_id
 *
 * @return mixed
 */
function _espn_get_espn_id_from_node($league_id) {
  $db_league = db_select('games', 'g')
    ->fields('g')
    ->condition('g.league', $league_id,'=')
    ->range(0,1)
    ->execute()
    ->fetchField();

  return $db_league;
}

function _espn_get_html($url) {
  $html = drupal_http_request($url);
  if ($html->code == '200') {
    return $html;
  }
}
/**
 * Scrape the Standings page (http://games.espn.go.com/ffl/standings) to get the
 * current standings.
 *
 * @param $league_id
 *    League ID from ESPN website.
 * @return array $standings
 *    An array of the current standings.
 */
function _espn_scrape_current_standings($league_id) {
  $standings = array();
  $url = 'http://games.espn.go.com/ffl/standings?leagueId=' . $league_id;
  // scrape HTML from ESPN league standings page
  $html = drupal_http_request($url);
  // split string on each standings table
  $tables = preg_split( '/<table (.*) class="tableBody" /', $html->data );
  foreach($tables as $table) {
    $rows = array();
    if(strpos( $table, 'DOCTYPE HTML PUBLIC' ) !== FALSE) {
      // skip this one
    }elseif(strpos($table, '<td colspan="6">') !== FALSE) {
      // grab all rows from the table
      $rows = preg_split('/<tr class="tableBody" bgcolor=#(.{6})>/', $table);
      $colspan = 6;
    }else {
      $rows    = preg_split('/<tr class="(odd|even)Row bodyCopy sortableRow">/', $table);
      $colspan = 7;
    }
    if ($rows) {
      foreach($rows as $row){
        if(strpos( $row, 'tableHead' ) !== FALSE) {
          // skip header row
        }else{
          if($colspan == 6){
            // break apart HTML to get pertinent information
            $data = preg_split('/<a title="/', $row);
            $split = explode('"', $data[1]);
            // format data
            $team_link = explode('&amp;', $split[2]);
            $team_id = explode('=', $team_link[1]);
            $id = $team_id[1];
            $team_info = explode('(', $split[0]);
            $wins = explode('>', $split[7]);
            $losses = explode('>', $split[9]);
            $ties = explode('>', $split[11]);
            // store team info in standings array
            $standings[$id]['owner'] = rtrim(array_pop($team_info), ')');

            $standings[$id]['name'] = rtrim(implode('(', $team_info));
            $standings[$id]['wins'] = rtrim($wins[1], '</td' );
            $standings[$id]['losses'] = rtrim($losses[1], '</td' );
            $standings[$id]['ties'] = rtrim($ties[1], '</td' );
          }elseif($colspan == 7) {
            $data = preg_split('/<td align="right" class="sortable(.{2,6})">/', $row);
            $team_link = explode('&amp;', $data[0]);
            $team_id = explode('=', $team_link[1]);
            $id = $team_id[1];
            $standings[$id]['pf'] = rtrim($data[1], '</td>');
            $standings[$id]['pa'] = rtrim($data[2], '</td>');
            $streak = explode('>', $data[6]);
            $standings[$id]['streak'] = rtrim($streak[1], '</td');
          }
        }
      }
    }
  }
  return $standings;
}

/**
 * Scrape ESPN Final Standings pages for each year the league has been active
 * (which we get from the _espn_get_years() function). Returns an array with
 * all of the historical data for us with which we can create field collections
 * for each team.
 *
 * @param $league_id
 *    League ID from ESPN website.
 * @param array $years
 *    Array of years the league has been active.
 * @return array $history
 *    Array of standings by year > team.
 */
function _espn_scrape_historical_standings($league_id, Array $years) {
  $history = array();
  // Go through each year and get final standings.
  foreach($years as $year) {
    $url = 'http://games.espn.go.com/ffl/tools/finalstandings?leagueId=' . $league_id . '&seasonId=' . $year;
    // scrape HTML from ESPN league standings page
    $html = drupal_http_request( $url );
    // pull out the standings table from the HTML code
    $break = preg_split( '/<table .* id="finalRankingsTable" .* /', $html->data );
    // pull out each row of the table, save in array
    $table = preg_split( '/<tr class="sortableRow .*>/', $break[1] );

    foreach ( $table as $row ) {
      if ( strpos( $row, 'FINAL LEAGUE STANDINGS' ) !== FALSE ) {
        // skip first row (table column headings)
      } else {
        $cells = preg_split( '/<td .*?>/', $row );
        $team_info = explode( '"', $cells[2] );
        $team_name = explode( '(', $team_info[1] );
        $team_owner = rtrim( $team_name[1], ')' );
        $team_id = explode( '&amp;', $team_info[3] );
        $id = substr( $team_id[1], 7 );

        $history[ $year ][$id]['team_name'] = htmlentities($team_name[0], ENT_IGNORE, "UTF-8");
        $history[ $year ][$id]['team_owner'] = htmlentities($team_owner, ENT_IGNORE, "UTF-8");

        $record                     = explode( '-', $cells[5] );
        $history[ $year ][$id]['wins']   = ltrim( $record[4], '>' );
        $history[ $year ][$id]['losses'] = str_replace( "</td>\n", '', $record[5] );
        $history[ $year ][$id]['ties']   = ( $record[6] ? str_replace( "</td>\n", '', $record[6] ) : '0' );

        $history[ $year ][$id]['pf'] = str_replace( "</td>\n", '', $cells[6] );
        $history[ $year ][$id]['pa'] = str_replace( "</td>\n", '', $cells[7] );
      }
    }
  }
  return $history;
}

/**
 * @param $league_id
 *    League ID from ESPN website.
 * @param array $years
 *    Array of years the league has been active.
 * @return array $champion
 *    Array of champions by year.
 */
function _espn_scrape_league_champions($league_id, Array $years) {
  $champion = array();
  // Get the individual teams info for this league.
  $teams = get_teams_from_league_id($league_id);
  // Go through each year and get final standings.
  foreach($years as $year) {
    $url = 'http://games.espn.go.com/ffl/tools/finalstandings?leagueId=' . $league_id . '&seasonId=' . $year;
    // scrape HTML from ESPN league standings page
    $html = drupal_http_request( $url );
    // pull out the standings table from the HTML code
    $break = preg_split( '/<table .* id="finalRankingsTable" .* /', $html->data );
    // pull out each row of the table, save in array
    $table = preg_split( '/<tr class="sortableRow .*>/', $break[1] );

    foreach ( $table as $row ) {
      if ( strpos( $row, 'FINAL LEAGUE STANDINGS' ) !== FALSE ) {
        // skip first row (table column headings)
      } else {
        $cells = preg_split( '/<td .*?>/', $row );
        if (strpos($cells[1], '<!-- 01 (for sorting) -->')) {
          // This is the champion, save this info.
          $team_info = explode( '"', $cells[2] );
          $team_id = explode( '&amp;', $team_info[3] );
          $id = substr( $team_id[1], 7 );

          $champion[$year] = $teams[$id];
        }
      }
    }
  }
  return $champion;
}

/**
 * @param $league_id
 *    League ID from ESPN website.
 * @param $year
 *    Year argument to pass to ESPN URL to get certain year schedule page.
 */
function _espn_scrape_schedule($league_id, $year) {

}

/**
 * Scrape ESPN homepage for the Year selection dropdown. This will give us
 * an array with the years the league has been active.
 *
 * @param $league_id
 *    League ID from ESPN website.
 * @return array $years
 *    Array of years in YYYY format (eg. 2016)
 */
function _espn_scrape_years($league_id) {
  //TODO: Rewrite this to more accurately figure out how long the league has been around. Maybe save to the DB?
  $url = 'http://games.espn.go.com/ffl/leagueoffice?leagueId='.$league_id;
  // Scrape HTML from ESPN league homepage.
  $html = drupal_http_request($url);
  // TODO: Check if league is private for each year.
  $is_private = _espn_is_private($html);
  if($is_private == FALSE) {
    // Get the select box with prior years in it.
    $select = preg_split('/<select/', $html->data);
    $years = array();
    // If we can find the select box, go through each one to get the years.
    if(array_key_exists(1, $select)){
      $options = preg_split('/<option/', $select[1]);
      unset($options[0]);
      foreach($options AS $year) {
        $split = preg_split('/value="/', $year);
        $years[] = substr($split[1], 0, 4);
      }
    } else {
      // Can't find the select box (league not active for current season or first season).
      // Redo the scrape for last year instead.
      $last_year = date('Y') - 1;
      $url .= '&seasonId=' . $last_year;
      $html = drupal_http_request($url);
      $select = preg_split('/<select/', $html->data);
      // Check again to make sure league isn't just set to private.
      if(array_key_exists(1, $select)){
        $options = preg_split('/<option/', $select[1]);
        unset($options[0]);
        foreach ($options AS $year) {
          $split   = preg_split('/value="/', $year);
          $years[] = substr($split[1], 0, 4);
        }
      }
      else {
        // Check to see if this is the inaugural season, and not a private league.
        $history_url = 'http://games.espn.go.com/ffl/history?leagueId=' . $league_id;
        $history_html = drupal_http_request($history_url);
        // History page will give a message saying it's the inaugural season.
        $inaugural = preg_split('/inaugural/', $history_html->data);
        if (array_key_exists(1, $inaugural)) {
          // Add current year to years array.
          $years[] = date('Y');
        }
        else {
          // At this point, we're pretty sure it's a private league. Set the error.
          $years[0] = 'ERROR';
          $years[1] = 'Your league is set to private, which means we can\'t scrape the data.';
        }
      }
    }
  } else {
    //TODO: League is private. Notify somehow?
  }
  return $years;
}

/*
 * Get all games that a team has participated in.
 * $team_id: the ESPN team ID
 * $league_id: the ESPN league ID
 * $league_og: the Drupal organic group node ID
 */
function _espn_get_games($team_id, $league_id, $league_og) {
  $games = array();
  $teams = array();
  // Get all of the teams in the league.
  $league_teams = db_query("SELECT n.title, og.gid, t.field_team_id_value FROM node n
    LEFT JOIN og_membership og ON og.etid = n.nid
    LEFT JOIN field_data_field_team_id t ON t.entity_id = n.nid
    WHERE n.type = 'team'
    AND og.gid = :gid", array(':gid' => $league_og));

  foreach($league_teams as $team) {
    $teams[$team->field_team_id_value] = $team->title;
  }

  // Get home games.
  $homegames = db_select('games', 'g')
    ->fields('g')
    ->condition('g.league', $league_id,'=')
    ->condition('g.home', $team_id, '=')
    ->orderBy('season', 'DESC')
    ->orderBy('week', 'ASC')
    ->execute();

  // Get away games.
  $awaygames = db_select('games', 'g')
    ->fields('g')
    ->condition('g.league', $league_id,'=')
    ->condition('g.away', $team_id, '=')
    ->orderBy('season', 'DESC')
    ->orderBy('week', 'ASC')
    ->execute();

  // Add home games to the master list.
  foreach($homegames as $game) {
    $games[$game->season][$game->week]['home_id'] = $game->home;
    $games[$game->season][$game->week]['home'] = $teams[$game->home];
    $games[$game->season][$game->week]['homescore'] = $game->homescore;
    $games[$game->season][$game->week]['away_id'] = $game->away;
    $games[$game->season][$game->week]['away'] = $teams[$game->away];
    $games[$game->season][$game->week]['awayscore'] = $game->awayscore;

    if($game->homescore > $game->awayscore) {
      $games[$game->season][$game->week]['result'] = 'win';
    }
    elseif($game->homescore < $game->awayscore) {
      $games[$game->season][$game->week]['result'] = 'loss';
    }
    else {
      $games[$game->season][$game->week]['result'] = 'tie';
    }
  }

  // Add away games to the master list.
  foreach($awaygames as $game) {
    $games[$game->season][$game->week]['home_id'] = $game->home;
    $games[$game->season][$game->week]['home'] = $teams[$game->home];
    $games[$game->season][$game->week]['homescore'] = $game->homescore;
    $games[$game->season][$game->week]['away_id'] = $game->away;
    $games[$game->season][$game->week]['away'] = $teams[$game->away];
    $games[$game->season][$game->week]['awayscore'] = $game->awayscore;

    if($game->homescore < $game->awayscore) {
      $games[$game->season][$game->week]['result'] = 'win';
    }
    elseif($game->homescore > $game->awayscore) {
      $games[$game->season][$game->week]['result'] = 'loss';
    }
    else {
      $games[$game->season][$game->week]['result'] = 'tie';
    }
  }

  return $games;
}
