<?php
/**
 * @file
 * request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function request_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function request_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function request_node_info() {
  $items = array(
    'request' => array(
      'name' => t('Request'),
      'base' => 'node_content',
      'description' => t('A request or invitation for types that require access such as organizations or workshops.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
