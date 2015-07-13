<?php

/**
 * Build the matchup data based on information from 2 teams.
 * This is where the magic happens!
 */
function matchup_builder($team1, $team2, $leagueID)
{
  $result = array();
  // Set these initially so we can check against 'em later.
  $result['records']['nailbiter']['score'] = 999;
  $result['records']['blowout']['score'] = 0;
  $result['totals']['homewins'] = 0;
  $result['totals']['awaywins'] = 0;

  // Get team names.
  $team1node = node_load($team1);
  $result['team1name'] = $team1node->title;
  $result['team1id'] = $team1node->field_team_id['und'][0]['value'];

  $team2node = node_load($team2);
  $result['team2name'] = $team2node->title;
  $result['team2id'] = $team2node->field_team_id['und'][0]['value'];
  // Get all game data for both teams.
  $query = "SELECT * FROM games WHERE league = '".$leagueID."' AND home IN ('".$result['team1id']."', '".$result['team2id']."') AND away IN ('".$result['team1id']."', '".$result['team2id']."')";
  $games = db_query($query);
  // Cycle through the data to organize it.
  foreach($games as $game){
    // Get basic game stats.
    $result['games'][$game->id]['season'] = $game->season;
    $result['games'][$game->id]['week'] = $game->week;
    $result['games'][$game->id]['homescore'] = $game->homescore;
    $result['games'][$game->id]['home'] = $game->home;
    $result['games'][$game->id]['awayscore'] = $game->awayscore;
    $result['games'][$game->id]['away'] = $game->away;

    // Set some defaults to get rid of PHP notices.
    if (!isset($result['totals'][$game->home]['wins'])) {
      $result['totals'][$game->home]['wins'] = 0;
    }
    if (!isset($result['totals'][$game->home]['losses'])) {
      $result['totals'][$game->home]['losses'] = 0;
    }
    if (!isset($result['totals'][$game->away]['wins'])) {
      $result['totals'][$game->away]['wins'] = 0;
    }
    if (!isset($result['totals'][$game->away]['losses'])) {
      $result['totals'][$game->away]['losses'] = 0;
    }

      // Figure out win/loss record.
    if($game->homescore + $game->awayscore > 0) {
      if ($game->homescore > $game->awayscore) {
        $result['totals'][$game->home]['wins'] += 1;
        $result['totals'][$game->away]['losses'] += 1;
        $result['totals']['homewins'] += 1;
      } elseif ($game->homescore < $game->awayscore) {
        $result['totals'][$game->away]['wins'] += 1;
        $result['totals'][$game->home]['losses'] += 1;
        $result['totals']['awaywins'] += 1;
      } else {
        if (isset($result['totals'][$game->away]['ties'])) {
          $result['totals'][$game->away]['ties'] += 1;
          $result['totals'][$game->home]['ties'] += 1;
        } else {
          $result['totals'][$game->away]['ties'] = 1;
          $result['totals'][$game->home]['ties'] = 1;
        }
      }
    }
    $margin = abs($game->homescore - $game->awayscore);
    $homewin = $game->homescore - $game->awayscore;
    $awaywin = $game->awayscore - $game->homescore;
// Biggest win.
    if($margin != 0 && $homewin > 0 && $margin > $result['records']['blowout']['score']){
      $result['records']['blowout']['score'] = abs($game->homescore - $game->awayscore);
      $result['records']['blowout']['winner'] = $game->home;
      $result['records']['blowout']['loser'] = $game->away;
      $result['records']['blowout']['week'] = $game->week;
      $result['records']['blowout']['season'] = $game->season;
    }elseif($margin != 0 && $awaywin > 0 && $margin > $result['records']['blowout']['score']){
      $result['records']['blowout']['score'] = abs($game->awayscore - $game->homescore);
      $result['records']['blowout']['winner'] = $game->away;
      $result['records']['blowout']['loser'] = $game->home;
      $result['records']['blowout']['week'] = $game->week;
      $result['records']['blowout']['season'] = $game->season;
    }
// Closest game.
    if($margin != 0 && $homewin > 0 && $margin < $result['records']['nailbiter']['score']){
      $result['records']['nailbiter']['score'] = abs($game->homescore - $game->awayscore);
      $result['records']['nailbiter']['winner'] = $game->home;
      $result['records']['nailbiter']['loser'] = $game->away;
      $result['records']['nailbiter']['week'] = $game->week;
      $result['records']['nailbiter']['season'] = $game->season;
    }elseif($margin != 0 && $awaywin > 0 && $margin < $result['records']['nailbiter']['score']){
      $result['records']['nailbiter']['score'] = abs($game->awayscore - $game->homescore);
      $result['records']['nailbiter']['winner'] = $game->away;
      $result['records']['nailbiter']['loser'] = $game->home;
      $result['records']['nailbiter']['week'] = $game->week;
      $result['records']['nailbiter']['season'] = $game->season;
    }
// Playoff matchups.
    if(substr($game->week,0,1) == 'P')
    {
      if (isset($result['records']['playoff']['games'])) {
        $result['records']['playoff']['games'] += 1;
      } else {
        $result['records']['playoff']['games'] = 1;
      }
      $result['records']['playoff']['week'] = $game->week;
      $result['records']['playoff']['season'] = $game->season;
      if ($game->homescore > $game->awayscore) {
        if (isset($result['records']['playoff'][$game->home]['wins'])) {
          $result['records']['playoff'][$game->home]['wins'] += 1;
        } else {
          $result['records']['playoff'][$game->home]['wins'] = 1;
        }
        if (isset($result['records']['playoff'][$game->away]['losses'])) {
          $result['records']['playoff'][$game->away]['losses'] += 1;
        } else {
          $result['records']['playoff'][$game->away]['losses'] = 1;
        }
        if (isset($result['records']['playoff']['homewins'])) {
          $result['records']['playoff']['homewins'] += 1;
        } else {
          $result['records']['playoff']['homewins'] = 1;
        }
        $result['records']['playoff'][$game->season][$game->week]['winner'] = $game->home;
        $result['records']['playoff'][$game->season][$game->week]['loser'] = $game->away;
      } elseif ($game->homescore < $game->awayscore) {
        if (isset($result['records']['playoff'][$game->away]['wins'])) {
          $result['records']['playoff'][$game->away]['wins'] += 1;
        } else {
          $result['records']['playoff'][$game->away]['wins'] = 1;
        }
        if (isset($result['records']['playoff'][$game->home]['losses'])) {
          $result['records']['playoff'][$game->home]['losses'] += 1;
        } else {
          $result['records']['playoff'][$game->home]['losses'] = 1;
        }
        if (isset($result['records']['playoff']['awaywins'])) {
          $result['records']['playoff']['awaywins'] += 1;
        } else {
          $result['records']['playoff']['awaywins'] = 1;
        }
        $result['records']['playoff'][$game->season][$game->week]['winner'] = $game->away;
        $result['records']['playoff'][$game->season][$game->week]['loser'] = $game->home;
      }
    }
  }
  return $result;
}

