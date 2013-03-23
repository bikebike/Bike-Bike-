<?php

module_load_include('inc', 'privatemsg', 'privatemsg.pages');

function bikebike_menu_alter(&$items)
{
	/*$items['entityreference/autocomplete/single/%/%/%'] = array(
			'title' => 'Entity Reference Autocomplete',
			'page callback' => 'bikebike_autocomplete_callback',
			'page arguments' => array(2, 3, 4, 5),
			'access callback' => 'entityreference_autocomplete_access_callback',
			'access arguments' => array(2, 3, 4, 5),
			'type' => MENU_CALLBACK,
	);*/
	$items['node/add/workshop/%']['access callback'] = 'bikebike_add_workshop_access';
	$items['node/add/workshop/%']['access arguments'] = array('create', 'workshop', 3);
	$items['node/add/workshop/%']['title'] = t('Propose a Workshop');
	$items['node/add/event/%']['access callback'] = 'bikebike_add_event_access';
	$items['node/add/event/%']['access arguments'] = array('create', 'event', 3);
	$items['messages/list']['access callback'] = FALSE;
	return $items;
}

function bikebike_menu()
{
	$items = array
	(
			'organizations/%node/add-member' => array
			(
					'title' => t('Request Membership'),
					'page callback' => 'drupal_get_form',
					'description' => 'Add yourself as an organization administrator',
					'page arguments' => array('bikebike_add_member', 1, false, 'organization'),
					'access callback' => 'bikebike_organization_add_member_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'organizations/%node/remove-member' => array
			(
					'title' => t('Revoke Membership'),
					'page callback' => 'drupal_get_form',
					'description' => 'Remove yourself as an organization administrator',
					'page arguments' => array('bikebike_add_member', 1, true, 'organization'),
					'access callback' => 'bikebike_organization_remove_member_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%/workshops/%node/add-coordinator' => array
			(
					'title' => t('Help Coordinate'),
					'page callback' => 'drupal_get_form',
					'description' => 'Add yourself as a workshop coordinator',
					'page arguments' => array('bikebike_add_member', 3, false, 'workshop'),
					'access callback' => 'bikebike_organization_add_member_access',
					'access arguments' => array(3),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%/workshops/%node/remove-coordinator' => array
			(
					'title' => t('Revoke Coordinator Position'),
					'page callback' => 'drupal_get_form',
					'description' => 'Remove yourself as a workshop coordinator',
					'page arguments' => array('bikebike_add_member', 3, true, 'workshop'),
					'access callback' => 'bikebike_organization_remove_member_access',
					'access arguments' => array(3),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			/*'conference-registration/%node/cancel' => array
			(
					'title' => t('Add Organization Administrator'),
					'page callback' => 'bikebike_change_registration',
					'page arguments' => array(1, false),
					'access callback' => TRUE,
					'type' => MENU_CALLBACK
			),
			'conference-registration/%node/confirm' => array
			(
					'title' => 'Add Organization Administrator',
					'page callback' => 'bikebike_change_registration',
					'page arguments' => array(1, true),
					'access callback' => TRUE,
					'type' => MENU_CALLBACK
			),*/
			'admin/config/system/gitpull' => array
			(
					'title' => 'Pull From Git Repository',
					'page callback' => 'bikebike_git_pull',
					'description' => 'Updates the site from the GitHub Repository',
					'page arguments' => array(),
					'access callback' => 'bikebike_git_pull_access',//array('access git pull'),
					'type' => MENU_NORMAL_ITEM
			),
			'conferences/%node/registration/open' => array
			(
					'title' => t('Open Registraion'),
					'page callback' => 'drupal_get_form',
					'description' => 'Open Registration',
					//'page arguments' => array(1, true),
					'page arguments' => array('bikebike_options_dlg', array('message' => 'Are you sure? Once registration is open, users will be able to register using you registration form. Have you finished compiling the form? (Go to: Registration > Registration Options)', 'actions' => array(array('name' => 'yes', 'title' => 'Yes', 'action' => 'bikebike_conference_registration_open'), array('name' => 'cancel', 'title' => 'No', 'action' => 'bikebike_add_member_cancel'))), 1, true),
					'access callback' => 'bikebike_registration_openclose_access',
					'access arguments' => array(1, true),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/registration/close' => array
			(
					'title' => t('Close Registration'),
					'page callback' => 'drupal_get_form',
					'description' => 'Open Registration',
					'page arguments' => array('bikebike_options_dlg', array('message' => 'Are you sure? Closing registration will prevent users from registering for this conference.', 'actions' => array(array('name' => 'yes', 'title' => 'Yes', 'action' => 'bikebike_conference_registration_open'), array('name' => 'cancel', 'title' => 'No', 'action' => 'bikebike_add_member_cancel'))), 1, false),
					//'page arguments' => array(1, false),
					'access callback' => 'bikebike_registration_openclose_access',
					'access arguments' => array(1, false),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'organizations/%node/cancel-request' => array
			(
					'title' => t('Cancel Membership Request'),
					'page callback' => 'drupal_get_form',
					'description' => 'Cancel your request to be an organization administrator',
					'page arguments' => array('bikebike_options_dlg', array('message' => 'Are you sure?', 'actions' => array(array('name' => 'yes', 'title' => 'Yes', 'action' => 'bikebike_cancel_request'), array('name' => 'cancel', 'title' => 'No', 'action' => 'bikebike_add_member_cancel'))), 1, 'organization'),
					'access callback' => 'bikebike_organization_cancel_request_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%/workshops/%node/cancel-request' => array
			(
					'title' => t('Cancel Coordinator Request'),
					'page callback' => 'drupal_get_form',
					'description' => 'Cancel your request to be an workshop coordinator',
					'page arguments' => array('bikebike_options_dlg', array('message' => 'Are you sure?', 'actions' => array(array('name' => 'yes', 'title' => 'Yes', 'action' => 'bikebike_cancel_request'), array('name' => 'cancel', 'title' => 'No', 'action' => 'bikebike_add_member_cancel'))), 3, 'workshop'),
					//'page arguments' => array(3, 'workshop'),
					'access callback' => 'bikebike_organization_cancel_request_access',
					'access arguments' => array(3),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'organizations/%node/requests' => array
			(
					'title' => t('Membership Requests'),
					'page callback' => 'drupal_get_form',
					'description' => 'Approve or Deny Membership to This Organization',
					'page arguments' => array('bikebike_requests_page', 'organization', 1),
					'access callback' => 'node_access',
					'access arguments' => array('update', 1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'organizations/%node/members' => array
			(
					'title' => t('Members'),
					'page callback' => 'drupal_get_form',
					'description' => 'Approve or Deny Membership to This Organization',
					'page arguments' => array('bikebike_requests_page', 'organization', 1),
					'access callback' => 'node_access',
					'access arguments' => array('view', 1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%/workshops/%node/members' => array
			(
					'title' => t('Coordinators'),
					'page callback' => 'drupal_get_form',
					'description' => 'Coordinators for This Workshop',
					'page arguments' => array('bikebike_requests_page', 'workshop', 3),
					'access callback' => 'node_access',
					'access arguments' => array('view', 3),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'organizations/%node/invitations' => array
			(
					'title' => t('Membership Invitations'),
					'page callback' => 'drupal_get_form',
					'description' => 'Manage Membership Invitations',
					'page arguments' => array('bikebike_invitations_page', 'organization', 1),
					'access callback' => 'node_access',
					'access arguments' => array('update', 1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%/workshops/%node/invitations' => array
			(
					'title' => t('Coordinator Invitations'),
					'page callback' => 'drupal_get_form',
					'description' => 'Manage Coordinator Invitations',
					'page arguments' => array('bikebike_invitations_page', 'workshop', 3),
					'access callback' => 'node_access',
					'access arguments' => array('update', 3),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'organizations/%node/accept-invitation/%' => array
			(
					'title' => t('Accept Membership'),
					'page callback' => 'drupal_get_form',
					//'page arguments' => array('organization', 1, 3, true),
					'page arguments' => array('bikebike_options_dlg', array('message' => 'Are you sure?', 'actions' => array(array('name' => 'yes', 'title' => 'Yes', 'action' => 'bikebike_accept_invitation'), array('name' => 'cancel', 'title' => 'No', 'action' => 'bikebike_add_member_cancel'))), 'organization', 1, 3, true),
					'access callback' => 'bikebike_organization_accept_invitation_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/workshops/%/accept-invitation/%' => array
			(
					'title' => t('Accept Coordinator Invitation'),
					//'page callback' => 'bikebike_accept_invitation',
					//'page arguments' => array('workshop', 3, 5, true),
					'page callback' => 'drupal_get_form',
					'page arguments' => array('bikebike_options_dlg', array('message' => 'Are you sure?', 'actions' => array(array('name' => 'yes', 'title' => 'Yes', 'action' => 'bikebike_accept_invitation'), array('name' => 'cancel', 'title' => 'No', 'action' => 'bikebike_add_member_cancel'))), 'workshop', 3, 5, true),
					'access callback' => 'bikebike_organization_accept_invitation_access',
					'access arguments' => array(3),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'organizations/%node/reject-invitation/%' => array
			(
					'title' => t('Reject Member Invitation'),
					//'page callback' => 'bikebike_accept_invitation',
					//'page arguments' => array('organization', 1, 3, false),
					'page callback' => 'drupal_get_form',
					'page arguments' => array('bikebike_options_dlg', array('message' => 'Are you sure?', 'actions' => array(array('name' => 'yes', 'title' => 'Yes', 'action' => 'bikebike_accept_invitation'), array('name' => 'cancel', 'title' => 'No', 'action' => 'bikebike_add_member_cancel'))), 'organization', 1, 3, false),
					'access callback' => 'bikebike_organization_accept_invitation_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/workshops/%/reject-invitation/%' => array
			(
					'title' => t('Reject Coordinator Invitation'),
					//'page callback' => 'bikebike_accept_invitation',
					//'page arguments' => array('workshop', 3, 5, false),
					'page callback' => 'drupal_get_form',
					'page arguments' => array('bikebike_options_dlg', array('message' => 'Are you sure?', 'actions' => array(array('name' => 'yes', 'title' => 'Yes', 'action' => 'bikebike_accept_invitation'), array('name' => 'cancel', 'title' => 'No', 'action' => 'bikebike_add_member_cancel'))), 'workshop', 3, 5, false),
					'access callback' => 'bikebike_organization_accept_invitation_access',
					'access arguments' => array(3),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/registration' => array
			(
					'title' => t('Registration'),
					'page callback' => 'drupal_get_form',
					'description' => 'Register for this Conference',
					'page arguments' => array('bikebike_registration_page', 1),
					'access callback' => 'bikebike_conference_registration_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/registration/manage' => array
			(
					'title' => t('Registration Options'),
					'page callback' => 'drupal_get_form',
					'description' => '',
					'page arguments' => array('bikebike_registration_options_page', 1),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/registration/fields' => array
			(
					'title' => t('Registration Form Fields'),
					'page callback' => 'bikebike_registration_fields_page',
					'description' => '',
					'page arguments' => array(1),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/registration/fields/add' => array
			(
					'title' => t('Create Registration Form Field'),
					'page callback' => 'drupal_get_form',
					'description' => '',
					'page arguments' => array('bikebike_registration_field_create_page', 1, 'form_field'),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/registration/fields/edit/%' => array
			(
					'title' => t('Create Registration Form Field'),
					'page callback' => 'drupal_get_form',
					'description' => '',
					'page arguments' => array('bikebike_registration_field_create_page', 1, 'form_field', 5),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/schedule/events/add' => array
			(
					'title' => t('Create Registration Form Field'),
					'page callback' => 'drupal_get_form',
					'description' => '',
					'page arguments' => array('bikebike_registration_field_create_page', 1, 'event'),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/schedule/events/edit/%' => array
			(
					'title' => t('Create Registration Form Field'),
					'page callback' => 'drupal_get_form',
					'description' => '',
					'page arguments' => array('bikebike_registration_field_create_page', 1, 'event', 5),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/registration/registrations' => array
			(
					'title' => t('Registrations'),
					'page callback' => 'bikebike_registration_registrations_page',
					'description' => '',
					'page arguments' => array(1),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/schedule' => array
			(
					'title' => t('Schedule'),
					'page callback' => 'bikebike_schedule_page',
					'description' => 'Schedule',
					'page arguments' => array(1),
					'access callback' => 'bikebike_conference_schedule_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/schedule/manage' => array
			(
					'title' => t('Manage Schedule'),
					'page callback' => 'drupal_get_form',
					'description' => 'Work out your conference schedule',
					'page arguments' => array('bikebike_scheduler_page', 1),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/schedule/locations' => array
			(
					'title' => t('Locations'),
					'page callback' => 'drupal_get_form',
					'description' => 'Workshop and Event locations',
					'page arguments' => array('bikebike_schedule_locations_page', 1),
					'access callback' => 'bikebike_conference_schedule_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/schedule/events' => array
			(
					'title' => t('Events'),
					'page callback' => 'bikebike_schedule_events_page',//'drupal_get_form',
					'description' => 'Conference Events',
					'page arguments' => array(1),
					'access callback' => 'bikebike_conference_schedule_access',
					'access arguments' => array(1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'conferences/%node/schedule/manage/conflicts' => array
			(
					'title' => t('Manage Conference Schedule'),
					'page callback' => 'bikebike_scheduler_page_conflicts',
					//'description' => 'Work out your conference schedule',
					'page arguments' => array(1),
					'access callback' => 'bikebike_conference_access',
					'access arguments' => array(1),
					'type' => MENU_CALLBACK
			),
			'conferences/%node/workshops' => array
			(
					'title' => t('Workshops'),
					'page callback' => 'bikebike_conference_workshops',
					//'description' => 'Work out your conference schedule',
					'page arguments' => array(1),
					'access callback' => 'node_access',
					'access arguments' => array('view', 1),
					'type' => MENU_VISIBLE_IN_BREADCRUMB,
					'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			),
			'ajax-form' => array
			(
					//'title' => t('Workshops'),
					'page callback' => 'bikebike_ajax_form',
					//'description' => 'Work out your conference schedule',
					'page arguments' => array(),
					'access callback' => TRUE,//'node_access',
					//'access arguments' => array('view', 1),
					'type' => MENU_CALLBACK,
			),
			'messages/new/%' => array(
			    'title'            => 'Message',
			    'page callback'    => 'drupal_get_form',
			    'page arguments'   => array('privatemsg_new', 2, NULL, NULL),
			    //'file'             => 'privatemsg.pages.inc',
			    'access callback'  => 'privatemsg_user_access',
			    'access arguments' => array('write privatemsg'),
			    //'type'             => MENU_LOCAL_ACTION,
			    'weight'           => -3,
			    'menu_name'        => 'user-menu',
				'type' => MENU_VISIBLE_IN_BREADCRUMB,
				'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
			  )
			/*
			'users/%user/message/new' => array
			(
					//'title' => t('Workshops'),
					'page callback' => 'bikebike_privatemsg_user',
					//'description' => 'Work out your conference schedule',
					'page arguments' => array(1),
					'access callback' => 'privatemsg_user_access',
					'access arguments' => array('write privatemsg'),
					'type' => MENU_CALLBACK,
			),*/
	);
	return $items;
}
