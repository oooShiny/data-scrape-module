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

global $user;
$home = ($user->uid == 0 ? '<a href="/">Home</a>' : '<a href="/dashboard">Dashboard</a>');
?>


<!-- Dropdown Structure -->
<ul id="dropdown1" class="dropdown-content">
  <?php foreach ($rows as $row_count => $row): ?>
    <?php foreach ($row as $field => $content): ?>
      <li><?php print $content; ?></li>
    <?php endforeach; ?>
  <?php endforeach; ?>
  <li class="divider"></li>
  <li><a href="/node/add/league">+ Add League</a></li>
</ul>

    <ul class="right hide-on-med-and-down">
      <!-- Dropdown Trigger -->
      <li><?php print $home; ?></li>
      <li><a href="/faq">FAQs</a></li>
      <li><a class="dropdown-button" href="#!" data-activates="dropdown1">My Leagues<i class="material-icons right">arrow_drop_down</i></a></li>
    </ul>