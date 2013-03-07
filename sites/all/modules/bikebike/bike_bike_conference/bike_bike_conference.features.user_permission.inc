<?php
/**
 * @file
 * bike_bike_conference.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bike_bike_conference_user_default_permissions() {
  $permissions = array();

  // Exported permission: create conference content.
  $permissions['create conference content'] = array(
    'name' => 'create conference content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any conference content.
  $permissions['delete any conference content'] = array(
    'name' => 'delete any conference content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own conference content.
  $permissions['delete own conference content'] = array(
    'name' => 'delete own conference content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any conference content.
  $permissions['edit any conference content'] = array(
    'name' => 'edit any conference content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own conference content.
  $permissions['edit own conference content'] = array(
    'name' => 'edit own conference content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: publish any conference content.
  $permissions['publish any conference content'] = array(
    'name' => 'publish any conference content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish editable conference content.
  $permissions['publish editable conference content'] = array(
    'name' => 'publish editable conference content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: publish own conference content.
  $permissions['publish own conference content'] = array(
    'name' => 'publish own conference content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish any conference content.
  $permissions['unpublish any conference content'] = array(
    'name' => 'unpublish any conference content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish editable conference content.
  $permissions['unpublish editable conference content'] = array(
    'name' => 'unpublish editable conference content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish own conference content.
  $permissions['unpublish own conference content'] = array(
    'name' => 'unpublish own conference content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'publishcontent',
  );

  return $permissions;
}
