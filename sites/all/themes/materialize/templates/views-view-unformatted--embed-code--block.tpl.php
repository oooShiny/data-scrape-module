<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
drupal_add_library('system', 'drupal.collapse');
?>

<fieldset class="collapsible collapsed">
  <legend>
    <span class="fieldset-legend">Embed Code</span>
  </legend>
  <div class="fieldset-wrapper">

    <?php
      foreach ($rows as $id => $row) {
        // Remove commas from token output between fields.
        $row = str_replace("\n,", '<br>', $row);
        // Removing the divs around Power Rankings table.
        $row = preg_replace('/&lt;div(.*?)&gt;/', '', $row);
        $row = str_replace('&lt;/div&gt;', '', $row);
        // Replacing HTML tags with markdown tags.
        $row = str_replace('<strong>', '[b]', $row);
        $row = str_replace('</strong>', '[/b]', $row);

        $row = str_replace('<em>', '[i]', $row);
        $row = str_replace('</em>', '[/i]', $row);
        // Print the row.
        print $row;
      }
    ?>

  </div>
</fieldset>
