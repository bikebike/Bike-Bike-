<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php if (isset($element['#object']->field_registration_open[$element['#object']->language]) && $element['#object']->field_registration_open[$element['#object']->language][0]['value'] == 1): ?>
	<?php if (isset($element['#object']->field_workshops_published[$element['#object']->language]) && $element['#object']->field_workshops_published[$element['#object']->language][0]['value'] != 1) : ?>
		<?php if (node_access('update', $element['#object'])): ?>
			<a href="workshops/<?php print $element['#object']->nid; ?>/schedule" class="important-button" id="workshops-scheduled">Create Workshop Schedule...</a>
		<?php endif; ?>
		<?php
			$args = array();
			$view = views_get_view('conference_registration_button');
			print $view->preview('workshop_register', $args);
			$view = views_get_view('workshops');
			print $view->preview('proposed', $args);
		?>
	<?php else: ?>
		<?php if (node_access('update', $element['#object'])): ?>
			<a href="workshops/<?php print $element['#object']->nid; ?>/schedule" class="important-button" id="workshops-scheduled">Edit Workshop Schedule...</a>
		<?php endif; ?>
	<?php endif; ?>
<?php else: ?>
<?php endif; ?>
</div>
