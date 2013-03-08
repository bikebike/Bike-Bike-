<?php
/**
 * @file
 * organization.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function organization_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-organization_list-block_1'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'organization_list-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'organizations',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '-12',
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
    'visibility' => '1',
  );

  return $export;
}
