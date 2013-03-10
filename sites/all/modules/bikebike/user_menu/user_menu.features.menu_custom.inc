<?php
/**
 * @file
 * user_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function user_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-log-out.
  $menus['menu-log-out'] = array(
    'menu_name' => 'menu-log-out',
    'title' => 'Log out',
    'description' => '',
  );
  // Exported menu: menu-login-menu.
  $menus['menu-login-menu'] = array(
    'menu_name' => 'menu-login-menu',
    'title' => 'Login Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Log out');
  t('Login Menu');


  return $menus;
}
