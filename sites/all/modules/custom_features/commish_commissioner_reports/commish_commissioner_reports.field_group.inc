<?php
/**
 * @file
 * commish_commissioner_reports.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function commish_commissioner_reports_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cr_content|node|commissioner_report|form';
  $field_group->group_name = 'group_cr_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'commissioner_report';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commish Report Content',
    'weight' => '2',
    'children' => array(
      0 => 'field_report_content',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Commish Report Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-cr-content field-group-fieldset',
        'description' => 'Here\'s where you add your content. Add a <strong>text block</strong> to display your hysterical anecdotes and razor sharp wit, an <strong>image</strong> (because they\'re worth 1,000 words), or drop in a block of <strong>league data</strong> to prove your points with science.',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_cr_content|node|commissioner_report|form'] = $field_group;

  return $export;
}
