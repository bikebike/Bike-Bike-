<section class="<?php print $classes; ?>"<?php print $attributes; ?>>
<h2 class="field-label"<?php print $title_attributes; ?>>Registration:</h2>
<?php if (isset($element['#object']->field_registration_open[$element['#object']->language]) && $element['#object']->field_registration_open[$element['#object']->language][0]['value'] == 1): ?>
	<?php if (node_access('update', $element['#object'])): ?>
		<a href="conference-registration/<?php print $element['#object']->nid; ?>/close" class="important-button" id="reg-open">Close Registration</a>
	<?php endif; ?>
	<?php
		/*$args = array();
		$view = views_get_view('conference_registration_button');
		print $view->preview('block', $args);*/
		global $user;
		$reg = _bikebike_get_registation($user->uid, $element['#object']->nid);
		if ($reg)
		{
			print '<p>'.t('You are currently registered for this conference').'</p><a href="/conferences/'.$element['#object']->nid.'/registration" class="important-button">'.t('Modify your registration details...').'</a>';
		}
		else
		{
			print '<a href="/conferences/'.$element['#object']->nid.'/registration" class="important-button">'.t('Register for this conference...').'</a>';
		}
	?>
<?php else: ?>
	<?php if (node_access('update', $element['#object'])): ?>
		<a href="conference-registration/<?php print $element['#object']->nid; ?>/open" class="important-button" id="reg-open">Open Registration</a>
	<?php endif; ?>
	<p class="message">Registration is not open for this conference at this time</p>
<?php endif; ?>
</section>