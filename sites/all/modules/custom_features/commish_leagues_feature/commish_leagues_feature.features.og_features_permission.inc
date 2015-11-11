<?php
/**
 * @file
 * commish_leagues_feature.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function commish_leagues_feature_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:league:add user'
  $permissions['node:league:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:administer group'
  $permissions['node:league:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:approve and deny subscription'
  $permissions['node:league:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:create commissioner_report content'
  $permissions['node:league:create commissioner_report content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:create game content'
  $permissions['node:league:create game content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:create team content'
  $permissions['node:league:create team content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:delete any commissioner_report content'
  $permissions['node:league:delete any commissioner_report content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:delete any game content'
  $permissions['node:league:delete any game content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:delete any team content'
  $permissions['node:league:delete any team content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:delete own commissioner_report content'
  $permissions['node:league:delete own commissioner_report content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:delete own game content'
  $permissions['node:league:delete own game content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:delete own team content'
  $permissions['node:league:delete own team content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:manage members'
  $permissions['node:league:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:manage permissions'
  $permissions['node:league:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:manage roles'
  $permissions['node:league:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:subscribe'
  $permissions['node:league:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:league:subscribe without approval'
  $permissions['node:league:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:unsubscribe'
  $permissions['node:league:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:league:update any commissioner_report content'
  $permissions['node:league:update any commissioner_report content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:update any game content'
  $permissions['node:league:update any game content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:update any team content'
  $permissions['node:league:update any team content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:update group'
  $permissions['node:league:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:update own commissioner_report content'
  $permissions['node:league:update own commissioner_report content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:league:update own game content'
  $permissions['node:league:update own game content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:league:update own team content'
  $permissions['node:league:update own team content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
