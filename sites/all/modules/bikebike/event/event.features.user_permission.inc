<?php
/**
 * @file
 * event.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function event_user_default_permissions() {
  $permissions = array();

  // Exported permission: create event content.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any event content.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete own event content.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any event content.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit own event content.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: publish any event content.
  $permissions['publish any event content'] = array(
    'name' => 'publish any event content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: publish editable event content.
  $permissions['publish editable event content'] = array(
    'name' => 'publish editable event content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: publish own event content.
  $permissions['publish own event content'] = array(
    'name' => 'publish own event content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish any event content.
  $permissions['unpublish any event content'] = array(
    'name' => 'unpublish any event content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish editable event content.
  $permissions['unpublish editable event content'] = array(
    'name' => 'unpublish editable event content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  // Exported permission: unpublish own event content.
  $permissions['unpublish own event content'] = array(
    'name' => 'unpublish own event content',
    'roles' => array(),
    'module' => 'publishcontent',
  );

  return $permissions;
}
