<?php
/**
 * @file
 * conference_registration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function conference_registration_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_node_info().
 */
function conference_registration_node_info() {
  $items = array(
    'conference_registration' => array(
      'name' => t('Conference Registration'),
      'base' => 'node_content',
      'description' => t('Registration information for attending a conference.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
