<?php
/**
 * @file
 * all_features.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function all_features_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['calendar-calendar_legend'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'calendar_legend',
    'module' => 'calendar',
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

  $export['comment-recent'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'recent',
    'module' => 'comment',
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
        'region' => 'dashboard_inactive',
        'status' => '1',
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

  $export['context_ui-editor'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'editor',
    'module' => 'context_ui',
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

  $export['form_builder-fields'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'fields',
    'module' => 'form_builder',
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

  $export['menu-features'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'features',
    'module' => 'menu',
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

  $export['node-recent'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'recent',
    'module' => 'node',
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
        'region' => 'dashboard_inactive',
        'status' => '1',
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

  $export['node-syndicate'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'syndicate',
    'module' => 'node',
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

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bike_bike',
        'weight' => '-1',
      ),
      'rubik' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'rubik',
        'weight' => '-1',
      ),
      'tao' => array(
        'region' => 'sidebar_first',
        'status' => '1',
        'theme' => 'tao',
        'weight' => '-1',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['shortcut-shortcuts'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'shortcuts',
    'module' => 'shortcut',
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

  $export['system-help'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'help',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'help',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '0',
      ),
      'rubik' => array(
        'region' => 'help',
        'status' => '1',
        'theme' => 'rubik',
        'weight' => '0',
      ),
      'tao' => array(
        'region' => 'help',
        'status' => '1',
        'theme' => 'tao',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '-10',
      ),
      'rubik' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'rubik',
        'weight' => '0',
      ),
      'tao' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'tao',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'main-menu',
    'module' => 'system',
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

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'management',
    'module' => 'system',
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

  $export['system-navigation'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'navigation',
    'module' => 'system',
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
    'title' => '',
    'visibility' => '0',
  );

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bike_bike',
        'weight' => '-9',
      ),
      'rubik' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'rubik',
        'weight' => '10',
      ),
      'tao' => array(
        'region' => 'footer',
        'status' => '1',
        'theme' => 'tao',
        'weight' => '10',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'user-menu',
    'module' => 'system',
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

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'leaderboard',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '-13',
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

  $export['user-new'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'new',
    'module' => 'user',
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
        'region' => 'dashboard_inactive',
        'status' => '1',
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

  $export['user-online'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'online',
    'module' => 'user',
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
        'region' => 'dashboard_inactive',
        'status' => '1',
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

  $export['views-conferences-block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'conferences-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'conferences',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'content',
        'status' => '1',
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
    'title' => '<none>',
    'visibility' => '1',
  );

  $export['views-next_bike_bike_-block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'next_bike_bike_-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'leaderboard',
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

  $export['views-org_map-block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'org_map-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bike_bike' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'bike_bike',
        'weight' => '-8',
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
    'title' => 'Where is Bike!Bike!?',
    'visibility' => '1',
  );

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
    'title' => '<none>',
    'visibility' => '1',
  );

  return $export;
}
