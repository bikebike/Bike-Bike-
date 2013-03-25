<?php
/**
 * @file
 * user_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function user_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:node/5
  $menu_links['main-menu:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Conferences',
    'options' => array(
      'attributes' => array(
        'title' => 'Information about upcoming or past conferences, both international and regional',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:node/6
  $menu_links['main-menu:node/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Organizations',
    'options' => array(
      'attributes' => array(
        'title' => 'Find information about the organizations involved or add yours to our list',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:node/7
  $menu_links['main-menu:node/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Resources',
    'options' => array(
      'attributes' => array(
        'title' => 'Search through the available resources or help others by adding your own',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-log-out:http://dev.bikebike.org:82/users/godwin
  $menu_links['menu-log-out:http://dev.bikebike.org:82/users/godwin'] = array(
    'menu_name' => 'menu-log-out',
    'link_path' => 'http://dev.bikebike.org:82/users/godwin',
    'router_path' => '',
    'link_title' => 'My Account',
    'options' => array(
      'menu_token_link_path' => '[current-user:url]',
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'attributes' => array(
        'title' => 'View and edit your user details',
        'id' => 'user-account-menu-item',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'http://dev.bikebike.org:82/users/godwin',
  );
  // Exported menu link: menu-log-out:menutoken/513cdec9d3cb5
  $menu_links['menu-log-out:menutoken/513cdec9d3cb5'] = array(
    'menu_name' => 'menu-log-out',
    'link_path' => 'menutoken/513cdec9d3cb5',
    'router_path' => 'menutoken/%',
    'link_title' => 'User Account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'menu_token_link_path' => '[current-user:url]',
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'clear' => 0,
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-50',
  );
  // Exported menu link: menu-log-out:messages
  $menu_links['menu-log-out:messages'] = array(
    'menu_name' => 'menu-log-out',
    'link_path' => 'messages',
    'router_path' => 'messages',
    'link_title' => 'Messages',
    'options' => array(
      'attributes' => array(
        'id' => 'user-messages-menu-item',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => 'http://dev.bikebike.org:82/users/godwin',
  );
  // Exported menu link: menu-log-out:user/logout
  $menu_links['menu-log-out:user/logout'] = array(
    'menu_name' => 'menu-log-out',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log Out',
    'options' => array(
      'attributes' => array(
        'id' => 'user-logout-menu-item',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => 'http://dev.bikebike.org:82/users/godwin',
  );
  // Exported menu link: menu-login-menu:user
  $menu_links['menu-login-menu:user'] = array(
    'menu_name' => 'menu-login-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Log in',
    'options' => array(
      'attributes' => array(
        'title' => 'Log into the site or create a new account',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: user-menu:messages
  $menu_links['user-menu:messages'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'messages',
    'router_path' => 'messages',
    'link_title' => 'Messages',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: user-menu:user
  $menu_links['user-menu:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-10',
  );
  // Exported menu link: user-menu:user/login
  $menu_links['user-menu:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'user',
  );
  // Exported menu link: user-menu:user/logout
  $menu_links['user-menu:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '10',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Conferences');
  t('Log Out');
  t('Log in');
  t('Log out');
  t('Messages');
  t('My Account');
  t('Organizations');
  t('Resources');
  t('User Account');
  t('User account');


  return $menu_links;
}
