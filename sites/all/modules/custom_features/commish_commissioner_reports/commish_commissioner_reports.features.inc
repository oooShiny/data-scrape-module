<?php
/**
 * @file
 * commish_commissioner_reports.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commish_commissioner_reports_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commish_commissioner_reports_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function commish_commissioner_reports_node_info() {
  $items = array(
    'commissioner_report' => array(
      'name' => t('Commissioner Report'),
      'base' => 'node_content',
      'description' => t('A Commissioner Report is your way of providing updates to your league members.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function commish_commissioner_reports_paragraphs_info() {
  $items = array(
    'cr_image' => array(
      'name' => 'Image',
      'bundle' => 'cr_image',
      'locked' => '1',
    ),
    'current_league_standings' => array(
      'name' => 'Current League Standings',
      'bundle' => 'current_league_standings',
      'locked' => '1',
    ),
    'header_text' => array(
      'name' => 'Header Text',
      'bundle' => 'header_text',
      'locked' => '1',
    ),
    'historical_league_standings' => array(
      'name' => 'Historical League Standings',
      'bundle' => 'historical_league_standings',
      'locked' => '1',
    ),
    'league_standings' => array(
      'name' => 'League Data Block',
      'bundle' => 'league_standings',
      'locked' => '1',
    ),
    'power_rankings' => array(
      'name' => 'Power Rankings',
      'bundle' => 'power_rankings',
      'locked' => '1',
    ),
    'text' => array(
      'name' => 'Paragraph Text',
      'bundle' => 'text',
      'locked' => '1',
    ),
  );
  return $items;
}
