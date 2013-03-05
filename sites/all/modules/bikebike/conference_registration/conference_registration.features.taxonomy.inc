<?php
/**
 * @file
 * conference_registration.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function conference_registration_taxonomy_default_vocabularies() {
  return array(
    'yes_no_maybe' => array(
      'name' => 'Yes, No, Maybe',
      'machine_name' => 'yes_no_maybe',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
