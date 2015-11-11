<?php

/**
 * @file
 * This file contains the main theme functions hooks and overrides.
 */


/**
 * Override or insert variables into the html template.
 */
function materialize_preprocess_html(&$vars) {
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

function materialize_preprocess_field(&$vars) {
  // Add a class to the Paragraphs image field to make it responsive.
  if ($vars['element']['#field_name'] == 'field_cr_image_block') {
  }

  // Add <h2> tag to Header Text paragraph types.
  if ($vars['element']['#field_name'] == 'field_header_text') {
    $vars['element']['#items'][0]['#prefix'] = '<h2>';
    $vars['element']['#items'][0]['#suffix'] = '</h2>';
  }
}

function materialize_node_view($node, $view_mode, $langcode) {
  $node->content['field_header_text'][0]['#prefix'] = '<h2>';
  $node->content['field_header_text'][0]['#suffix'] = '</h2>';
}