<?php
/**
 * @file
 * bike_bike_conference.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bike_bike_conference_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attachments|node|conference|default';
  $field_group->group_name = 'group_attachments';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Proposed Workshops',
    'weight' => '2',
    'children' => array(
      0 => 'field_workshops_published',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Proposed Workshops',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_attachments|node|conference|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|conference|default';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_content|node|conference|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details_wrapper|node|conference|default';
  $field_group->group_name = 'group_details_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_poster',
      1 => 'group_details',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details_wrapper|node|conference|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|conference|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_details_wrapper';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'field_host_organizations',
      1 => 'field_date',
      2 => 'field_registration_open',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_details|node|conference|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_identity|node|conference|form';
  $field_group->group_name = 'group_identity';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Identity',
    'weight' => '7',
    'children' => array(
      0 => 'field_banner',
      1 => 'field_poster',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Identity',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_identity|node|conference|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_registration|node|conference|form';
  $field_group->group_name = 'group_registration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Registration',
    'weight' => '10',
    'children' => array(
      0 => 'field_registration_open',
      1 => 'field_fields',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_registration|node|conference|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_schedule|node|conference|form';
  $field_group->group_name = 'group_schedule';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Schedule',
    'weight' => '8',
    'children' => array(
      0 => 'field_workshops_published',
      1 => 'field_locations',
      2 => 'field_meals_provided',
      3 => 'field_meal_info',
      4 => 'field_scheduled_times',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_schedule|node|conference|form'] = $field_group;

  return $export;
}
