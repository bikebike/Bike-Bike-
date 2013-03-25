<?php
/**
 * @file
 * user_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function user_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'leaderboard',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '-27',
      ),
      'rubik' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'rubik',
        'weight' => '0',
      ),
      'tao' => array(
        'region' => 'sidebar_first',
        'status' => '1',
        'theme' => 'tao',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  return $export;
}
