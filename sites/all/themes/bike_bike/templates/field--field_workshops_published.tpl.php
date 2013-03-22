<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php if (isset($element['#object']->field_registration_open['und']) && $element['#object']->field_registration_open['und'][0]['value'] == 1): ?>
	<?php if (isset($element['#object']->field_workshops_published['und']) && $element['#object']->field_workshops_published['und'][0]['value'] != 1) : ?>
		<?php if (node_access('update', $element['#object'])): ?>
			<a href="conferences/<?php print $element['#object']->nid; ?>/schedule/manage" class="important-button" id="workshops-scheduled"><?php print t('Create Workshop Schedule...'); ?></a>
		<?php endif; ?>
		<?php
			$args = array();
			/*$view = views_get_view('conference_registration_button');
			print $view->preview('workshop_register', $args);*/
			global $user;
			$reg = _bikebike_get_registation($user->uid, $element['#object']->nid);
			if ($reg && $reg[0]->data == 'yes')
			{
				print '<a href="node/add/workshop/'.$element['#object']->nid.'" class="important-button">'.t('Propose a Workshop...').'</a>';
			}
			else
			{
				print '<p class="message">Once registered, you may propose a workshop of your own or volunteer to help others with theirs.</p>';
			}
			$view = views_get_view('workshops');
			print $view->preview('proposed', $args);
		?>
	<?php else: ?>
		<?php if (node_access('update', $element['#object'])): ?>
			<a href="conferences/<?php print $element['#object']->nid; ?>/schedule/manage" class="important-button" id="workshops-scheduled"><?php print t('Edit Workshop Schedule...'); ?></a>
		<?php endif; ?>
	<?php endif; ?>
<?php else: ?>
<?php endif; ?>
</div>
