<?php
/**
 * @file
 * commish_leagues_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function commish_leagues_feature_user_default_roles() {
  $roles = array();

  // Exported role: Bronze.
  $roles['Bronze'] = array(
    'name' => 'Bronze',
    'weight' => 3,
  );

  // Exported role: Gold.
  $roles['Gold'] = array(
    'name' => 'Gold',
    'weight' => 5,
  );

  // Exported role: Silver.
  $roles['Silver'] = array(
    'name' => 'Silver',
    'weight' => 4,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
