<?php
/**
 * @file
 * commish_leagues_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function commish_leagues_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'high_scorers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'High Scorers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'High Scorers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_team_points_for' => 'field_team_points_for',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_points_for' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Groups audience */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = 'League';
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_group_ref']['delta_offset'] = '0';
  /* Field: Content: Points For */
  $handler->display->display_options['fields']['field_team_points_for']['id'] = 'field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['table'] = 'field_data_field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['field'] = 'field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Points For (field_team_points_for) */
  $handler->display->display_options['sorts']['field_team_points_for_value']['id'] = 'field_team_points_for_value';
  $handler->display->display_options['sorts']['field_team_points_for_value']['table'] = 'field_data_field_team_points_for';
  $handler->display->display_options['sorts']['field_team_points_for_value']['field'] = 'field_team_points_for_value';
  $handler->display->display_options['sorts']['field_team_points_for_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'high-scorers';
  $export['high_scorers'] = $view;

  $view = new view();
  $view->name = 'historical_standings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Historical Standings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Overall Historical Standings';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_team_owner' => 'field_team_owner',
    'field_historical_wins' => 'field_historical_wins',
    'field_historical_losses' => 'field_historical_losses',
    'field_historical_ties' => 'field_historical_ties',
    'field_historical_points_for' => 'field_historical_points_for',
    'field_historical_points_against' => 'field_historical_points_against',
    'expression' => 'expression',
  );
  $handler->display->display_options['style_options']['default'] = 'field_historical_wins';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_owner' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_historical_wins' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_historical_losses' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_historical_ties' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_historical_points_for' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_historical_points_against' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Header Text';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Overall Standings</h3>
<p>These are the overall historical standings for your league.</p>';
  /* Relationship: Field collection item: Entity with the Historical Stats (field_historical_stats) */
  $handler->display->display_options['relationships']['field_historical_stats_node']['id'] = 'field_historical_stats_node';
  $handler->display->display_options['relationships']['field_historical_stats_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_historical_stats_node']['field'] = 'field_historical_stats_node';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['relationship'] = 'field_historical_stats_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_historical_stats_node';
  /* Field: Content: Owner */
  $handler->display->display_options['fields']['field_team_owner']['id'] = 'field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['table'] = 'field_data_field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['field'] = 'field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['relationship'] = 'field_historical_stats_node';
  /* Field: SUM(Field collection item: Wins) */
  $handler->display->display_options['fields']['field_historical_wins']['id'] = 'field_historical_wins';
  $handler->display->display_options['fields']['field_historical_wins']['table'] = 'field_data_field_historical_wins';
  $handler->display->display_options['fields']['field_historical_wins']['field'] = 'field_historical_wins';
  $handler->display->display_options['fields']['field_historical_wins']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_historical_wins']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: SUM(Field collection item: Losses) */
  $handler->display->display_options['fields']['field_historical_losses']['id'] = 'field_historical_losses';
  $handler->display->display_options['fields']['field_historical_losses']['table'] = 'field_data_field_historical_losses';
  $handler->display->display_options['fields']['field_historical_losses']['field'] = 'field_historical_losses';
  $handler->display->display_options['fields']['field_historical_losses']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_historical_losses']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: SUM(Field collection item: Ties) */
  $handler->display->display_options['fields']['field_historical_ties']['id'] = 'field_historical_ties';
  $handler->display->display_options['fields']['field_historical_ties']['table'] = 'field_data_field_historical_ties';
  $handler->display->display_options['fields']['field_historical_ties']['field'] = 'field_historical_ties';
  $handler->display->display_options['fields']['field_historical_ties']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_historical_ties']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: SUM(Field collection item: Points For) */
  $handler->display->display_options['fields']['field_historical_points_for']['id'] = 'field_historical_points_for';
  $handler->display->display_options['fields']['field_historical_points_for']['table'] = 'field_data_field_historical_points_for';
  $handler->display->display_options['fields']['field_historical_points_for']['field'] = 'field_historical_points_for';
  $handler->display->display_options['fields']['field_historical_points_for']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_historical_points_for']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: SUM(Field collection item: Points Against) */
  $handler->display->display_options['fields']['field_historical_points_against']['id'] = 'field_historical_points_against';
  $handler->display->display_options['fields']['field_historical_points_against']['table'] = 'field_data_field_historical_points_against';
  $handler->display->display_options['fields']['field_historical_points_against']['field'] = 'field_historical_points_against';
  $handler->display->display_options['fields']['field_historical_points_against']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_historical_points_against']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Math expression */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['label'] = 'Win Pct';
  $handler->display->display_options['fields']['expression']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['expression']['precision'] = '3';
  $handler->display->display_options['fields']['expression']['expression'] = '[field_historical_wins]/([field_historical_wins] + [field_historical_losses] + [field_historical_ties])';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'field_historical_stats_node';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['historical_standings'] = $view;

  $view = new view();
  $view->name = 'league_power_rankings';
  $view->description = 'Show all content (nodes) of a group.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'League Power Rankings';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Power Rankings';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_team_id' => 'field_team_id',
    'title' => 'title',
    'field_team_owner' => 'field_team_owner',
    'field_team_wins' => 'field_team_wins',
    'field_team_losses' => 'field_team_losses',
    'field_team_ties' => 'field_team_ties',
    'body' => 'body',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_team_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_owner' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_wins' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_losses' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_ties' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Header Text';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Power Rankings</h3>
