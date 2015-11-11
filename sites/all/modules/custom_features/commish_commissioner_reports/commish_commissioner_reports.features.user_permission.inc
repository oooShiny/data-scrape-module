<?php
/**
 * @file
 * commish_commissioner_reports.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function commish_commissioner_reports_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create commissioner_report content'.
  $permissions['create commissioner_report content'] = array(
    'name' => 'create commissioner_report content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any commissioner_report content'.
  $permissions['delete any commissioner_report content'] = array(
    'name' => 'delete any commissioner_report content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own commissioner_report content'.
  $permissions['delete own commissioner_report content'] = array(
    'name' => 'delete own commissioner_report content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any commissioner_report content'.
  $permissions['edit any commissioner_report content'] = array(
    'name' => 'edit any commissioner_report content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own commissioner_report content'.
  $permissions['edit own commissioner_report content'] = array(
    'name' => 'edit own commissioner_report content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
