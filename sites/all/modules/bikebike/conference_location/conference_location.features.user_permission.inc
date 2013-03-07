<?php
/**
 * @file
 * conference_location.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function conference_location_user_default_permissions() {
  $permissions = array();

  // Exported permission: create conference_location content.
  $permissions['create conference_location content'] = array(
    'name' => 'create conference_location content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any conference_location content.
  $permissions['delete any conference_location content'] = array(
    'name' => 'delete any conference_location content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own conference_location content.
  $permissions['delete own conference_location content'] = array(
    'name' => 'delete own conference_location content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any conference_location content.
  $permissions['edit any conference_location content'] = array(
    'name' => 'edit any conference_location content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own conference_location content.
  $permissions['edit own conference_location content'] = array(
    'name' => 'edit own conference_location content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
