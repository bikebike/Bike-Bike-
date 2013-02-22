<<?php print $tag; ?> class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php if (!$label_hidden) : ?>
    <h2 class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</h2>
  <?php endif; ?>
  
  <?php
  	$is_org_admin = false;
  	global $user;
  	if (user_is_logged_in())
  	{
  		foreach ($element['#object']->field_administrators['und'] as $admin)
	  	{
  			if ($admin['target_id'] == $user->uid)
  			{
	  			$is_org_admin = true;
  			}
  		}
  	}
  ?>

  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item) : ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
        <?php print render($item); ?>
      </div>
    <?php endforeach; ?>
  </div>
  <?php if (!$is_org_admin && user_is_logged_in()): ?>
  	<div class="button-container">
		<a href="<?php print $element['#object']->nid.'/add-admin/'; ?>" class="important-button" id="add-me-as-admin">Add Me</a>
	</div>
  <?php endif; ?>
</<?php print $tag; ?>>