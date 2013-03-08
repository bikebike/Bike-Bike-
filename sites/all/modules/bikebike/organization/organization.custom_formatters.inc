<?php
/**
 * @file
 * organization.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function organization_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'link_with_picture';
  $formatter->label = 'Link with Picture';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'entityreference';
  $formatter->code = '// Formatter settings.
$settings = $variables[\'#display\'][\'settings\'];

$element = array();
foreach ($variables[\'#items\'] as $delta => $item) {
  $usr = user_load($item[\'target_id\']);
  $element[$delta] = array(
    \'#type\' => \'link\',
    \'#href\' => \'user/\'.$usr->uid,
    \'#title\' => theme(\'image_style\', array(\'style_name\' => \'icon_meduim\', \'path\' => ($usr->picture ? $usr->picture->uri : variable_get(\'user_picture_default\', \'\')), \'attributes\' => array(\'class\' => \'avatar\'))).\'<h3>\'.$usr->name.\'</h3>\',
    \'#attributes\' => array(\'class\' => \'profile\'),
    \'#options\' => array(
      \'html\' => TRUE,
    ),
  );
}
return $element;';
  $formatter->fapi = '';
  $export['link_with_picture'] = $formatter;

  return $export;
}
