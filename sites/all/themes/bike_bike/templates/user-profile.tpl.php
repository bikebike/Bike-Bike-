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
	print '<h2>'.format_plural($view->total_rows, 'Organization', 'Organizations').'</h2>';
	print $output;
  ?>
  <?php global $user; if ($user->uid == $elements['#account']->uid): ?>
	<div class="button-container"><?php print l('Register a new organization', 'node/add/organization', array('attributes' => array('class' => array('important-button')))); ?></div>
<?php endif; ?>
</div>
