<?php
/**
 * @file
 * commish_leagues_feature.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function commish_leagues_feature_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'league_info';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'League Info';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'data_scrape_delta_matchup_builder',
      'hide_title' => 1,
      'title' => 'Matchup Analysis',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'block_delta_4',
      'hide_title' => 1,
      'title' => 'League Leaders',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'vid' => 'og_team_table',
      'display' => 'default',
      'args' => '',
      'title' => 'Current Standings',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'historical_standings',
      'display' => 'default',
      'args' => '',
      'title' => 'Overall Standings',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'league_power_rankings',
      'display' => 'sort_block',
      'args' => '',
      'title' => 'Power Rankings',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'commissioner_report_list',
      'display' => 'default',
      'args' => '',
      'title' => 'Commish Reports',
      'weight' => '-95',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Commish Reports');
  t('Current Standings');
  t('League Info');
  t('League Leaders');
  t('Matchup Analysis');
  t('Overall Standings');
  t('Power Rankings');

  $export['league_info'] = $quicktabs;

  return $export;
}
