<?php
/**
 * @file
 * form_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function form_fields_user_default_permissions() {
  $permissions = array();

  // Exported permission: create form_field content.
  $permissions['create form_field content'] = array(
    'name' => 'create form_field content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any form_field content.
  $permissions['delete any form_field content'] = array(
    'name' => 'delete any form_field content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own form_field content.
  $permissions['delete own form_field content'] = array(
    'name' => 'delete own form_field content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any form_field content.
  $permissions['edit any form_field content'] = array(
    'name' => 'edit any form_field content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own form_field content.
  $permissions['edit own form_field content'] = array(
    'name' => 'edit own form_field content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
