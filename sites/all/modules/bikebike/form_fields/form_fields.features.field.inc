<?php
/**
 * @file
 * form_fields.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function form_fields_field_default_fields() {
  $fields = array();

  // Exported field: 'node-form_field-body'.
  $fields['node-form_field-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'form_field',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'field_formatter_class' => '',
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'field_formatter_class' => '',
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Help Text',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'css_code' => 0,
            'filtered_html' => 'filtered_html',
            'full_html' => 0,
            'php_code' => 0,
            'plain_text' => 0,
          ),
          'allowed_formats_toggle' => 1,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'css_code' => array(
                'weight' => '0',
              ),
              'filtered_html' => array(
                'weight' => '0',
              ),
              'full_html' => array(
                'weight' => '1',
              ),
              'php_code' => array(
                'weight' => '11',
              ),
              'plain_text' => array(
                'weight' => '10',
              ),
            ),
          ),
        ),
        'display_summary' => 0,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '31',
      ),
    ),
  );

  // Exported field: 'node-form_field-field_field_type'.
  $fields['node-form_field-field_field_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_field_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'checkbox' => 'Checkbox',
          'date' => 'Date',
          'select' => 'Single Select',
          'checkboxes' => 'Multiple Select',
          'textfield' => 'Text',
          'textarea' => 'Long text',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'form_field',
      'default_value' => array(
        0 => array(
          'value' => 'textarea',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(
            'field_formatter_class' => '',
          ),
          'type' => 'list_default',
          'weight' => 2,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_field_type',
      'label' => 'Field Type',
      'required' => 1,
      'settings' => array(
        'jquery_ui_multiselect' => array(
          'dividerLocation' => 0.5,
          'doubleClickable' => 1,
          'dragToAdd' => 1,
          'enabled' => 0,
          'height' => 0,
          'includeAddAll' => 1,
          'includeRemoveAll' => 1,
          'searchable' => 1,
          'selectedContainerOnLeft' => 1,
          'sortable' => 1,
          'width' => 0,
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '33',
      ),
    ),
  );

  // Exported field: 'node-form_field-field_include_other_option'.
  $fields['node-form_field-field_include_other_option'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_include_other_option',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'form_field',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(
            'field_formatter_class' => '',
          ),
          'type' => 'list_default',
          'weight' => 4,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_include_other_option',
      'label' => 'Include Other Option',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '35',
      ),
    ),
  );

  // Exported field: 'node-form_field-field_options'.
  $fields['node-form_field-field_options'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_options',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'form_field',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Enter options delimited by new lines, you may also include key/display pairs in the form of: key|display. Example:
1|Yes
2|No
3|Maybe',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'field_formatter_class' => '',
          ),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_options',
      'label' => 'Options',
      'required' => 1,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'css_code' => 'css_code',
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'php_code' => 'php_code',
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'css_code' => array(
                'weight' => '0',
              ),
              'filtered_html' => array(
                'weight' => '0',
              ),
              'full_html' => array(
                'weight' => '1',
              ),
              'php_code' => array(
                'weight' => '11',
              ),
              'plain_text' => array(
                'weight' => '10',
              ),
            ),
          ),
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '34',
      ),
    ),
  );

  // Exported field: 'node-form_field-field_required'.
  $fields['node-form_field-field_required'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_required',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '',
          1 => '',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'form_field',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(
            'field_formatter_class' => '',
          ),
          'type' => 'list_default',
          'weight' => 1,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_required',
      'label' => 'Required',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '32',
      ),
    ),
  );

  // Exported field: 'node-form_field-field_retired'.
  $fields['node-form_field-field_retired'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_retired',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => '0',
          1 => '1',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'form_field',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(
            'field_formatter_class' => '',
          ),
          'type' => 'list_default',
          'weight' => 5,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_retired',
      'label' => 'Retired',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '36',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter options delimited by new lines, you may also include key/display pairs in the form of: key|display. Example:
1|Yes
2|No
3|Maybe');
  t('Field Type');
  t('Help Text');
  t('Include Other Option');
  t('Options');
  t('Required');
  t('Retired');

  return $fields;
}
