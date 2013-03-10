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
  <?php if (user_is_logged_in()): ?>
  	<div class="button-container">
  	<?php if ($is_org_admin): ?>
		<?php if (count($element['#object']->field_administrators['und']) > 1): ?><a href="<?php print $element['#object']->nid.'/remove-admin/'; ?>" class="important-button" id="remove-me-as-admin">Remove Me</a><?php endif; ?>
	<?php elseif ($invitation = bikebike_get_invitation($element['#object'], $user->mail)): ?>
		<div class="invitation">
			<p>You have been invited to become a member of this Organization</p>
			<a href="<?php print $element['#object']->nid.'/accept-invitation/'.$invitation->title; ?>" class="important-button" id="accept-invitation">Accept Invitation</a>
			<a href="<?php print $element['#object']->nid.'/reject-invitation/'.$invitation->title; ?>" class="important-button" id="reject-invitation">Reject Invitation</a>
		</div>
	<?php elseif (bikebike_create_request_exists($element['#object'], $user)): ?>
		<a href="<?php print $element['#object']->nid.'/cancel-request/'; ?>" class="important-button" id="cancel-add-me-as-admin">Cancel Your Request</a>
	<?php else: ?>
		<a href="<?php print $element['#object']->nid.'/add-admin/'; ?>" class="important-button" id="add-me-as-admin">Add Me</a>
  	<?php endif; ?>
	</div>
	<?php endif; ?>
</<?php print $tag; ?>>

<?php if ($is_org_admin): ?>
<section class="field field-name-field-requests field-type-entityreference field-label-above view-mode-full">
	       	<?php
			$args = array();
			$view = views_get_view('requests');
			print $view->preview('block', $args);
			$view = views_get_view('requests');
			print $view->preview('invitations', $args);
			?>
</section>
<?php endif; ?>