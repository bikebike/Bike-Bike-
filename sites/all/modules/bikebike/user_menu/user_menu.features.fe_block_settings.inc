<?php
/**
 * @file
 * user_menu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function user_menu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['fboauth-login'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'login',
    'module' => 'fboauth',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'leaderboard',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '-14',
      ),
      'rubik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'rubik',
        'weight' => '0',
      ),
      'tao' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tao',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['logintoboggan-logintoboggan_logged_in'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'logintoboggan_logged_in',
    'module' => 'logintoboggan',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bike_bike',
        'weight' => '0',
      ),
      'rubik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'rubik',
        'weight' => '0',
      ),
      'tao' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tao',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['menu-menu-log-out'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-log-out',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'authenticated user' => '2',
    ),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'leaderboard',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '-10',
      ),
      'rubik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'rubik',
        'weight' => '0',
      ),
      'tao' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tao',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  $export['menu-menu-login-menu'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'menu-login-menu',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '<front>
user
user/register
user/password',
    'roles' => array(
      'anonymous user' => '1',
    ),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'leaderboard',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '-11',
      ),
      'rubik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'rubik',
        'weight' => '0',
      ),
      'tao' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'tao',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  return $export;
}
