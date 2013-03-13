<?php
/**
 * @file
 * request.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function request_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Requests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="!1/requests" class="button">Approve/Deny Requests...</a>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '<h2 class="field-label">Requests (@total):</h2>';
  /* Relationship: Content: Node (field_node) */
  $handler->display->display_options['relationships']['field_node_nid']['id'] = 'field_node_nid';
  $handler->display->display_options['relationships']['field_node_nid']['table'] = 'field_data_field_node';
  $handler->display->display_options['relationships']['field_node_nid']['field'] = 'field_node_nid';
  $handler->display->display_options['relationships']['field_node_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_node_nid']['delta'] = '-1';
  /* Field: Content: Email Address */
  $handler->display->display_options['fields']['field_email_address']['id'] = 'field_email_address';
  $handler->display->display_options['fields']['field_email_address']['table'] = 'field_data_field_email_address';
  $handler->display->display_options['fields']['field_email_address']['field'] = 'field_email_address';
  $handler->display->display_options['fields']['field_email_address']['label'] = '';
  $handler->display->display_options['fields']['field_email_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email_address']['type'] = 'custom_formatters_user_profile_from_email';
  $handler->display->display_options['fields']['field_email_address']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Node (field_node) */
  $handler->display->display_options['arguments']['field_node_nid']['id'] = 'field_node_nid';
  $handler->display->display_options['arguments']['field_node_nid']['table'] = 'field_data_field_node';
  $handler->display->display_options['arguments']['field_node_nid']['field'] = 'field_node_nid';
  $handler->display->display_options['arguments']['field_node_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_node_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_node_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_node_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_node_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'request' => 'request',
  );
  /* Filter criterion: Content: Invitation (field_invitation) */
  $handler->display->display_options['filters']['field_invitation_value']['id'] = 'field_invitation_value';
  $handler->display->display_options['filters']['field_invitation_value']['table'] = 'field_data_field_invitation';
  $handler->display->display_options['filters']['field_invitation_value']['field'] = 'field_invitation_value';
  $handler->display->display_options['filters']['field_invitation_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_invitation_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: State (field_state) */
  $handler->display->display_options['filters']['field_state_value']['id'] = 'field_state_value';
  $handler->display->display_options['filters']['field_state_value']['table'] = 'field_data_field_state';
  $handler->display->display_options['filters']['field_state_value']['field'] = 'field_state_value';
  $handler->display->display_options['filters']['field_state_value']['value'] = array(
    0 => '0',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'request' => 'request',
  );
  /* Filter criterion: Content: Invitation (field_invitation) */
  $handler->display->display_options['filters']['field_invitation_value']['id'] = 'field_invitation_value';
  $handler->display->display_options['filters']['field_invitation_value']['table'] = 'field_data_field_invitation';
  $handler->display->display_options['filters']['field_invitation_value']['field'] = 'field_invitation_value';
  $handler->display->display_options['filters']['field_invitation_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_invitation_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: State (field_state) */
  $handler->display->display_options['filters']['field_state_value']['id'] = 'field_state_value';
  $handler->display->display_options['filters']['field_state_value']['table'] = 'field_data_field_state';
  $handler->display->display_options['filters']['field_state_value']['field'] = 'field_state_value';
  $handler->display->display_options['filters']['field_state_value']['value'] = array(
    0 => '0',
  );

  /* Display: Invitations */
  $handler = $view->new_display('block', 'Invitations', 'invitations');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Invitations';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="!1/invitations" class="button">Manage Invitations...</a>';
  $handler->display->display_options['header']['area_text_custom']['tokenize'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2 class="field-label">Invitations (@total):</h2>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<a href="!1/invitations" class="important-button">Invite Members...</a>';
  $handler->display->display_options['empty']['area_text_custom']['tokenize'] = TRUE;
  $translatables['requests'] = array(
    t('Master'),
    t('Requests'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="!1/requests" class="button">Approve/Deny Requests...</a>'),
    t('<h2 class="field-label">Requests (@total):</h2>'),
    t('field_node'),
    t('All'),
    t('Block'),
    t('Invitations'),
    t('<a href="!1/invitations" class="button">Manage Invitations...</a>'),
    t('<h2 class="field-label">Invitations (@total):</h2>'),
    t('<a href="!1/invitations" class="important-button">Invite Members...</a>'),
  );
  $export['requests'] = $view;

  return $export;
}
