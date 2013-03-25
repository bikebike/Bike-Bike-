<div class="user-profile"<?php print $attributes; ?>>
<?php if ($elements['#account']->field_about_me && isset($elements['#account']->field_about_me['und'])): ?>
<section id="about">
	<h2><?php print t('About Me:'); ?></h2>
	<?php print render(field_view_field('user', $elements['#account'], 'field_about_me', array('label' => 'hidden'))); ?>
</section>

<?php endif; ?>	
  <?php
	$view = views_get_view('organization_list');
	$view->set_display('user_block');
	$view->dom_id = 'organizations';
	$output = $view->render();
	
	if ($view->total_rows)
	{
		print '<h2>'.format_plural($view->total_rows, 'Organization', 'Organizations').'</h2>';
		print $output;
		if ($user->uid == $elements['#account']->uid)
		{
			print '<div class="button-container">'.l('Register a new organization', 'node/add/organization', array('attributes' => array('class' => array('important-button')))).'</div>';
		}
	}
	else if ($user->uid == $elements['#account']->uid)
	{
		print '<h2>'.format_plural($view->total_rows, 'Organization', 'Organizations').'</h2>';
		print t('You are not currently a member of any organizations. Find your organization and request membership. Only if you are sure your organization does not yet exist; register a new organization on this site.');
		print '<div class="button-container">'.
				l('Find your organization', 'organizations', array('attributes' => array('class' => array('important-button')))).
				l('Register a new organization', 'node/add/organization', array('attributes' => array('class' => array('important-button', 'less-important')))).
			'</div>';
	}
  ?>
  <?php global $user; if ($user->uid == $elements['#account']->uid): ?>
	
<?php endif; ?>
</div>
