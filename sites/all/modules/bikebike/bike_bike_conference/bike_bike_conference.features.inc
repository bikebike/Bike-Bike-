<?php
/**
 * @file
 * bike_bike_conference.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bike_bike_conference_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_node_info().
 */
function bike_bike_conference_node_info() {
  $items = array(
    'conference' => array(
      'name' => t('Conference'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
