jQuery.extend(jQuery.expr[':'],{
    inView: function(a) {
        var st = (document.documentElement.scrollTop || document.body.scrollTop),
            ot = jQuery(a).offset().top + (jQuery(a).height() / 2.0),
            wh = (window.innerHeight && window.innerHeight < jQuery(window).height()) ? window.innerHeight : jQuery(window).height();
        return ot > st && ot < (st + wh);
    }
});

(function ($) {

	  Drupal.behaviors.bikebike = {
	    attach: function (context, settings) {
	    	completeAutocomplete('.field-widget-entityreference-autocomplete input.form-autocomplete[value!=""]');
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
	if (jQuery(element).hasParent('.field-multiple-table'))//parent().parent().parent().parent().parent().parent().hasClass('field-multiple-table'))
	{
		jQuery(element).hide();
		if (jQuery(element).parent().find('a.autocomplete-remove').length < 1)
		{
			jQuery(element).before('<a href="javascript:void(0)" class="autocomplete-remove" title="Remove this one">Remove</a>');
			jQuery(element).parent().find('a.autocomplete-remove').click(
				function ()
				{
					jQuery(this).parent().find('input.form-autocomplete').val('').show().trigger('change');
					/*if (jQuery(this).closest('tbody').find('tr').length < 1) { console.log('poo'); }*/
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
	}
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
		
		//console.log(jQuery('input[type="file"] + input[type="submit"]').length);
		/*jQuery('input[type="file"] + input[type="submit"]').each
		(
			function ()
			{
				jQuery(this).after('<input type="button" value="Upload File..." class="upload-button" />');
			}
		);
		
		jQuery('input.upload-button').click
		(
			function (e)
			{
				//alert('pooo!');
				//console.log('clicked');
				//console.log('[ ' + file.val() + ' ]');
				var button = jQuery(this).prev();
				var file = button.prev();
				//if (!file.val())
				//{
					file.click();
					//button.mousedown();
					//e.preventDefault();
				//}
				//else
				//{
					//button.submit();
					//button.mousedown();
				//}
			}
		);*/
	}
);

function initializeMap(selector)
{
	// Create an array of styles.
	console.log('init');
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
							icon: '/sites/all/themes/bikebike/images/marker.png' 
						}
					);
					//var infowindow = new google.maps.InfoWindow({});
					google.maps.event.addListener(marker, 'click',
						function()
						{
							//console.log(place);
							var content = '<div class="infoWindow"><h3>' + place.link + '</h3>' + place.logo + '<p><ul class="address"><li class="street">' + place.address + '</li><li class="city">' + place.city + (place.province && place.province.length > 0 ? ', ' + place.province : '') + '</li><li class="country">' + place.country + '</li></ul></p></div>';
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
			icon: '/sites/all/themes/bikebike/images/marker.png' 
		}
	);

}