/**
 * Take a result array and return a string of HTML that looks pretty.
 */
function format_results($result_array) {
  $team_data[$result_array['team1id']] = $result_array['team1name'];
  $team_data[$result_array['team2id']] = $result_array['team2name'];

  // Print matchup team names.
  $pretty_html = '<h4>' . $result_array['team1name'] . ' vs. ' . $result_array['team2name'] . '</h4>';

  /*
   * Print overall head-to-head record and related stats.
   */
  $pretty_html .= '<h5>All Time Statistics</h5>';

  // Overall record (using the first team).
  $record = $result_array['totals'][$result_array['team1id']]['wins'] . ' - ' . $result_array['totals'][$result_array['team1id']]['losses'];
  if (isset($result_array['totals'][$result_array['team1id']]['ties'])) {
    $record .= ' - ' . $result_array['totals'][$result_array['team1id']]['ties'];
  }

  // Getting the home record.
  $home_record = $result_array['totals']['homewins'] . ' - ' . $result_array['totals']['awaywins'];
  // Make sure we're not missing any ties.
  $game_total = $result_array['totals']['homewins'] + $result_array['totals']['awaywins'];
  if (isset($result_array['totals'][$result_array['team1id']]['ties'])) {
    $home_record .= ' - ' . $result_array['totals'][$result_array['team1id']]['ties'];
  }

  // Create narrative about home field advantage based on results.
  if ($result_array['totals']['homewins'] > $result_array['totals']['awaywins']) {
    $home_advantage = 'home field advantage actually matters when these two teams meet';
  }
  elseif ($result_array['totals']['homewins'] < $result_array['totals']['awaywins']) {
    $home_advantage = 'home field advantage seems to be a disadvantage when these two teams meet';
  }
  else {
    $home_advantage = 'home field advantage has no bearing on the results when these two teams meet';
  }
  $pretty_html .= '<ul>';
  $pretty_html .= '<li>' . $result_array['team1name'] . ' is ' . $record . ' against ' . $result_array['team2name'] . ' overall.</li>';
  $pretty_html .= '<li> In this matchup, the home team is ' . $home_record . ', proving that ' . $home_advantage . '.</li>';

  /*
   * Print notable games.
   */

  // Closest game.
  $pretty_html .= '<li>The closest game was in Week ' . $result_array['records']['nailbiter']['week'] . ' of the ' . $result_array['records']['nailbiter']['season'] . ' season, when ' . $team_data[$result_array['records']['nailbiter']['winner']] . ' squeaked by ' . $team_data[$result_array['records']['nailbiter']['loser']] . ' by a minuscule ' . $result_array['records']['nailbiter']['score'] . ' points.</li>';

  // Biggest blowout.
  $pretty_html .= '<li>The biggest blowout occurred in Week ' . $result_array['records']['blowout']['week'] . ' of the ' . $result_array['records']['blowout']['season'] . ' season, when ' . $team_data[$result_array['records']['blowout']['winner']] . ' blew the doors off ' . $team_data[$result_array['records']['blowout']['loser']] . ' by a whopping ' . $result_array['records']['blowout']['score'] . ' points.</li>';

  $pretty_html .= '</ul>';
  /*
   * Print results table.
   */
  $pretty_html .= '<table><thead><tr><th>Season</th><th>Week</th><th>Home</th><th>Score</th><th>Away</th></tr></thead>';
  $pretty_html .= '<tbody>';
  foreach ($result_array['games'] as $game) {
    $score = $game['homescore'] . ' - ' . $game['awayscore'];
    $pretty_html .= '<tr>';
    $pretty_html .= '<td>' . $game['season'] . '</td><td>' . $game['week'] . '</td>';
    $pretty_html .= '<td>' . $team_data[$game['home']] . '</td><td>' . $score . '</td><td>' . $team_data[$game['away']] . '</td>';
    $pretty_html .= '</tr>';
  }
  $pretty_html .= '</tbody></table>';


  return $pretty_html;
}