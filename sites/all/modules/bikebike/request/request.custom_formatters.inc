<?php
/**
 * @file
 * request.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function request_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'user_profile_from_email';
  $formatter->label = 'User Profile From Email';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'email';
  $formatter->code = '// Formatter settings.
$settings = $variables[\'#display\'][\'settings\'];

$element = array();
foreach ($variables[\'#items\'] as $delta => $item) {
  $usr = _bikebike_user_load_from_email($item[\'email\']);
  $element[$delta] = array(
    \'#type\' => is_object($usr) ? \'link\' : \'markup\',
    \'#href\' => \'user/\'.$usr->uid,
    (is_object($usr) ? \'#title\' : \'#markup\') => is_object($usr) ? theme(\'image_style\', array(\'style_name\' => \'icon_meduim\', \'path\' => ($usr->picture ? $usr->picture->uri : variable_get(\'user_picture_default\', \'\')), \'attributes\' => array(\'class\' => \'avatar\'))).\'<h3>\'.$usr->name.\'</h3>\' : $usr,
    \'#attributes\' => array(\'class\' => \'profile\'),
    \'#options\' => array(
      \'html\' => TRUE,
    ),
  );
}
return $element;';
  $formatter->fapi = '';
  $export['user_profile_from_email'] = $formatter;

  return $export;
}
