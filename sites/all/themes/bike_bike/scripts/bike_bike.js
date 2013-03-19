jQuery.extend(jQuery.expr[':'],{
    inView: function(a) {
        var st = (document.documentElement.scrollTop || document.body.scrollTop),
            ot = jQuery(a).offset().top + (jQuery(a).height() / 2.0),
            wh = (window.innerHeight && window.innerHeight < jQuery(window).height()) ? window.innerHeight : jQuery(window).height();
        return ot > st && ot < (st + wh);
    }
});

function expandDay(day)
{
	jQuery('#edit-schedule-' + day + ' ul.times > li.unpopular').slideDown();
	jQuery('#expand-day-' + day).css('display', 'none');
	jQuery('#collapse-day-' + day).css('display', 'block');
}

function collapseDay(day)
{
	jQuery('#edit-schedule-' + day + ' ul.times > li.unpopular').slideUp();
	jQuery('#expand-day-' + day).css('display', 'block');
	jQuery('#collapse-day-' + day).css('display', 'none');
}

var dumbGlobal;

(function ($) {

	function validateScheduledItem(item)
	{
		//console.log('validating...');
		var li = $(item).closest('li');
		var liNext = li;
		var height = $(item).height() / 26;
		for (var i = 1; i < height; i++)
		{
			liNext = liNext.next();
			if (liNext.length < 1 || !liNext.is(':visible') || !liNext.hasClass('available'))
			{
				$(item).height((i * 26) - 2);
				return;
			}
			if (liNext.find('.ui-draggable').length > 0)
			{
				$(item).height((i * 26) - 2);
				return;
			}
		}
	}
	
	function validateDroppables(validateWorkshopConflicts)
	{
		var droppableHeight = 0;
		var dropClass = '';
    	if (validateWorkshopConflicts)
    	{
    		$('#edit-schedule ul.times .schedulable').addClass('validating');
    	}
		$('.ui-draggable').find('input.location').val('');
		$('.ui-draggable').find('input.time').val('');
		$('.ui-draggable').find('input.length').val('');
    	$('#edit-schedule ul.times > li').each
    	(
    		function ()
    		{
    			var draggable = $(this).find('.ui-draggable');
    			var droppable = $(this).find('.ui-droppable');
    			if (draggable.length > 0)
    			{
    				droppableHeight = Math.round(draggable.height() / 26);
    				dropClass = draggable.attr('id');
    				draggable.find('input.location').val(this.className.replace(/^.*l\-(\d+).*/, '$1'));
    				draggable.find('input.time').val(this.className.replace(/^.*t\-(\d+).*/, '$1'));
    				draggable.find('input.length').val(droppableHeight);
    				draggable.removeClass('conflict').removeAttr('title');
    			}
    			if (droppable.length > 0)
    			{
    				droppable[0].className = droppable[0].className.replace(/\s*(workshop|event|meal)-\d+/, '');
	    			if (droppableHeight > 0)
	    			{
	    				droppable.droppable('disable');
	    				droppable.addClass(dropClass);
	    			}
	    			else
	    			{
	    				droppable.droppable('enable');
	    			}
    			}   				
   				if (droppableHeight > 0)
   				{
   	   				droppableHeight--;
   				}
    		}
    	);
    	if (validateWorkshopConflicts)
    	{
    		$('#edit-schedule').addClass('screen-edits');
    		$.ajax
	    	(
				{
					url: "manage/conflicts",
					type: "post",
					data: $('form#bikebike-scheduler-page').serialize(),
					success:
						function (data)
						{
							var conflicts = jQuery.parseJSON(data);
							for (var nidA in conflicts)
							{
								var nidB = conflicts[nidA].nid;
								$('#workshop-' + nidA).addClass('conflict').attr('title', conflicts[nidA].messageA);
								$('#workshop-' + nidB).addClass('conflict').attr('title', conflicts[nidA].messageB);
							}
							$('#edit-schedule').removeClass('screen-edits');
							$('#edit-schedule ul.times .schedulable').removeClass('validating');
						},
					error:
						function ()
						{
							//alert("failure");
							$('#edit-schedule').removeClass('screen-edits');
						}
	    	    }
			);
    	}
	}
	
	function dropInto(droppable, dropped, validate)
	{
		if ($(dropped).hasClass('meal') && $(dropped).parent().parent().attr('id') == 'edit-events-meals')
  		{
			if ($('#edit-events-meals .meal').length < 2)
			{
				makeSchedulable($(dropped).clone().appendTo('#edit-events-meals > .fieldset-wrapper').removeAttr('style'));
			}
			var index = 1;
			while ($(dropped).attr('id') == 'meal-0' && $('#meal-' + index).length > 0)
			{
				index++;
			}
			$(dropped).attr('id', 'meal-' + index);
			$(dropped).html
			(
				function (i, html)
				{
					return html.replace(/\[meals\]\[\d+\]/g, '[meals][' + index + ']');
				}
			);
  		}
		$(dropped).detach().css({position: 'absolute', top: -1, left: 40}).appendTo(droppable);
    	$(dropped).resizable
    	(
			{
    	    	grid: 26,
    	    	stop:
    	    		function (event, ui)
    	    		{
    	    			validateScheduledItem(ui.element);
    	    			validateDroppables($(ui.element).hasClass('workshop'));
    	    		}
        	}
    	);
    	$('.time-slot.has-droppable').each
    	(
    		function ()
    		{
    			if (droppable.find('.ui-draggable').length < 1)
    			{
    				droppable.removeClass('has-droppable');
    				droppable.droppable("enable");
    			}
    		}
    	);
    	droppable.addClass('has-droppable');
    	if (validate || validate == undefined)
    	{
    		//console.log('yes');
    		validateScheduledItem(dropped);
    		validateDroppables($(dropped).hasClass('workshop'));
    	}
	}
	
	function makeSchedulable(item)
	{
    	item.draggable
    	(
			{
				revert: "invalid",
				snap: ".schedulable, #edit-schedule ul.times li .time-slot:not(.ui-droppable-disabled)",
				cursorAt: { top: 10, left: 100 },
				start:
					function (event, ui)
					{
						$('.ui-droppable.' + $(this).attr('id')).droppable("enable");
					},
				stop:
					function (event, ui)
					{
						$('.ui-droppable.' + $(this).attr('id')).droppable("disable");
					},
			}
    	);
	}
	
	function hashChange()
	{
		if (location.hash.length > 1 && location.hash.substr(1, 2) == '!/')
		{
			var url = location.hash.substr(3);
			$('html').addClass('overlay');
			if ($('#ajax-form').length < 1)
			{
				$('#content').append('<div id="ajax-form"></div>');
			}
			$.ajax
	    	(
				{
					url: "/ajax-form",
					type: "post",
					data: {url: url},
					success:
						function (data)
						{
							$('#ajax-form').html(data);
							$('input#edit-cancel').click
							(
								function (event)
								{
									location.hash = '';
									event.preventDefault();
								}
							);

							$('#ajax-form-inner').ready
							(
								function ()
								{
									var top = ($(window).height() - $('#ajax-form-inner').outerHeight()) / 3;
									if (top > 30)
									{
										$('#ajax-form-inner').css({marginTop: top});
									}
								}
							);
						},
					error:
						function ()
						{
						}
	    	    }
			);
		}
		else
		{
			$('html').removeClass('overlay');
			$('#ajax-form').remove();
		}
	}
	
	Drupal.behaviors.bike_bike = {
		attach:
			function (context, settings)
	    	{
		    	completeAutocomplete();
		    	
		    	$('#content .field-widget-options-select .ui-multiselect li > strong').each
		    	(
		    		function ()
		    		{
		    			var src = $(this).html();
		    			$(this).after('<img src="' + src + '" />');
		    			$(this).remove();
		    		}
		    	);
		    	
		    	$('a.overlay').each
		    	(
		    		function ()
		    		{
		    			$(this).removeClass('overlay');
		    			$(this).attr
		    			(
	    					'href',
	    					function (i, href)
	    					{
	    						return '#!' + href;
	    					}
    					);
		    		}
	    		);
				jQuery(window).hashchange(function () { hashChange(); });
				hashChange();
	
		    	if ($('body.page-conferences-schedule-manage').length > 0)
		    	{
			    	$('#edit-events, #edit-workshops').draggable
			    	(
						{
							handle: '.fieldset-legend',
							snap: 'body #main-content #content form > div > fieldset#edit-schedule.form-wrapper'
						}
			    	);
			    	
			    	$('#expand-schedule').click
			    	(
			    		function ()
			    		{
			    			$('#edit-schedule').css('max-height', 'none');
			    			$('#expand-schedule').css('display', 'none');
			    			$('#collapse-schedule').css('display', 'block');
			    		}
			    	);
		
			    	$('#collapse-schedule').click
			    	(
			    		function ()
			    		{
			    			$('#edit-schedule').css('max-height', 600);
			    			$('#expand-schedule').css('display', 'block');;
			    			$('#collapse-schedule').css('display', 'none');
			    		}
			    	);
		
			    	$('.schedulable .de-schedule').click
			    	(
			    		function ()
			    		{
			    			var schedulable = $(this).closest('.schedulable');
			    			if (schedulable.hasClass('meal'))
			    			{
			    				schedulable.remove();
			    			}
			    			else
			    			{
			    				schedulable.removeClass('conflict').removeAttr('title');
			    				var dest = schedulable.hasClass('event') ? 'events' : 'workshops';
			    				schedulable.detach().removeAttr('style').prependTo('#edit-' + dest + ' > .fieldset-wrapper').resizable('destroy');
			    			}
			    			$('.ui-droppable.' + schedulable.attr('id')).removeClass('has-droppable');
		    		    	validateDroppables();
			    		}
			    	);
			    	makeSchedulable($('.schedulable'));
			    	$('#edit-schedule ul.times li.available .time-slot').droppable
			    	(
		    			{
		    				activeClass: "ui-state-hover",
							hoverClass: "ui-state-active",
							tolerance: 'pointer',
							accept: '.schedulable',
							drop:
								function (event, ui)
								{
									var dropped = ui.draggable;
									dropInto($(this), dropped)
				    	      	},
			    	    }
					);
			    	$('.schedulable').each
			    	(
			    		function ()
			    		{
			    			var location = $(this).find('input.location').val();
			    			var time = $(this).find('input.time').val();
			    			var length = $(this).find('input.length').val();
			    			if (location && time && length)
			    			{
			    				var timeSlot = $('ul.times li.t-' + time + '.l-' + location + ' .time-slot.ui-droppable');
			    				if (timeSlot.length > 0)
			    				{
			    					dropInto(timeSlot, $(this), false);
			    					$(this).height((length * 26) - 1);
			    				}
			    			}
			    		}
			    	);
			    	validateDroppables();
		    	}
	    	}
    	};
	})(jQuery);

