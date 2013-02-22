(function ($) {
 
    /**
     * Attaches the autocomplete behavior to all required fields.
     */
    Drupal.behaviors.dynamicAutocomplete = {
      attach: function (context, settings) {
        $('input.form-autocomplete').change(function(i) {
        	//var str = $('#edit-divisions_child a.selected').attr('id');
        	//var n = str.replace("edit-divisions_msa_",""); 
        	//Drupal.behaviors.dynamicAutocompleteAttach(n);
        	console.log(i);
        	console.log($(this));
        	console.log('i');
        });
      }
    };
 
    Drupal.behaviors.dynamicAutocompleteAttach = function (division) {    
      $('#edit-school-name').unbind().val('');
      $('#edit-school-name').each(function(i) {
	      //Get the (hidden) *-autocomplete input element
	      var input_autocomplete = $('#edit-school-name-autocomplete');
	      // Update autocomplete url
	      input_autocomplete.val(Drupal.settings.dynamicAutocomplete.autocompleteUrl + division);
	      // Mark as not processed.
	      input_autocomplete.removeClass('autocomplete-processed');
	      //Call autocomplete
	 
      });  
      Drupal.behaviors.autocomplete.attach(document);
    };
 
})(jQuery);

/*
jQuery(document).ready(
	function()
	{
		jQuery("input.form-autocomplete").bind('autocomplete_select',
			function(event)
			{
				var selected = jQuery('#autocomplete > ul > li.selected').html();
				jQuery(this).parent().find('div.selected-preview').remove();
				jQuery(this).hide();
				jQuery(this).parent().append('<div class="selected-preview">' + selected + '</div>');
			}
		);
	}
);

(function ($) {
	
	Drupal.jsAC = function ($input, db) {
		  var ac = this;
		  this.input = $input[0];
		  this.ariaLive = $('#' + this.input.id + '-autocomplete-aria-live');
		  this.db = db;

		  $input
		    .keydown(function (event) { return ac.onkeydown(this, event); })
		    .keyup(function (event) { ac.onkeyup(this, event); })
		    .blur(function () { ac.hidePopup(); ac.db.cancel(); });

		};


Drupal.jsAC.prototype.hidePopup = function (keycode) {
	  // Select item if the right key or mousebutton was pressed.
	  if (this.selected && ((keycode && keycode != 46 && keycode != 8 && keycode != 27) || !keycode)) {
	    //this.input.value = $(this.selected).data('autocompleteValue');
		  this.select(this.selected);
	  }
	  // Hide popup.
	  var popup = this.popup;
	  if (popup) {
	    this.popup = null;
	    $(popup).fadeOut('fast', function () { $(popup).remove(); });
	  }
	  this.selected = false;
	  $(this.ariaLive).empty();
};

Drupal.jsAC.prototype.select = function (node) {
	  this.input.value = $(node).data('autocompleteValue');
	  $(this.input).trigger('autocomplete_select');
};

})(jQuery);
*/

function checkboxAutocompleteSelect(id, checked_id)
{
	jQuery('#' + checked_id).attr('checked','checked');
	jQuery('#' + id + ' input.autocomplete-checkboxes-search').val('');
	checkboxAutocompleteUpdate(id);
}

function checkboxAutocompleteDeselect(id, checked_id)
{
	jQuery('#' + checked_id).removeAttr('checked');
	checkboxAutocompleteUpdate(id);
}

function checkboxAutocompleteChange(id)
{
	var val = jQuery('#' + id).find('input.autocomplete-checkboxes-search').val();
	var visibleCount = 0;
	jQuery('#' + id).find('.autocomplete-checkboxes-dropdown .autocomplete-checkboxes-noresults').remove();
	jQuery('#' + id).find('.autocomplete-checkboxes-dropdown .form-type-checkbox').each(
		function ()
		{
			if (jQuery(this).find('input.form-checkbox').is(':checked'))
			{
				jQuery(this).hide();
			}
			else
			{
				var text = jQuery(this).find('.searchable').html();
				//console.log(val + ' | ' + text);
				if (val.length <= 0 || text.toLowerCase().indexOf(val.toLowerCase()) >= 0)
				{
					jQuery(this).show();
					visibleCount++;
				}
				else
				{
					jQuery(this).hide();
				}
			}
		}
	);
	if (visibleCount < 1)
	{
		jQuery('#' + id).find('.autocomplete-checkboxes-dropdown').append('<div class="autocomplete-checkboxes-noresults">Nothing found</div>');
	}
}

