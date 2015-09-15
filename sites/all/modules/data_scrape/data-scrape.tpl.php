<?php
?>
<div style="clear: both"></div>
<div>
  <h4><?php print $variables['matchup_title']; ?></h4>
  <strong>All Time Statistics</strong>
  <div class="row">
    <div class="col s12 l4">
      <div class="card-panel hoverable">
        <span class="card-title blue-text">Overall Record</span>
        <p><?php print $variables['card']['overall_record']; ?></p>
      </div>
    </div>
    <div class="col s12 l4">
      <div class="card-panel hoverable">
        <span class="card-title blue-text">Home Record</span>
        <p><?php print $variables['card']['home_field']; ?></p>
      </div>
    </div>
    <div class="col s12 l4">
      <div class="card-panel hoverable">
        <span class="card-title blue-text">Playoff Meetings</span>
        <p><?php print $variables['card']['playoff_record']; ?></p>
      </div>
    </div>
  </div>
  <div class="row">
    <div class="col s12 l4">
      <div class="card-panel hoverable">
        <span class="card-title blue-text">Closest Game</span>
        <p><?php print $variables['card']['closest_game']; ?></p>
      </div>
    </div>
    <div class="col s12 l4">
      <div class="card-panel hoverable">
        <span class="card-title blue-text">Biggest Blowout</span>
        <p><?php print $variables['card']['biggest_blowout']; ?></p>
      </div>
    </div>
  </div>
  <table class="striped hoverable">
    <thead>
    <tr>
      <th>Season</th>
      <th>Week</th>
      <th>Home</th>
      <th>Score</th>
      <th>Away</th>
    </tr>
    </thead>
    <tbody>
    <?php print $variables['results']; ?>
    </tbody>
  </table>
</div>