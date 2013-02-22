This module provides a live preview for the Entity Reference autocomplete
widget.  To use it:

1. Create an entity reference field, and set it to use an autocomplete widget
   (the normal one, NOT the tags-style one).

2. Edit the field settings.  In the "Live preview settings" fieldset, select
   the "Enable" checkbox, and choose a view mode (e.g. teaser) to use.  This is
   the view mode that will be used to render the field for the live preview, so
   it's a view mode of the referencing entity, not the referenced entity.

   For example: if you have two content types "Album" and "Track" and the Album
   content type has an entity reference field that can reference Track nodes,
   then you should select a view mode for the Album content type.  Then, when
   editing an album, you will see a preview of the references to Track nodes as
   they will appear when the Album is rendered in the selected view mode.

   IMPORTANT!  If you choose a view mode in which your entity reference field
   is hidden, then it will be hidden in the preview too, and nothing will be
   displayed.

   If you don't want to use a real view mode like "teaser", you can create a
   custom one just for the preview using e.g. Display Suite.
