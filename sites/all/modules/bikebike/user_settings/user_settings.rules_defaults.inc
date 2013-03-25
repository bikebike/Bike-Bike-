<?php
/**
 * @file
 * user_settings.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function user_settings_default_rules_configuration() {
  $items = array();
  $items['rules_new_private_message'] = entity_import('rules_config', '{ "rules_new_private_message" : {
      "LABEL" : "New Private Message",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "privatemsg_rules" ],
      "ON" : [ "privatemsg_insert" ],
      "DO" : [
        { "mail" : {
            "to" : [ "recipient:mail" ],
            "subject" : "[Bike!Bike!] You have received a new message from [privatemsg-message:author:name]",
            "message" : "[privatemsg-message:author:name][privatemsg-message:summary]",
            "from" : "[privatemsg-message:author:name]\\u003Cnoreply@bikebike.org\\u003E",
            "language" : [ "recipient:language" ]
          }
        }
      ]
    }
  }');
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