if (Drupal.jsAC)
{
	Drupal.jsAC.prototype.select =
		function (node)
		{
			this.input.value = jQuery(node).data('autocompleteValue');
			completeAutocomplete(this.input);
		};
}
jQuery(window).load
(
	function ()
	{
		completeAutocomplete('.field-widget-entityreference-autocomplete input.form-autocomplete[value!=""]');
	}
);

jQuery.fn.hasParent =
	function(objs)
	{
		// ensure that objs is a jQuery array
		objs = jQuery(objs);
		var found = false;
		jQuery(this[0]).parents().andSelf().each
		(
			function()
			{
				if (jQuery.inArray(this, objs) != -1)
				{
					found = true;
					return false; // stops the each...
				}
			}
		);
		return found;
	}

function completeAutocomplete(element)
{
	/*return;
	jQuery('.field-multiple-table').each
	(
		function ()
		{
			var table = jQuery(this);
			jQuery(this).find('.entityreference-live-preview').each
			(
				function ()
				{
					var input = jQuery(this).next().find('input.form-autocomplete');
					if (input.val() && input.val().match(/^.+ \(\d+\)$/))
					{
						input.hide();
						if (jQuery(this).find('a.autocomplete-remove').length < 1)
						{
							jQuery(this).after('<a href="javascript:void(0)" class="autocomplete-remove" title="Remove this one">Remove</a>');
							jQuery(this).next().click
							(
								function ()
								{
									jQuery(this).next().find('input.form-autocomplete').val('').show().trigger('change');
									jQuery(this).closest('tr').nextAll('tr').toggleClass('even');
									jQuery(this).closest('tr').nextAll('tr').toggleClass('odd');
									if (table.find('.entityreference-live-preview').length > 1)
									{
										jQuery(this).closest('tr').hide();
									}
									else
									{
										jQuery(this).parent().find('input.form-autocomplete').val('').show();
										jQuery(this).remove();
									}
								}
							);
						}
					}
				}
			);
			if (table.find('input.form-autocomplete:visible').length < 1)
			{
				table.next().find('input.field-add-more-submit').show();
			}
			else
			{
				table.next().find('input.field-add-more-submit').hide();
			}
		}
	);
	//jQuery('input.field-add-more-submit').mousedown(function() { completeAutocomplete(); });

	//console.log(jQuery(element).closest('.entityreference-live-preview-container').find('.entityreference-live-preview').html());
	/*if (jQuery(element).hasParent('.field-multiple-table'))// && jQuery(element).closest('.entityreference-live-preview-container').find('.entityreference-live-preview').html())//parent().parent().parent().parent().parent().parent().hasClass('field-multiple-table'))
	{
		jQuery(element).hide();
		if (jQuery(element).parent().find('a.autocomplete-remove').length < 1)
		{
			jQuery(element).before('<a href="javascript:void(0)" class="autocomplete-remove" title="Remove this one">Remove</a>');
			jQuery(element).parent().find('a.autocomplete-remove').click
			(
				function ()
				{
					jQuery(this).parent().find('input.form-autocomplete').val('').show().trigger('change');
					/*if (jQuery(this).closest('tbody').find('tr').length < 1) { console.log('poo'); }* /
					jQuery(this).closest('tr').nextAll('tr').toggleClass('even');
					jQuery(this).closest('tr').nextAll('tr').toggleClass('odd');
					if (jQuery('.field-widget-entityreference-autocomplete input.form-autocomplete[value=""]').length > 1)
					{
						jQuery(this).closest('tr').hide();
					}
					else
					{
						jQuery(this).parent().find('input.form-autocomplete').val('').show();
						jQuery(this).remove();
					}
				}
			);
		}
		var formItem = jQuery(element).closest('.field-widget-entityreference-autocomplete');
		//console.log(formItem.find('input.form-autocomplete'));
		if (formItem.find('input.form-autocomplete:visible').length < 1)
		{
			formItem.find('input.field-add-more-submit').show();
		}
		else
		{
			formItem.find('input.field-add-more-submit').hide();
		}
		//console.log(formItem.html());//find('input.field-add-more-submit'));
	}*/
}

