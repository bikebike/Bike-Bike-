<div class="profile"<?php print $attributes; ?>>
	<?php $user_profile['user_picture']['#printed'] = 1; ?>
	<?php print theme('image_style', array('style_name' => 'icon_meduim', 'path' => ($elements['#account']->picture ? $elements['#account']->picture->uri : variable_get('user_picture_default', '')), 'attributes' => array('class' => 'avatar'))); ?>
	<h3><?php print format_username($elements['#account']); ?></h3>
	<?php print render($user_profile); ?>
</div>
