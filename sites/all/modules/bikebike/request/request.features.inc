<?php
/**
 * @file
 * request.features.inc
 */

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
