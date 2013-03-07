<?php
/**
 * @file
 * workshop.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function workshop_user_default_permissions() {
  $permissions = array();

  // Exported permission: create workshop content.
  $permissions['create workshop content'] = array(
    'name' => 'create workshop content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any workshop content.
  $permissions['delete any workshop content'] = array(
    'name' => 'delete any workshop content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own workshop content.
  $permissions['delete own workshop content'] = array(
    'name' => 'delete own workshop content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete terms in 6.
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7.
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any workshop content.
  $permissions['edit any workshop content'] = array(
    'name' => 'edit any workshop content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own workshop content.
  $permissions['edit own workshop content'] = array(
    'name' => 'edit own workshop content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit terms in 6.
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7.
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
