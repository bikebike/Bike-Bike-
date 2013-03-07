<?php
/**
 * @file
 * workshop.features.inc
 */

/**
 * Implements hook_views_api().
 */
function workshop_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function workshop_node_info() {
  $items = array(
    'workshop' => array(
      'name' => t('Workshop'),
      'base' => 'node_content',
      'description' => t('A conference workshop'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
