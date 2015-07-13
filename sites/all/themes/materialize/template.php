<?php

/**
 * @file
 * This file contains the main theme functions hooks and overrides.
 */


/**
 * Override or insert variables into the html template.
 */
function materialize_preprocess_html(&$vars) {
1==1;
  $google_icons = array(
    '#tag' => 'link',
    '#attributes' => array(
      'href' => 'http://fonts.googleapis.com/icon?family=Material+Icons',
      'rel' => 'stylesheet',
      'type' => 'text/css',
    ),
  );
  drupal_add_html_head($google_icons, 'google_icons');
}
