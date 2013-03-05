<?php
/**
 * @file
 * bike_bike_conference.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function bike_bike_conference_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'link_with_icon';
  $formatter->label = 'Link with Icon';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'entityreference, node_reference';
  $formatter->code = '// Formatter settings.
$settings = $variables[\'#display\'][\'settings\'];

$element = array();
foreach ($variables[\'#items\'] as $delta => $item) {
  $con = node_load($item[\'target_id\']);
  $element[$delta] = array(
    \'#type\' => \'link\',
    \'#href\' => \'node/\'.$con->nid,
    \'#title\' => theme(\'image_style\', array(\'style_name\' => \'icon_meduim\', \'path\' => ($con->field_icon ? $con->field_icon[\'und\'][0][\'uri\'] : variable_get(\'user_picture_default\', \'\')), \'attributes\' => array(\'class\' => \'avatar\'))).\'<h3>\'.$con->title.\'</h3>\',
    \'#attributes\' => array(\'class\' => \'org-profile\', \'title\' => $con->title),
    \'#options\' => array(
      \'html\' => TRUE,
    ),
  );
}
return $element;';
  $formatter->fapi = '';
  $export['link_with_icon'] = $formatter;

  return $export;
}
