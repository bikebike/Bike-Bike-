<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 * 
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "bike_bike" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "bike_bike".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function bike_bike_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.
  
  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function bike_bike_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */
/* -- Delete this line if you want to use these functions*/
function bike_bike_preprocess_page(&$vars)
{
	drupal_add_js('https://maps.googleapis.com/maps/api/js?key=AIzaSyDitM1lyVWkrumteDvSkje6GiIKYyHlAXM&sensor=false');
	/*if (!empty($vars['node']))
	{
		$variables['theme_hook_suggestions'][] = 'page--node--' . $vars['node']->type;
		drupal_set_message('<pre>'.print_r($variables['theme_hook_suggestions'], true).'</php>');
	}*/
	//print_r($vars);
}
/*function bike_bike_process_page(&$vars)
{
	if (!empty($vars['node']))
	{
		$variables['theme_hook_suggestions'][] = 'page--node--' . $vars['node']->type;
		drupal_set_message('<pre>'.print_r($variables['theme_hook_suggestions'], true).'</php>');
	}
}
// */

/**
 * Override or insert variables into the node templates.
 */
/* -- Delete this line if you want to use these functions
function bike_bike_preprocess_node(&$vars) {
}
function bike_bike_process_node(&$vars) {
}
// */


/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function bike_bike_preprocess_comment(&$vars) {
}
function bike_bike_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function bike_bike_preprocess_block(&$vars) {
}
function bike_bike_process_block(&$vars) {
}
// */

/*function bike_bike_node_form($form) {
	switch($form['type']['#value']) {
		case 'organization':
			$title = empty($form['nid']['#value']) ? 'Register an Organization' : 'Edit Organization Details';
			drupal_set_title($title);
			break;
	}
	return drupal_render($form);
}*/

function bike_bike_file_icon($variables)
{
	$file = $variables['file'];
	$icon_directory = drupal_get_path('theme', 'bike_bike').'/images/icons';

	$mime = check_plain($file->filemime);
	//drupal_set_message('<pre>'.print_r($variables, true).'</pre>');
	$icon_url = file_icon_url($file, $icon_directory);
	return '<img alt="" class="file-icon" src="' . $icon_url . '" title="' . $mime . '" />';
}

function bike_bike_menu_link(array $variables)
{
	global $user;
	$element = $variables['element'];
	$sub_menu = '';

	if ($element['#below'])
	{
		$sub_menu = drupal_render($element['#below']);
	}
	$title = '';
	// Check if the user is logged in, that you are in the correct menu,
	// and that you have the right menu item
	//drupal_set_message($element['#theme']);
	if ($user->uid != 0 && $element['#theme'] == 'menu_link__menu_log_out' && $element['#title'] == t('User Account'))
	{
		$element['#title'] = $user->name;
		$element['#attributes']['title'] = $user->name;
		// Add 'html' = TRUE to the link options
		$element['#localized_options']['html'] = TRUE;
		// Load the user picture file information; Unnecessary if you use theme_user_picture()
		//_bikebike_show_object($user);
		$file = ($user->picture ? file_load($user->picture)->uri : variable_get('user_picture_default', ''));
		//$file = file_load($fid);
		// I found it necessary to use theme_image_style() instead of theme_user_picture()
		// because I didn't want any extra html, just the image.
		$title = theme('image_style', array('style_name' => 'icon_small', 'path' => $file, 'alt' => $element['#title'], 'title' => $element['#title']));// . $element['#title'];
	}
	else
	{
		$title = $element['#title'];
	}
	$output = l($title, $element['#href'], $element['#localized_options']);
	return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
