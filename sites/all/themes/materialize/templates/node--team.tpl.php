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
    <div class="row">
      <div class="col s12 m12 l4">
        <strong>League: </strong><?php print render($content['og_group_ref'][0]); ?><br />
        <strong>Owner: </strong><?php print render($content['field_team_owner'][0]); ?><br />
        <strong>Current Record: </strong><?php print render($content['field_team_wins'][0]); ?> -
                <?php print render($content['field_team_losses'][0]); ?> -
                <?php print render($content['field_team_ties'][0]); ?><br />
      </div>
      <div class="col s12 m12 l8">
        <table class="striped">
            <tbody>
              <tr><td><strong>Highest Score </strong></td><td><?php print render($content['field_team_most_points'][0]); ?></td></tr>
              <tr><td><strong>Lowest Score </strong></td><td><?php print render($content['field_team_least_points'][0]); ?></td></tr>
              <tr><td><strong>Biggest Win </strong></td><td>+<?php print render($content['field_team_biggest_win'][0]); ?></td></tr>
              <tr><td><strong>Biggest Loss </strong></td><td>-<?php print render($content['field_team_biggest_loss'][0]); ?></td></tr>
            </tbody>
          </table>
        </div>
    </div>
      <?php
//       print render($content);
      ?>
    <div class="row">
    <h3>Historical Statistics</h3>
    <table class="striped">
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
      </tr>
      </thead>
      <tbody>
      <?php
      $total = array();

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
          print '</tr>';
        }
      }
      print '<tr class="historical_totals">';
      print '<td colspan="3"><strong>Totals</strong></td>';
      print '<td><strong>'.$total['wins'].'</strong></td>';
      print '<td><strong>'.$total['losses'].'</strong></td>';
      print '<td><strong>'.$total['ties'].'</strong></td>';
      print '<td><strong>'.$total['pf'].'</strong></td>';
      print '<td><strong>'.$total['pa'].'</strong></td>';
      print '</tr>';

      ?>
      </tbody>
    </table>
    </div>
  </div>
    
    <?php if (($tags = render($content['field_tags'])) || ($links = render($content['links']))): ?>
    <footer>
    <?php print render($content['field_tags']); ?>
    <?php print render($content['links']); ?>
    </footer>
    <?php endif; ?> 

  <?php print render($content['comments']); ?>

</article>