function checkboxAutocompleteFocus(id)
{
	checkboxAutocompleteChange(id);
	jQuery('#' + id).find('.autocomplete-checkboxes-dropdown').show();
}

function checkboxAutocompleteBlur(id)
{
	setTimeout(function() { jQuery('#' + id).find('.autocomplete-checkboxes-dropdown').hide(); }, 100);
}

function checkboxAutocompleteUpdate(id)
{
	var list = jQuery('#' + id).find('.autocomplete-checkboxes-list');
	list.empty();
	jQuery('#' + id).find('.autocomplete-checkboxes-dropdown .form-type-checkbox').each(
		function ()
		{
			if (jQuery(this).find('input.form-checkbox').is(':checked'))
			{
				var html = jQuery(this).clone();
				var checkbox_id = html.find('input.form-checkbox').attr('id');
				html.find('input.form-checkbox').remove();
				html.find('a.autocomplete-checkboxes-selector').remove();
				list.append('<li>' + html.html() + '<a class="autocomplete-checkboxes-deselect" onclick="checkboxAutocompleteDeselect(\'' + id + '\', \'' + checkbox_id + '\')"></a></li>')
			}
		}
	);
}

function checkboxAutocomplete(id)
{
	jQuery('#' + id).html(
		function(index, oldhtml)
		{
			var id = jQuery(this).attr('id');
			return '<div class="autocomplete-checkboxes-selector"><input onfocus="checkboxAutocompleteFocus(\'' + id + '\')" onblur="checkboxAutocompleteBlur(\'' + id + '\')" onkeyup="checkboxAutocompleteChange(\'' + id + '\')" type="text" class="autocomplete-checkboxes-search" /><div class="autocomplete-checkboxes-dropdown">' + oldhtml + '</div></div><ul class="autocomplete-checkboxes-list"></ul><div style="clear: left;"></div>';
		}
	);
	jQuery('#' + id + ' .form-checkbox').before( function () { return '<a onclick="checkboxAutocompleteSelect(\'' + id + '\', \'' + jQuery(this).attr('id') + '\')" class="autocomplete-checkboxes-selector"></a>' } )
	jQuery('#' + id + ' .form-checkbox').hide();
	checkboxAutocompleteUpdate(id);
}

/*jQuery(document).ready(
	function ()
	{
		jQuery(document).delegate('.field-name-field-custom-css textarea', 'keydown',
			function(e)
			{
				var keyCode = e.keyCode || e.which;

				if (keyCode == 9)
				{
					e.preventDefault();
					var start = jQuery(this).get(0).selectionStart;
					var end = jQuery(this).get(0).selectionEnd;
					
					// set textarea value to: text before caret + tab + text after caret
					jQuery(this).val(jQuery(this).val().substring(0, start)
					            + "\t"
					            + jQuery(this).val().substring(end));
					
					// put caret at right position again
					jQuery(this).get(0).selectionStart =
					jQuery(this).get(0).selectionEnd = start + 1;
				}
		});
		
		/*jQuery('.views-exposed-form .views-exposed-widgets').each(
			function ()
			{
				var textFields = jQuery(this).find('.views-exposed-widget .form-type-textfield input');
				if (textFields.length > 0)
				{
					var submit = jQuery(this).find('.views-submit-button input');
					textFields.keydown(function() { jQuery(this).trigger('change'); });
				}
			}
		);*/
		
		/*jQuery('.form-type-checkboxes .form-checkboxes').each(
			function ()
			{
				if (jQuery(this).find('.form-item.form-type-checkbox .views-field').length > 0)
				{
					checkboxAutocomplete(jQuery(this).attr('id'));
					console.log(jQuery(this).attr('id'));
				}
			}
		);* /
	}
);*/

