<<?php print $tag; ?> class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php if (!$label_hidden) : ?>
    <h2 class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp; </h2>
  <?php endif; ?>

  <div class="field-items"<?php print $content_attributes; ?>>
  	<!-- <?php print_r($element['#object']); ?> -->
    <?php foreach ($items as $delta => $item) : ?>
		<?php print theme('image_style', array('style_name' => 'icon_small', 'path' => ($item->field_icon ? $item->field_icon['und'][0]['uri'] : variable_get('user_picture_default', '')), 'attributes' => array('class' => 'avatar'))); ?>
		<h3><?php print $item->title; ?></h3>
    <?php endforeach; ?>
  </div>

</<?php print $tag; ?>>
