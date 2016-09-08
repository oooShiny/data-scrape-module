<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
$title = $user->name . "'s Leagues";
?>
<h1><?php print $title; ?></h1>
<div class="row">
  <div class="col s12">
    <a href="/node/add/league" class="btn">+ Add League</a>
  </div>
</div>
  <?php foreach ($rows as $row_count => $row): ?>
    <?php if (in_array($row_count, array(0,2,4,6))): ?>
      <div class="row">
    <?php endif; ?>

      <?php foreach ($row as $field => $content): ?>
        <?php
          $pieces = explode(" ", $content);
          array_splice($pieces, 1, 0, 'class="blue-text"');
          $content = implode(" ", $pieces);

          $link_pieces = explode('"', $pieces[2]);
          $link_path = drupal_lookup_path('source', ltrim($link_pieces[1], '/'));
        ?>
        <div class="card col l4 m6 s12">
          <div class="card-content">
            <span class="card-title">
              <?php print $content; ?></span>
          </div>
          <div class="card-action">
            <a href="<?php print $link_path; ?>/delete">Remove League</a>
          </div>
        </div>
      <?php endforeach; ?>
      <?php if (in_array($row_count, array(2,4,6))): ?>
        </div>
      <?php endif; ?>

  <?php endforeach; ?>
