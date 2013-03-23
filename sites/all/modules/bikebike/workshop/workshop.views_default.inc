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
    1 => array(
      'field' => 'nid',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_presentation_style']['element_label_type'] = 'h3';
  $handler->display->display_options['fields']['field_presentation_style']['type'] = 'custom_formatters_term_with_class';
  $handler->display->display_options['fields']['field_presentation_style']['settings'] = array(
    'field_formatter_class' => '',
  );
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'schedule');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
    'workshop' => 'workshop',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_conference_location_target_id']['id'] = 'field_conference_location_target_id';
  $handler->display->display_options['filters']['field_conference_location_target_id']['table'] = 'field_data_field_conference_location';
  $handler->display->display_options['filters']['field_conference_location_target_id']['field'] = 'field_conference_location_target_id';
  $handler->display->display_options['filters']['field_conference_location_target_id']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_conference_location_target_id']['value'] = array(
    'min' => '',
    'max' => '',
    'value' => '',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '99';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['groupby_times'] = 'half';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'article' => '#ffffff',
    'page' => '#ffffff',
    'conference' => '#ffffff',
    'conference_location' => '#ffffff',
    'conference_registration' => '#ffffff',
    'event' => '#ffffff',
    'form_field' => '#ffffff',
    'organization' => '#ffffff',
    'registration_form' => '#ffffff',
    'request' => '#ffffff',
    'workshop' => '#ffffff',
  );
  $handler->display->display_options['row_options']['colors']['taxonomy_field'] = 'field_presentation_style';
  $handler->display->display_options['row_options']['colors']['calendar_colors_vocabulary'] = array(
    'field_presentation_style' => '6',
  );
  $handler->display->display_options['row_options']['colors']['calendar_colors_taxonomy'] = array(
    13 => '#ffffff',
    15 => '#ffffff',
    12 => '#ffffff',
    14 => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Field: Scheduled Time */
  $handler->display->display_options['fields']['field_scheduled_time']['id'] = 'field_scheduled_time';
  $handler->display->display_options['fields']['field_scheduled_time']['table'] = 'field_data_field_scheduled_time';
  $handler->display->display_options['fields']['field_scheduled_time']['field'] = 'field_scheduled_time';
  $handler->display->display_options['fields']['field_scheduled_time']['label'] = '';
  $handler->display->display_options['fields']['field_scheduled_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_scheduled_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
    'field_formatter_class' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Scheduled Time -  start date (field_scheduled_time) */
  $handler->display->display_options['sorts']['field_scheduled_time_value']['id'] = 'field_scheduled_time_value';
  $handler->display->display_options['sorts']['field_scheduled_time_value']['table'] = 'field_data_field_scheduled_time';
  $handler->display->display_options['sorts']['field_scheduled_time_value']['field'] = 'field_scheduled_time_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Conference (field_conference) */
  $handler->display->display_options['arguments']['field_conference_nid']['id'] = 'field_conference_nid';
  $handler->display->display_options['arguments']['field_conference_nid']['table'] = 'field_data_field_conference';
  $handler->display->display_options['arguments']['field_conference_nid']['field'] = 'field_conference_nid';
  $handler->display->display_options['arguments']['field_conference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_conference_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_conference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_conference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_conference_nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'hour';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
  );
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
    t('Presentation Style'),
    t('[title]'),
    t('All'),
    t('Block'),
  );
  $export['workshops'] = $view;

  return $export;
}
