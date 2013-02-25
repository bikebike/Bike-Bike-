<?php
/**
 * @file
 * all_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function all_features_default_rules_configuration() {
  $items = array();
  $items['rules_redirect_to_edit_page'] = entity_import('rules_config', '{ "rules_redirect_to_edit_page" : {
      "LABEL" : "Redirect to edit page",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_insert" ],
      "DO" : [ { "redirect" : { "url" : "user\\/[account:uid]\\/edit" } } ]
    }
  }');
  return $items;
}
