<?php
/**
 * @file
 * conference_registration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function conference_registration_user_default_permissions() {
  $permissions = array();

  // Exported permission: create conference_registration content.
  $permissions['create conference_registration content'] = array(
    'name' => 'create conference_registration content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any conference_registration content.
  $permissions['delete any conference_registration content'] = array(
    'name' => 'delete any conference_registration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own conference_registration content.
  $permissions['delete own conference_registration content'] = array(
    'name' => 'delete own conference_registration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any conference_registration content.
  $permissions['edit any conference_registration content'] = array(
    'name' => 'edit any conference_registration content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own conference_registration content.
  $permissions['edit own conference_registration content'] = array(
    'name' => 'edit own conference_registration content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
