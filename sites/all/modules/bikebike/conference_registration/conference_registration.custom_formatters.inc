<?php
/**
 * @file
 * conference_registration.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function conference_registration_custom_formatters_defaults() {
  $export = array();

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
