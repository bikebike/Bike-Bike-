<?php
/**
 * @file
 * all_features.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function all_features_custom_formatters_defaults() {
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

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'term_with_class';
  $formatter->label = 'Term with class';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'taxonomy_term_reference';
  $formatter->code = '// Formatter settings.
$settings = $variables[\'#display\'][\'settings\'];

$element = array();
foreach ($variables[\'#items\'] as $delta => $item) {
  $term = taxonomy_term_load($item[\'tid\']);
  $element[$delta] = array(
    \'#type\' => \'markup\',
    \'#markup\' => \'<span title="\'.$term->name.\'" class="\'.str_replace(\'_\', \'-\', $term->vocabulary_machine_name).\' \'.str_replace(\'_\', \'-\', $term->vocabulary_machine_name).\'--\'.strtolower(preg_replace(\'/\\s+/\', \'-\', preg_replace(\'/\\//\', \'\', $term->name))).\'">\'.$term->name.\'</span>\',
    \'#attributes\' => array(\'class\' => \'profilez\'),
    \'#options\' => array(
      \'html\' => TRUE,
    ),
  );
}
return $element;';
  $formatter->fapi = '';
  $export['term_with_class'] = $formatter;

  return $export;
}
