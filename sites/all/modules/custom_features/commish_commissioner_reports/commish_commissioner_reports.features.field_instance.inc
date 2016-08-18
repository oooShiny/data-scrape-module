<?php
/**
 * @file
 * commish_commissioner_reports.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function commish_commissioner_reports_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-commissioner_report-field_report_content'
  $field_instances['node-commissioner_report-field_report_content'] = array(
    'bundle' => 'commissioner_report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 2,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'token',
        ),
        'type' => 'paragraphs_view',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_report_content',
    'label' => 'Report Content',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'cr_image' => 'cr_image',
        'current_league_standings' => 'current_league_standings',
        'header_text' => 'header_text',
        'historical_league_standings' => 'historical_league_standings',
        'league_standings' => -1,
        'power_rankings' => 'power_rankings',
        'text' => 'text',
      ),
      'bundle_weights' => array(
        'cr_image' => -10,
        'current_league_standings' => 10,
        'header_text' => 8,
        'historical_league_standings' => -10,
        'league_standings' => 6,
        'power_rankings' => -10,
        'text' => 3,
      ),
      'default_edit_mode' => 'open',
      'title' => 'Content Block',
      'title_multiple' => 'Content Blocks',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-commissioner_report-og_group_ref'
  $field_instances['node-commissioner_report-og_group_ref'] = array(
    'bundle' => 'commissioner_report',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select which league for which you\'re writing this Commish Report. This will let us pull the right information in if you have multiple leagues.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Groups audience',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_buttons',
          ),
          'status' => TRUE,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Full',
        'type' => 'og_list_default',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Teaser',
        'type' => 'og_list_default',
      ),
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-cr_image-field_cr_image_upload'
  $field_instances['paragraphs_item-cr_image-field_cr_image_upload'] = array(
    'bundle' => 'cr_image',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cr_image_upload',
    'label' => 'Image Upload',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'report_images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
        ),
        'allowed_types' => array(
          'image' => 'image',
        ),
        'browser_plugins' => array(),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-current_league_standings-field_current_league_standings'
  $field_instances['paragraphs_item-current_league_standings-field_current_league_standings'] = array(
    'bundle' => 'current_league_standings',
    'default_value' => array(
      0 => array(
        'vname' => 'league_standings_table|block_1',
        'vargs' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Display the current league standings as they are right now.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_current_league_standings',
    'label' => 'Current League Standings',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'commissioner_report_list' => 0,
        'embed_code' => 0,
        'high_scorers' => 0,
        'historical_standings' => 0,
        'league_power_rankings' => 0,
        'league_standings_table' => 'league_standings_table',
        'leagues_list' => 0,
        'og_all_user_group_content' => 0,
        'og_members' => 0,
        'og_members_admin' => 0,
        'og_nodes' => 0,
        'og_team_table' => 0,
        'og_user_groups' => 0,
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-header_text-field_header_text'
  $field_instances['paragraphs_item-header_text-field_header_text'] = array(
    'bundle' => 'header_text',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_header_text',
    'label' => 'Header Text',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-historical_league_standings-field_overall_league_standings'
  $field_instances['paragraphs_item-historical_league_standings-field_overall_league_standings'] = array(
    'bundle' => 'historical_league_standings',
    'default_value' => array(
      0 => array(
        'vname' => 'historical_standings|block',
        'vargs' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_overall_league_standings',
    'label' => 'Overall League Standings',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'commissioner_report_list' => 0,
        'embed_code' => 0,
        'high_scorers' => 0,
        'historical_standings' => 'historical_standings',
        'league_power_rankings' => 0,
        'league_standings_table' => 0,
        'leagues_list' => 0,
        'og_all_user_group_content' => 0,
        'og_members' => 0,
        'og_members_admin' => 0,
        'og_nodes' => 0,
        'og_team_table' => 0,
        'og_user_groups' => 0,
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-league_standings-field_cr_standings_block'
  $field_instances['paragraphs_item-league_standings-field_cr_standings_block'] = array(
    'bundle' => 'league_standings',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cr_standings_block',
    'label' => 'Commish Tools Data',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'commissioner_report_list' => 'commissioner_report_list',
        'high_scorers' => 0,
        'historical_standings' => 'historical_standings',
        'league_power_rankings' => 'league_power_rankings',
        'league_standings_table' => 'league_standings_table',
        'leagues_list' => 0,
        'og_all_user_group_content' => 0,
        'og_members' => 0,
        'og_members_admin' => 0,
        'og_nodes' => 0,
        'og_team_table' => 0,
        'og_user_groups' => 0,
      ),
      'force_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-power_rankings-field_power_rankings'
  $field_instances['paragraphs_item-power_rankings-field_power_rankings'] = array(
    'bundle' => 'power_rankings',
    'default_value' => array(
      0 => array(
        'vname' => 'league_power_rankings|view_block',
        'vargs' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'This will display your power rankings that you created from the league Power Rankings tab. Order and edit it there, and the changes will show up here.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'viewfield',
        'settings' => array(),
        'type' => 'viewfield_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_power_rankings',
    'label' => 'Power Rankings',
    'required' => 0,
    'settings' => array(
      'allowed_views' => array(
        'commissioner_report_list' => 0,
        'embed_code' => 0,
        'high_scorers' => 0,
        'historical_standings' => 0,
        'league_power_rankings' => 'league_power_rankings',
        'league_standings_table' => 0,
        'leagues_list' => 0,
        'og_all_user_group_content' => 0,
        'og_members' => 0,
        'og_members_admin' => 0,
        'og_nodes' => 0,
        'og_team_table' => 0,
        'og_user_groups' => 0,
      ),
      'force_default' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viewfield',
      'settings' => array(),
      'type' => 'viewfield_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-text-field_cr_text_block'
  $field_instances['paragraphs_item-text-field_cr_text_block'] = array(
    'bundle' => 'text',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_cr_text_block',
    'label' => 'Text',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Commish Tools Data');
  t('Current League Standings');
  t('Display the current league standings as they are right now.');
  t('Groups audience');
  t('Header Text');
  t('Image Upload');
  t('Overall League Standings');
  t('Power Rankings');
  t('Report Content');
  t('Select which league for which you\'re writing this Commish Report. This will let us pull the right information in if you have multiple leagues.');
  t('Text');
  t('This will display your power rankings that you created from the league Power Rankings tab. Order and edit it there, and the changes will show up here.');

  return $field_instances;
}
