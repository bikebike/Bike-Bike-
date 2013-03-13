<?php
/**
 * @file
 * workshop.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function workshop_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'workshops';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Workshops';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Workshops';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_looking_for_coordinators',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
    'field_formatter_class' => '',
  );
  /* Field: Content: Presentation Style */
  $handler->display->display_options['fields']['field_presentation_style']['id'] = 'field_presentation_style';
  $handler->display->display_options['fields']['field_presentation_style']['table'] = 'field_data_field_presentation_style';
  $handler->display->display_options['fields']['field_presentation_style']['field'] = 'field_presentation_style';
  $handler->display->display_options['fields']['field_presentation_style']['label'] = '';
  $handler->display->display_options['fields']['field_presentation_style']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_presentation_style']['type'] = 'custom_formatters_term_with_class';
  $handler->display->display_options['fields']['field_presentation_style']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Field: Content: Coordinators */
  $handler->display->display_options['fields']['field_coordinators']['id'] = 'field_coordinators';
  $handler->display->display_options['fields']['field_coordinators']['table'] = 'field_data_field_coordinators';
  $handler->display->display_options['fields']['field_coordinators']['field'] = 'field_coordinators';
  $handler->display->display_options['fields']['field_coordinators']['type'] = 'custom_formatters_link_with_picture';
  $handler->display->display_options['fields']['field_coordinators']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_coordinators']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_coordinators']['multi_type'] = 'ul';
  /* Field: Content: Looking for Coordinators */
  $handler->display->display_options['fields']['field_looking_for_coordinators']['id'] = 'field_looking_for_coordinators';
  $handler->display->display_options['fields']['field_looking_for_coordinators']['table'] = 'field_data_field_looking_for_coordinators';
  $handler->display->display_options['fields']['field_looking_for_coordinators']['field'] = 'field_looking_for_coordinators';
  $handler->display->display_options['fields']['field_looking_for_coordinators']['label'] = '';
  $handler->display->display_options['fields']['field_looking_for_coordinators']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_looking_for_coordinators']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_looking_for_coordinators']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Conference (field_conference) */
  $handler->display->display_options['arguments']['field_conference_nid']['id'] = 'field_conference_nid';
  $handler->display->display_options['arguments']['field_conference_nid']['table'] = 'field_data_field_conference';
  $handler->display->display_options['arguments']['field_conference_nid']['field'] = 'field_conference_nid';
  $handler->display->display_options['arguments']['field_conference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_conference_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_conference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_conference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_conference_nid']['summary_options']['items_per_page'] = '25';
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
    'workshop' => 'workshop',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'proposed');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['workshops'] = array(
    t('Master'),
    t('Workshops'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Coordinators'),
    t('All'),
    t('Block'),
  );
  $export['workshops'] = $view;

  return $export;
}
