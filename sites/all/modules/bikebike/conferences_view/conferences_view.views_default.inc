<?php
/**
 * @file
 * conferences_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function conferences_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'conferences';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conferences';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Conferences';
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
      'field' => 'field_conference_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="node/add/conference" class="important-button">Register a new conference</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Banner */
  $handler->display->display_options['fields']['field_banner']['id'] = 'field_banner';
  $handler->display->display_options['fields']['field_banner']['table'] = 'field_data_field_banner';
  $handler->display->display_options['fields']['field_banner']['field'] = 'field_banner';
  $handler->display->display_options['fields']['field_banner']['label'] = '';
  $handler->display->display_options['fields']['field_banner']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_banner']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_banner']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
    'field_formatter_class' => '',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long_date_only_',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
    'field_formatter_class' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Host Organizations */
  $handler->display->display_options['fields']['field_host_organizations']['id'] = 'field_host_organizations';
  $handler->display->display_options['fields']['field_host_organizations']['table'] = 'field_data_field_host_organizations';
  $handler->display->display_options['fields']['field_host_organizations']['field'] = 'field_host_organizations';
  $handler->display->display_options['fields']['field_host_organizations']['label'] = 'Hosted By';
  $handler->display->display_options['fields']['field_host_organizations']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_host_organizations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_host_organizations']['type'] = 'custom_formatters_link_with_icon';
  $handler->display->display_options['fields']['field_host_organizations']['settings'] = array(
    'field_formatter_class' => '',
  );
  $handler->display->display_options['fields']['field_host_organizations']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_host_organizations']['multi_type'] = 'ul';
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
  /* Field: Content: Conference Type */
  $handler->display->display_options['fields']['field_conference_type']['id'] = 'field_conference_type';
  $handler->display->display_options['fields']['field_conference_type']['table'] = 'field_data_field_conference_type';
  $handler->display->display_options['fields']['field_conference_type']['field'] = 'field_conference_type';
  $handler->display->display_options['fields']['field_conference_type']['label'] = '';
  $handler->display->display_options['fields']['field_conference_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_conference_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_conference_type']['alter']['text'] = '[field_conference_type] Conferences';
  $handler->display->display_options['fields']['field_conference_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conference_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_conference_type']['settings'] = array(
    'field_formatter_class' => '',
  );
  /* Sort criterion: Content: Conference Type (field_conference_type) */
  $handler->display->display_options['sorts']['field_conference_type_tid']['id'] = 'field_conference_type_tid';
  $handler->display->display_options['sorts']['field_conference_type_tid']['table'] = 'field_data_field_conference_type';
  $handler->display->display_options['sorts']['field_conference_type_tid']['field'] = 'field_conference_type_tid';
  /* Sort criterion: Content: Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
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
    'conference' => 'conference',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['conferences'] = $view;

  return $export;
}
