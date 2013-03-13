<?php
/**
 * @file
 * form_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function form_fields_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function form_fields_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function form_fields_node_info() {
  $items = array(
    'form_field' => array(
      'name' => t('Form Field'),
      'base' => 'node_content',
      'description' => t('Describes a field to be included on Conference Registration pages'),
      'has_title' => '1',
      'title_label' => t('Label'),
      'help' => '',
    ),
  );
  return $items;
}
