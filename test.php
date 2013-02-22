<?php

$to      = 'goodgodwin@hotmail.com';

// subject
$subject = 'Birthday Reminders for August';

// message
$message = '
<html>
<head>
  <title>Birthday Reminders for August</title>
</head>
<body>
  <p>Here are the birthdays upcoming in August!</p>
  <table>
    <tr>
      <th>Person</th><th>Day</th><th>Month</th><th>Year</th>
    </tr>
    <tr>
      <td>Joe</td><td>3rd</td><td>August</td><td>1970</td>
    </tr>
    <tr>
      <td>Sally</td><td>17th</td><td>August</td><td>1973</td>
    </tr>
  </table>
</body>
</html>
';

// To send HTML mail, the Content-type header must be set
$headers  = 'MIME-Version: 1.0' . "\r\n";
$headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";

// Additional headers
$headers .= 'To: Mary <goodgodwin@hotmail.com>' . "\r\n";
$headers .= 'From: Birthday Reminder <goodgodwin@hotmail.com>' . "\r\n";

// Mail it
print 'TESTING: '.(mail($to, $subject, $message, $headers) ? 'pass' : 'fail');
/*$x = "<ul><li>Romelia - $14.99/220 g</li>
<li>Juliette - $12.99/220 g</li>
<li>Saint Jo - $14.99/270 g</li>
<li>Basil - $10.49/150 g</li>
<li>Garlic - $10.49/150 g</li>
<li>Flower - $10.49/150 g</li>
</ul>";

print preg_replace_callback('/<ul>\s*((<li>\s*((?:(?!<\/li>).)+?)(  +|\t+|\s+\-\s+)((?:(?!<\/li>).)+?)\s*<\/li>\s*){2,})\s*<\/ul>/s',
	create_function(
		'$matches',
		'print_r($matches); return \'<table>\'.preg_replace(\'/<li>\s*((?:(?!<\/li>).)+?)(  +|\t+|\s+\-\s+)((?:(?!<\/li>).)+?)\s*<\/li>/s\', \'<tr><th>$1</th><td>$3</td></tr>\', $matches[0]).\'</table><br />\';'
	), $x);

/*$x = array("Grand Opening Produce specials on Saturday, Feb. 9 - check out the sweet deals Produce Manager Tamara has planned - see you there!", "Heritage Harvest Farm specializes in high quality heritage grains in Alberta - you'll find their organic whole grain Red Fife Flour in Sunnyside Natural Market's bulk section...this weekend, as part of our Grand Opening, 2 kg & 3 kg bags will be available as well. Learn more about this unique farm and the history of Red Fife wheat at",
"<p>Join us on Sat. Feb. 9 for the Grand Opening of the newly-expanded <a href=\"http://www.facebook.com/201606259861952\">Sunnyside Natural Market</a> &amp; <a href=\"http://www.facebook.com/204889012862927\">Sidewalk Citizen Bakery</a> - the blender bike will be at the store from 9-5 - create your own people-powered smoothie! Lots more to look forward to...a magician, juggling lessons, coffee and Ice Cream Anarchy samples and lots of door prizes &amp; giveaways. Come celebrate with your neighbourhood market!</p>",
"Over the past couple of years, Sidewalk Citizen has amassed a huge following for its fresh baking. Arrive at the Manchester bakery (5524 1A Street SW) on a Saturday morning and you’ll likely be looking at a lineup that spills out the door as regulars wait for their scones and croissants. Now,...",
"What a novel idea (pun intended)!<br />A small-town library in Colorado is lending more than just books. Patrons can now check out seeds and farm them. After the crops are harvested, the patrons return the seeds from the best fruits and vegetables so the library can lend them out to others.",
"On Saturday, Feb. 2 @ 10:00 am at the store, Sidewalk Citizen Bakery hosts Chef Cindy Lazarenko - half of the duo behind the artisan Edmonton-based company, On Our Table. Come sample some of her delectable creations...Olive & Prune Tapenade and Chicken Liver Pate on Sidewalk Citizen baguettes and served on their gorgeous boards. ",
"New at Sunnyside Natural Market - Vij's at Home - ready-made and healthy Indian meals from Vancouver's well-known and loved contemporary Indian cuisine restaurant...suitable for vegans and dairy and gluten reduced diets...now in our frozen foods section.",
"A good, definitive answer to a question we hear often!<br />Having trouble telling one from the other in the dairy aisle? Leslie Beck breaks down the differences between the two",
"Sidewalk Citizen Bakery - baking some of the very best bread in town...now, we knew that all along! Stop by and pick up a loaf (or two) today.<br />For those still enjoying a chewy, rustic loaf, here are just a few of the best bread bakeries in Calgary — some new and some that have been baking and breaking bread for generations.",
"New at Sunnyside Natural Market - Salt Spring Island Cheese Company - specializing in handmade goat and sheep cheeses, and especially known for their chèvres...beautiful varieties include",
"Staying home with the flu bug? Here are some home remedies to put you back on the road to recovery...<br />Fight the flu and recover faster with natural flu home remedies and a soothing chicken noodle soup recipe",
"Good Morning, friends! Just a reminder that we will be closing at 6:00 pm today and re-opening at 9:00 am on Sat. Jan. 19th - over the next five days we'll be finishing up renovation construction and moving in to our new space with Sidewalk Citizen Bakery...check back this week for updates - and stop by today to stock up on your groceries for the week!",
"Reno Sale! Check out our super sweet deals on clearance products - 50 - 70% discounts to be found on select items on everything from Yerba Mate to artisanal granola to yummy juice concentrates to health and beauty care...must be seen to be believed!",
"Kale Sale Alert! Include this superfood in your New Year's detox - the Queen of Greens is high in iron, calcium, vitamins A &amp; K and is filled with powerful antioxidants, as well as having great anti-inflammatory properties.<br /><ul><li>Black Kale @ $2.79 ea (reg. $3.49)</li><li>Green Kale @ $3.79 ea</li><li>Purple Kale @ $3.79 ea</li></ul><br /><br />Discover a whole new kale that is anything but bitter and overcooked. The leafy winter green is great in soups, salads and snacks like this kale chip recipe, and more.<a class=\"linkshare\" href=\"http://www.organicauthority.com/eco-chic-table/quick-and-easy-recipe-ideas-for-kale.html\" target=\"_blank\">Read full story at <strong>www.organicauthority.com</strong></a>",
"Look for mention of Sidewalk Citizen Bakery's artisanal baking in John Gilchrist's top 10 restaurant trends of the year...<br />2012 was a great year for restaurant openings in Calgary with everything from Peruvian chicken roasters",
);


foreach ($x as $body)
{
	//$body = trim(preg_replace('/<br\s*\/? >/', "\n", $body));
	$body = preg_replace('/<\/?p>/', '', $body);
	$delimiters =
		array
		(
			'/^(.)(\s*<br\s*\/?>\s*)+(.)/' => array(128, -1, -1, null),
			'/^([!|\?])(\s+)(.)/' => array(50, -1, -1, null),
			'/^(\d)(\s+\-\s+)(\d)/' => array(128, -1, -1, null, false),
			'/^(\w)(\s+\-\s+)(\w)/' => array(128, -1, -1, null),
			'/^(>)(\s*\-\s+)(\w)/' => array(128, -1, -1, null),
			'/^([^A-Z]\w\w)(\.\s+)(.)/' => array(100, -1, -1, null),
			'/^([!|\?])(\s+)(.)/' => array(100, -1, -1, null),
		);
	$char_count = 0;
	$total_char_count = 0;
	$in_tag = false;
	$b = $body;
	for ($total_char_count = 0; $total_char_count < strlen($body) && $char_count < 150; $total_char_count++)
	{
		$char = $b[0];
		if ($in_tag)
		{
			if ($char == '>')
			{
				$in_tag = false;
			}
		}
		else
		{
			if ($char == '<')
			{
				$in_tag = true;
			}
		}
		if (!$in_tag)
		{
			foreach ($delimiters as $delimiter => $info)
			{
				if ($info[1] < 0 && preg_match($delimiter, $b, $match))
				{
					$delimiters[$delimiter][1] = $char_count;
					$delimiters[$delimiter][2] = $total_char_count;
					$delimiters[$delimiter][3] = $match;
				}
			}
			$char_count++;
		}
		$b = substr($b, 1);
	}
	$body = preg_replace('/\n/', '<br />', $body);
	$found = false;
	foreach ($delimiters as $delimiter => $info)
	{
		if (!$found && $info[1] >= 0 && $info[1] <= $info[0] && (!isset($info[4]) || $info[4] !== false))
		{
			$title = trim(strip_tags(substr($body, 0, $info[2] + strlen($info[3][1]) + 1)));
			$body = substr($body, $info[2] + strlen($info[3][1]) + strlen($info[3][2]));
			$body = '<p>'.preg_replace('/(<br\s*\/?>)+/', '</p><p>', $body).'<p>';
			$body[0] = strtoupper($body[0]);
			print '<h3>'.$title.'</h3><p>'.$body.'</p>';
			$found = true;
		}
	}
	if (!$found)
	{
		print '<h3>FAIL!</h3><p>'.$body.'</p>';
	}
}*/
?>
