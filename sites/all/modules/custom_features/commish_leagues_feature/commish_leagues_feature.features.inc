<?php
/**
 * @file
 * commish_leagues_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commish_leagues_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function commish_leagues_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function commish_leagues_feature_node_info() {
  $items = array(
    'game' => array(
      'name' => t('Game'),
      'base' => 'node_content',
      'description' => t('An internal content type to store game data from scraped league schedules.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'league' => array(
      'name' => t('League'),
      'base' => 'node_content',
      'description' => t('A League is a collection of Team nodes via an Organic Group.'),
      'has_title' => '1',
      'title_label' => t('League Name'),
      'help' => t('The name of your league for use on this website. It doesn\'t have to match the actual name of your league.'),
    ),
    'team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => t('A Team is part of a League Organic Group, and houses information scraped from the ESPN fantasy football website. '),
      'has_title' => '1',
      'title_label' => t('Team Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
