<?php
/**
 * @file
 * organization.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function organization_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_organization_secret',
    'dependent' => 'field_reply',
    'dependee' => 'field_question',
    'options' => array(
      'state' => 'required',
      'condition' => 'value',
      'grouping' => 'AND',
      'effect' => FALSE,
      'effect_options' => array(),
      'element_view' => array(
        1 => '1',
        2 => '2',
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        3 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        4 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        5 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => '1',
        3 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => '1',
          3 => 0,
        ),
        2 => array(
          1 => '1',
          3 => 0,
        ),
        3 => array(
          1 => '1',
          3 => 0,
        ),
        4 => array(
          1 => '1',
          3 => 0,
        ),
        5 => array(
          1 => '1',
          3 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => '1',
      'value_form' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'value' => array(
        0 => array(
          'value' => '',
        ),
      ),
      'values' => array(),
    ),
  );

  return $items;
}
