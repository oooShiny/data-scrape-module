<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || !$page): ?>
  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <div class="submitted">
        <?php print $user_picture; ?>
        <span class="glyphicon glyphicon-calendar"></span> <?php print $submitted; ?>
      </div>
    <?php endif; ?>
  </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_tags']);
    ?>
    <div>
      <strong>League: </strong><?php print render($content['og_group_ref'][0]); ?><br />
      <strong>Owner: </strong><?php print render($content['field_team_owner'][0]); ?><br />
      <strong>Current Record: </strong><?php print render($content['field_team_wins'][0]); ?> -
              <?php print render($content['field_team_losses'][0]); ?> -
              <?php print render($content['field_team_ties'][0]); ?><br />
      <strong>Win Percentage: </strong><?php print render($content['field_team_win_percentage'][0]); ?>
    </div>
      <?php
//       print render($content);
      ?>
    <h3>Historical Statistics</h3>
    <table>
      <thead>
      <tr>
        <th>Year</th>
        <th>Team Name</th>
        <th>Owner</th>
        <th>Wins</th>
        <th>Losses</th>
        <th>Ties</th>
        <th>Points For</th>
        <th>Points Against</th>
        <th>Win %</th>
      </tr>
      </thead>
      <tbody>
      <?php
      $total = array();
      $total['wins'] = 0;
      $total['losses'] = 0;
      $total['ties'] = 0;
      $total['pf'] = 0;
      $total['pa'] = 0;

      foreach($content['field_historical_stats']['#items'] as $history) {
        $history_field = entity_load('field_collection_item', $history);

        foreach($history_field as $history_object) {
          $total['wins'] += $history_object->field_historical_wins['und'][0]['value'];
          $total['losses'] += $history_object->field_historical_losses['und'][0]['value'];
          $total['ties'] += $history_object->field_historical_ties['und'][0]['value'];
          $total['pf'] += $history_object->field_historical_points_for['und'][0]['value'];
          $total['pa'] += $history_object->field_historical_points_against['und'][0]['value'];

          print '<tr>';
          print '<td>' . $history_object->field_historical_year['und'][0]['value'] . '</td>';
          print '<td>' . $history_object->field_historical_team_name['und'][0]['value'] . '</td>';
          print '<td>' . $history_object->field_historical_owner['und'][0]['value'] . '</td>';
          print '<td>' . $history_object->field_historical_wins['und'][0]['value'] . '</td>';
          print '<td>' . $history_object->field_historical_losses['und'][0]['value'] . '</td>';
          print '<td>' . $history_object->field_historical_ties['und'][0]['value'] . '</td>';
          print '<td>' . $history_object->field_historical_points_for['und'][0]['value'] . '</td>';
          print '<td>' . $history_object->field_historical_points_against['und'][0]['value'] . '</td>';
//          print '<td>' . $history_object->field_win_percentage['und'][0]['value'] . '</td>';
          print '</tr>';
        }
      }
      print '<tr class="historical_totals">';
      print '<td colspan="3">Totals</td>';
      print '<td>'.$total['wins'].'</td>';
      print '<td>'.$total['losses'].'</td>';
      print '<td>'.$total['ties'].'</td>';
      print '<td>'.$total['pf'].'</td>';
      print '<td>'.$total['pa'].'</td>';
      print '<td></td>'; // win pct
      print '</tr>';

      ?>
      </tbody>
    </table>
  </div>
    
    <?php if (($tags = render($content['field_tags'])) || ($links = render($content['links']))): ?>
    <footer>
    <?php print render($content['field_tags']); ?>
    <?php print render($content['links']); ?>
    </footer>
    <?php endif; ?> 

  <?php print render($content['comments']); ?>

</article>