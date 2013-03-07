<?php
/**
 * @file
 * conference_location.features.inc
 */

/**
 * Implements hook_node_info().
 */
function conference_location_node_info() {
  $items = array(
    'conference_location' => array(
      'name' => t('Conference Location'),
      'base' => 'node_content',
      'description' => t('A location where workshops, lunch, or anything else during the conference will take place'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