';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There is no content in this group.';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Team ID */
  $handler->display->display_options['fields']['field_team_id']['id'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['table'] = 'field_data_field_team_id';
  $handler->display->display_options['fields']['field_team_id']['field'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  /* Field: Content: Owner */
  $handler->display->display_options['fields']['field_team_owner']['id'] = 'field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['table'] = 'field_data_field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['field'] = 'field_team_owner';
  /* Field: Content: Wins */
  $handler->display->display_options['fields']['field_team_wins']['id'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['table'] = 'field_data_field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['field'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_wins']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Losses */
  $handler->display->display_options['fields']['field_team_losses']['id'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['table'] = 'field_data_field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['field'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_losses']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Ties */
  $handler->display->display_options['fields']['field_team_ties']['id'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['table'] = 'field_data_field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['field'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_ties']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Record';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_team_wins] - [field_team_losses] - [field_team_ties]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Ranking */
  $handler->display->display_options['fields']['field_team_ranking']['id'] = 'field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['table'] = 'field_data_field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['field'] = 'field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['label'] = 'LW';
  $handler->display->display_options['fields']['field_team_ranking']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_ranking']['type'] = 'editable';
  $handler->display->display_options['fields']['field_team_ranking']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'number_integer',
    'fallback_settings' => array(
      'thousand_separator' => '',
      'prefix_suffix' => 0,
    ),
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Notes';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'editable';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );

  /* Display: View */
  $handler = $view->new_display('block', 'View', 'view_block');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Team ID */
  $handler->display->display_options['fields']['field_team_id']['id'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['table'] = 'field_data_field_team_id';
  $handler->display->display_options['fields']['field_team_id']['field'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Owner */
  $handler->display->display_options['fields']['field_team_owner']['id'] = 'field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['table'] = 'field_data_field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['field'] = 'field_team_owner';
  /* Field: Content: Wins */
  $handler->display->display_options['fields']['field_team_wins']['id'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['table'] = 'field_data_field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['field'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_wins']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Losses */
  $handler->display->display_options['fields']['field_team_losses']['id'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['table'] = 'field_data_field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['field'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_losses']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Ties */
  $handler->display->display_options['fields']['field_team_ties']['id'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['table'] = 'field_data_field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['field'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_ties']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Record';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_team_wins] - [field_team_losses] - [field_team_ties]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Ranking */
  $handler->display->display_options['fields']['field_team_ranking']['id'] = 'field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['table'] = 'field_data_field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['field'] = 'field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['label'] = 'LW';
  $handler->display->display_options['fields']['field_team_ranking']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_ranking']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Notes';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Power Rankings';

  /* Display: Sort */
  $handler = $view->new_display('block', 'Sort', 'sort_block');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Header Text';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Power Rankings</h3>
<p>
<strong><em>Instructions:</em></strong> This is where you can create a power rankings table to use in your Commissioner Reports. Drag and drop the teams into the order you want and <strong>click the Save button at the bottom of the page</strong>. 
</p>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Team ID */
  $handler->display->display_options['fields']['field_team_id']['id'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['table'] = 'field_data_field_team_id';
  $handler->display->display_options['fields']['field_team_id']['field'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  /* Field: Content: Owner */
  $handler->display->display_options['fields']['field_team_owner']['id'] = 'field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['table'] = 'field_data_field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['field'] = 'field_team_owner';
  /* Field: Content: Wins */
  $handler->display->display_options['fields']['field_team_wins']['id'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['table'] = 'field_data_field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['field'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_wins']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Losses */
  $handler->display->display_options['fields']['field_team_losses']['id'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['table'] = 'field_data_field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['field'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_losses']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Ties */
  $handler->display->display_options['fields']['field_team_ties']['id'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['table'] = 'field_data_field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['field'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_ties']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Record';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_team_wins] - [field_team_losses] - [field_team_ties]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Ranking */
  $handler->display->display_options['fields']['field_team_ranking']['id'] = 'field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['table'] = 'field_data_field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['field'] = 'field_team_ranking';
  $handler->display->display_options['fields']['field_team_ranking']['label'] = 'LW';
  $handler->display->display_options['fields']['field_team_ranking']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_ranking']['type'] = 'editable';
  $handler->display->display_options['fields']['field_team_ranking']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'number_integer',
    'fallback_settings' => array(
      'thousand_separator' => '',
      'prefix_suffix' => 0,
    ),
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Notes';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'editable';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['block_description'] = 'OG Team Standings';
  $export['league_power_rankings'] = $view;

  $view = new view();
  $view->name = 'league_standings_table';
  $view->description = 'Show all content (nodes) of a group.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'League Standings Table';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'League Standings';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_team_id' => 'field_team_id',
    'title' => 'title',
    'field_team_owner' => 'field_team_owner',
    'field_team_points_for' => 'field_team_points_for',
    'field_team_points_against' => 'field_team_points_against',
    'field_team_wins' => 'field_team_wins',
    'field_team_losses' => 'field_team_losses',
    'field_team_ties' => 'field_team_ties',
    'field_team_win_percentage' => 'field_team_win_percentage',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_team_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_owner' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_points_for' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_points_against' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_wins' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_losses' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_ties' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_win_percentage' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Header Text';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Current Standings</h3>
<p>These are the latest standings for the current season of your league.</p>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There is no content in this group.';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Team ID */
  $handler->display->display_options['fields']['field_team_id']['id'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['table'] = 'field_data_field_team_id';
  $handler->display->display_options['fields']['field_team_id']['field'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  /* Field: Content: Owner */
  $handler->display->display_options['fields']['field_team_owner']['id'] = 'field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['table'] = 'field_data_field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['field'] = 'field_team_owner';
  /* Field: Content: Points For */
  $handler->display->display_options['fields']['field_team_points_for']['id'] = 'field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['table'] = 'field_data_field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['field'] = 'field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Points Against */
  $handler->display->display_options['fields']['field_team_points_against']['id'] = 'field_team_points_against';
  $handler->display->display_options['fields']['field_team_points_against']['table'] = 'field_data_field_team_points_against';
  $handler->display->display_options['fields']['field_team_points_against']['field'] = 'field_team_points_against';
  $handler->display->display_options['fields']['field_team_points_against']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Wins */
  $handler->display->display_options['fields']['field_team_wins']['id'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['table'] = 'field_data_field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['field'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Losses */
  $handler->display->display_options['fields']['field_team_losses']['id'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['table'] = 'field_data_field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['field'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Ties */
  $handler->display->display_options['fields']['field_team_ties']['id'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['table'] = 'field_data_field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['field'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_team_win_percentage']['id'] = 'field_team_win_percentage';
  $handler->display->display_options['fields']['field_team_win_percentage']['table'] = 'field_data_field_team_win_percentage';
  $handler->display->display_options['fields']['field_team_win_percentage']['field'] = 'field_team_win_percentage';
  $handler->display->display_options['fields']['field_team_win_percentage']['label'] = 'Win %';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Wins (field_team_wins) */
  $handler->display->display_options['sorts']['field_team_wins_value']['id'] = 'field_team_wins_value';
  $handler->display->display_options['sorts']['field_team_wins_value']['table'] = 'field_data_field_team_wins';
  $handler->display->display_options['sorts']['field_team_wins_value']['field'] = 'field_team_wins_value';
  $handler->display->display_options['sorts']['field_team_wins_value']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['block_description'] = 'OG Team Standings';
  $export['league_standings_table'] = $view;

  $view = new view();
  $view->name = 'leagues_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Leagues List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Leagues List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'league' => 'league',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'leagues-list';
  $export['leagues_list'] = $view;

  $view = new view();
  $view->name = 'og_team_table';
  $view->description = 'Show all content (nodes) of a group.';
  $view->tag = 'og';
  $view->base_table = 'node';
  $view->human_name = 'OG Team Table';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'League Standings';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_team_id' => 'field_team_id',
    'title' => 'title',
    'field_team_owner' => 'field_team_owner',
    'field_team_wins' => 'field_team_wins',
    'field_team_losses' => 'field_team_losses',
    'field_team_ties' => 'field_team_ties',
    'field_team_points_for' => 'field_team_points_for',
    'field_team_points_against' => 'field_team_points_against',
  );
  $handler->display->display_options['style_options']['default'] = 'field_team_wins';
  $handler->display->display_options['style_options']['info'] = array(
    'field_team_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_owner' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_wins' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_losses' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_ties' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_points_for' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_team_points_against' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Header Text';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Current Standings</h3>
<p>These are the latest standings for the current season of your league.</p>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'There is no content in this group.';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: Content: Team ID */
  $handler->display->display_options['fields']['field_team_id']['id'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['table'] = 'field_data_field_team_id';
  $handler->display->display_options['fields']['field_team_id']['field'] = 'field_team_id';
  $handler->display->display_options['fields']['field_team_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Team';
  /* Field: Content: Owner */
  $handler->display->display_options['fields']['field_team_owner']['id'] = 'field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['table'] = 'field_data_field_team_owner';
  $handler->display->display_options['fields']['field_team_owner']['field'] = 'field_team_owner';
  /* Field: Content: Wins */
  $handler->display->display_options['fields']['field_team_wins']['id'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['table'] = 'field_data_field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['field'] = 'field_team_wins';
  $handler->display->display_options['fields']['field_team_wins']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Losses */
  $handler->display->display_options['fields']['field_team_losses']['id'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['table'] = 'field_data_field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['field'] = 'field_team_losses';
  $handler->display->display_options['fields']['field_team_losses']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Ties */
  $handler->display->display_options['fields']['field_team_ties']['id'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['table'] = 'field_data_field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['field'] = 'field_team_ties';
  $handler->display->display_options['fields']['field_team_ties']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Points For */
  $handler->display->display_options['fields']['field_team_points_for']['id'] = 'field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['table'] = 'field_data_field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['field'] = 'field_team_points_for';
  $handler->display->display_options['fields']['field_team_points_for']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Points Against */
  $handler->display->display_options['fields']['field_team_points_against']['id'] = 'field_team_points_against';
  $handler->display->display_options['fields']['field_team_points_against']['table'] = 'field_data_field_team_points_against';
  $handler->display->display_options['fields']['field_team_points_against']['field'] = 'field_team_points_against';
  $handler->display->display_options['fields']['field_team_points_against']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Wins (field_team_wins) */
  $handler->display->display_options['sorts']['field_team_wins_value']['id'] = 'field_team_wins_value';
  $handler->display->display_options['sorts']['field_team_wins_value']['table'] = 'field_data_field_team_wins';
  $handler->display->display_options['sorts']['field_team_wins_value']['field'] = 'field_team_wins_value';
  $handler->display->display_options['sorts']['field_team_wins_value']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Group_type */
  $handler->display->display_options['filters']['group_type']['id'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['group_type']['field'] = 'group_type';
  $handler->display->display_options['filters']['group_type']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['group_type']['value'] = array(
    'node' => 'node',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'team' => 'team',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['block_description'] = 'OG Team Standings';
  $export['og_team_table'] = $view;

  return $export;
}
