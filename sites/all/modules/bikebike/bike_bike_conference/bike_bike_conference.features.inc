<?php
/**
 * @file
 * bike_bike_conference.features.inc
 */

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