function killWebkitAutofill()
{
	jQuery('input:-webkit-autofill').each(
		function()
		{
			var text = jQuery(this).val();
			var name = jQuery(this).attr('name');
			jQuery(this).after(this.outerHTML).remove();
			jQuery('input[name=' + name + ']').val(text);
		}
	);
}

(function ($) {
	  Drupal.behaviors.autoUpload = {
	    attach: function (context, settings) {
	      $('form', context).delegate('input.form-file', 'change', function() {  
	        $(this).next('input[type="submit"]').mousedown();
	      }); 
	    }
	  };
	})(jQuery);

jQuery(document).ready
(
	function ()
	{
		jQuery('input.field-add-more-submit').mousedown(function() { completeAutocomplete(); });//'.field-widget-entityreference-autocomplete input.form-autocomplete[value!=""]'));
		jQuery('input.field-add-more-submit').keydown(function() { completeAutocomplete(); });
		//jQuery('.entityreference-live-preview').resize(function() { console.log('completeAutocomplete('); });
		jQuery('body.front #primary-menu-bar ul.menu li a').each(
			function ()
			{
				var a = jQuery(this);
				var title = a.attr('title');
				//console.log(title);
				a.parent().prepend('<a class="nav-icon" href="' + a.attr('href') + '"><p>' + title + '</p></div>');//.removeAttr('title');
				//a.parent().find('.nav-icon').click(function() { jQuery(this).parent().find('a').click(); });
				a.removeAttr('title');
			}
		);
		jQuery('.field-widget-entityreference-autocomplete input.form-autocomplete').change(function () {completeAutocomplete(this); });
		if (navigator.userAgent.toLowerCase().indexOf("chrome") >= 0)
		{
			jQuery(window).load(killWebkitAutofill);
			/*jQuery('input[type=text], input[type=password]').keydown(killWebkitAutofill);*/
			jQuery('input[type=text], input[type=password]').change(killWebkitAutofill);
		}
		jQuery('#block-menu-menu-login-menu ul li a').click
		(
			function (event)
			{
				try
				{
					if (jQuery('#block-user-login').is(':visible'))
					{
						jQuery('#block-user-login .form-actions > input').click();
					}
					else
					{
						//jQuery('#block-user-login').slideDown(400, 'easeOutBack');
						//jQuery('#block-fb-connect-login-bike-bike').slideDown(400, 'easeOutBack');
						jQuery('.region-leaderboard .region-inner > .block').slideDown(400, 'easeOutBack');
						jQuery('#block-user-login #edit-name').focus();
						jQuery(this).addClass('submit');
					}
					event.preventDefault();
				}
				catch (err)
				{
					console.log('ERROR! ' + err);
					event.preventDefault();
				}
			}
		);
		jQuery('body.page-user-register .toboggan-unified.register #login-links').after(jQuery('.region-leaderboard #block-fboauth-login'));
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
		
		jQuery('#edit-invitemore-filter').keyup
		(
			function ()
			{
				var str = jQuery(this).val();
				//var checkboxes = jQuery(this).parent.find();
				//console.log(jQuery(this).parent());
				jQuery(this).parent().next().find('.form-item').each
				(
					function ()
					{
						var show = true;
						var text = jQuery(this).find('label > .profile > h3').html();
						if (str.length < 1 || text.match(new RegExp(str, 'gi')))
						{
							jQuery(this).show();
						}
						else
						{
							jQuery(this).hide();
						}
					}
				);
			}
		);
	}
);

