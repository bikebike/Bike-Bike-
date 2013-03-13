<?php
/**
 * @file
 * form_fields.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function form_fields_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'field';
  $formatter->label = 'Field';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'entityreference';
  $formatter->code = '// Formatter settings.
$settings = $variables[\'#display\'][\'settings\'];

$element = array();
foreach ($variables[\'#items\'] as $delta => $item) {
  $node = node_load($item[\'target_id\']);
  $element[$delta] = array(
    \'#type\' => \'link\',
    \'#href\' => \'node/\'.$node->nid,
    \'#title\' => \'<h3>\'.$node->title.\'</h3>\',
    \'#attributes\' => array(\'class\' => \'entity\', \'title\' => $node->title),
    \'#options\' => array(
      \'html\' => TRUE,
    ),
  );
}
return $element;';
  $formatter->fapi = '';
  $export['field'] = $formatter;

  return $export;
}