function initializeMap(selector)
{
	// Create an array of styles.
	var styles = [
	              {
	            	    "featureType": "water",
	            	    "stylers": [
	            	      { "visibility": "on" },
	            	      { "hue": "#000000" },
	            	      { "color": "#8A9BAB" }
	            	      //{ }
	            	    ]
	            	  },{
	            	    "featureType": "landscape.natural.terrain",
	            	    "stylers": [
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            		    "featureType": "landscape",
	            		    "stylers": [
	            		      { "visibility": "simplified" },
	            		      { "color": "#EEEEEE" }
	            		    ]
	            	  },{
	            	    "featureType": "administrative.country",
	            	    "elementType": "labels",
	            	    "stylers": [
	            	      { "hue": "#1900ff" },
	            	      { "saturation": -11 },
	            	      { "color": "#808080" },
	            	      { "weight": 0.1 },
	            	      { "lightness": 22 },
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            	    "featureType": "poi.park",
	            	    "stylers": [
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            	    "featureType": "road",
	            	    "stylers": [
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            	    "featureType": "administrative",
	            	    "stylers": [
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            	    "featureType": "administrative"  }
	            	];

	// Create a new StyledMapType object, passing it the array of styles,
	// as well as the name to be displayed on the map type control.
	var styledMap = new google.maps.StyledMapType(styles, {name: "Styled Map"});
	jQuery(selector).show();

	// Create a map object, and include the MapTypeId to add
	// to the map type control.
	
	/*var coords = new google.maps.LatLng(lat, long);*/
	var center = new google.maps.LatLng(45, 11.5);
	
	var mapOptions = {
			zoom: 2,
			center: center,
			mapTypeControlOptions:
			{
				mapTypeIds: [google.maps.MapTypeId.ROADMAP, 'map_style']
			},
			panControl: false,
		    zoomControl: true,
		    scaleControl: false,
		    mapTypeControl: false,
		    streetViewControl: false,
		    overviewMapControl: false,
		    scrollwheel: true,
		    disableDoubleClickZoom: false,
		    draggable: false
	};
	
	var places = [];
	
	jQuery(selector + ' > div').each
	(
		function ()
		{
			places.push(eval('(' + jQuery(this).html() + ')'));
		}
	);
	
	var map = new google.maps.Map(jQuery(selector)[0], mapOptions);
	jQuery(selector).parent().prepend('<div class="map-mask" style="opacity: 0.99;"></div>');
	/*jQuery(selector).css({opacity: 0});*/
	var infoWindow = new google.maps.InfoWindow({disableAutoPan: true});
	var loadWait = google.maps.event.addListener(map, 'tilesloaded',
		function()
		{
			//showNextMarker(map, places, 600, selector);
			jQuery(selector).after(jQuery(selector + ' > div:first-child > div:last-child').addClass('zoomer')[0]);
			jQuery(selector).after(jQuery(selector + ' > div:first-child > div:first-child + div').addClass('google-link')[0]);
			jQuery(selector).after(jQuery(selector + ' > div:first-child > div:first-child + div').addClass('map-data')[0]);
			google.maps.event.removeListener(loadWait);
			jQuery(selector).parent().find('.map-mask')./*animate({opacity: .95}, 'slow',
				//function ()
				//{
					//google.maps.event.trigger(map, "projection_changed");
					//map.draw();
					
					jQuery(selector).parent().find('.map-mask').*/fadeOut(2000, function() { jQuery(this).remove(); });
				//}
			showNextMarker(map, places, 600, selector, infoWindow);
			//);
			/*jQuery(selector + ' img').hide();
			jQuery(selector).css({opacity: 1});
			jQuery(selector + ' img').fadeIn();*/
		}
	);
	google.maps.event.addListener(map, 'zoom_changed',
		function ()
		{
			if (map.getZoom() > 2)
			{
				jQuery(selector).css({width: '1600px'});
				google.maps.event.trigger(map, "resize");
				map.setOptions({draggable: true});
			}
 			else
			{
 				if (this.getZoom() < 1)
 				{
 					this.setZoom(1);
 				}
				//jQuery(selector).css({width: (map.getZoom() == 2 ? '1028px' : map.getZoom() == 1 ? '510px' : '260px')});
				jQuery(selector).css({width: (map.getZoom() == 2 ? '1028px' : '510px')});
				google.maps.event.trigger(map, "resize");
				map.setCenter(center);
				map.setOptions({draggable: false});
			}
		}
	);
	google.maps.event.addListener(map, 'click',
		function ()
		{
			infoWindow.close();
		}
	);
	google.maps.event.addListener(map, 'center_changed',
		function ()
		{
			if (map.getZoom() < 3 && !map.getCenter().equals(center))
			{
				map.setCenter(center);
				//iFiredIt = true;
				//return false;
			}
		}
	);
	
	var t, l = (new Date()).getTime();
	
	//jQuery(window).mousemove(function() { console.log(event); });

	jQuery(window).scroll(function(event){
	    var now = (new Date()).getTime();
    	var mx, my;

	    if (now - l > 400)
	    {
	    	mx = event.pageX;
	    	my = event.pageY;
	        /*jQuery(this).trigger('scrollStart');*/
	    	map.setOptions({scrollwheel: false});
	        l = now;
	    }
	    
	    clearTimeout(t);
	    t = setTimeout(function(){
	        //jQuery(window).trigger('scrollEnd');
	    	
	    	jQuery(window).mousemove(
	    		function (event)
	    		{
	    			if (mx != event.pageX || my != event.pageY)
	    			{
	    				map.setOptions({scrollwheel: true});
	    				//console.log('yup');
	    				jQuery(window).unbind('mousemove');
	    			}
	    		}
	    	);
	    }, 300);
	});

  	//Associate the styled map with the MapTypeId and set it to display.
	map.mapTypes.set('map_style', styledMap);
	map.setMapTypeId('map_style');
}

function showNextMarker(map, places, delay, selector, infoWindow)
{
	if (places && places.length > 0)
	{
		var place = null;
		if (jQuery(selector).is(':inView'))
		{
			place = places.shift();
		}
		
		setTimeout
		(
			function ()
			{
				if (place)
				{
					var marker = new google.maps.Marker
					(
						{
							position: new google.maps.LatLng(place.coordinates[0], place.coordinates[1]),
							map: map,
							title: place.title,
							animation:google.maps.Animation.DROP,
							icon: '/sites/all/themes/bike_bike/images/marker.png' 
						}
					);
					//var infowindow = new google.maps.InfoWindow({});
					google.maps.event.addListener(marker, 'click',
						function()
						{
							//console.log(place);
							var content = '<div class="infoWindow"><h3><a href="' + place.link + '" title="' + place.title + '">' + place.title + '</a></h3>' + place.logo + '<p><ul class="address"><li class="street">' + place.address + '</li><li class="city">' + place.city + (place.province && place.province.length > 0 ? ', ' + place.province : '') + '</li><li class="country">' + place.country + '</li></ul></p></div>';
							infoWindow.setContent(content);//place.title);
							infoWindow.open(map, marker);
							/*if (map.getZoom() < 3)
							{
								map.setCenter(new google.maps.LatLng(45, 11.5));
							}*/
						}
					);
				}
				
				showNextMarker(map, places, delay, selector, infoWindow);
			},
			delay
		);
	}
}

function initializeOrgMap(lat, long)
{
	// Create an array of styles.
	var styles = [
	              {
	            	    "featureType": "water",
	            	    "stylers": [
	            	      { "visibility": "on" },
	            	      { "hue": "#000000" },
	            	      { "color": "#8A9BAB" }
	            	      //{ }
	            	    ]
	            	  },{
	            	    "featureType": "landscape.natural.terrain",
	            	    "stylers": [
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            		    "featureType": "landscape",
	            		    "stylers": [
	            		      { "visibility": "simplified" },
	            		      { "color": "#EEEEEE" }
	            		    ]
	            	  },{
	            	    "featureType": "administrative.country",
	            	    "elementType": "labels",
	            	    "stylers": [
	            	      { "hue": "#1900ff" },
	            	      { "saturation": -11 },
	            	      { "color": "#808080" },
	            	      { "weight": 0.1 },
	            	      { "lightness": 22 },
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            	    "featureType": "poi.park",
	            	    "stylers": [
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            		    "featureType": "road",
	            		    "stylers": [
	            		      { "visibility": "simplified" },
	            		      { "color": "#9BAB8A" },
	            		      { "lightness": 50 },
	            		      { "weight": 0.5 }
	            		    ]
	            		  }, {
	            			    "featureType": "road",
	            			    "elementType": "labels",
	            			    "stylers": [
	            			      { "visibility": "off" }
	            			    ]
	            			  }/*,{
	            	    "featureType": "road",
	            	    "stylers": [
	            	      { "visibility": "off" }
	            	    ]
	            	  }/*,{
	            	    "featureType": "administrative",
	            	    "stylers": [
	            	      { "visibility": "off" }
	            	    ]
	            	  },{
	            	    "featureType": "administrative"  }*/
	            	];

	// Create a new StyledMapType object, passing it the array of styles,
	// as well as the name to be displayed on the map type control.
	var styledMap = new google.maps.StyledMapType(styles, {name: "Styled Map"});
	var center = new google.maps.LatLng(lat, long);
	var mapOptions = {
			zoom: 11,
			center: center,
			mapTypeControlOptions:
			{
				mapTypeIds: [google.maps.MapTypeId.ROADMAP, 'map_style']
			},
			panControl: false,
		    zoomControl: true,
		    scaleControl: false,
		    mapTypeControl: false,
		    streetViewControl: false,
		    overviewMapControl: false,
		    scrollwheel: true,
		    disableDoubleClickZoom: false,
		    draggable: false
	};
	var map = new google.maps.Map(jQuery('#org-map')[0], mapOptions);
	map.mapTypes.set('map_style', styledMap);
	map.setMapTypeId('map_style');
	var marker = new google.maps.Marker
	(
		{
			position: center,
			map: map,
			/*title: place.title,
			animation:google.maps.Animation.DROP,*/
			icon: '/sites/all/themes/bike_bike/images/marker.png' 
		}
	);

}
