<?php
function sources_fetch_links($site, $hosts) {
	dout("Processing site: " . $site['name']);

	$result = array();

	$ch = curl_init();
	curl_setopt($ch, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.78 Safari/535.11");
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
	curl_setopt($ch, CURLOPT_REFERER, $site['login']);
	curl_setopt($ch, CURLOPT_HEADER, FALSE);
	curl_setopt($ch, CURLOPT_FOLLOWLOCATION, FALSE);
	curl_setopt($ch, CURLOPT_COOKIESESSION, TRUE);
	curl_setopt($ch, CURLOPT_COOKIEJAR, "cookiejar.txt");
	curl_setopt($ch, CURLOPT_COOKIEFILE, "cookiejar.txt");

	curl_setopt($ch, CURLOPT_URL, $site['login']);
	curl_setopt($ch, CURLOPT_POST, TRUE);
	$post = str_replace(array('__USER__', '__PASS__'), array($site['user'], $site['pass']), $site['login_post']);
	curl_setopt($ch, CURLOPT_POSTFIELDS, $post);

	$transfer = curl_exec($ch);

	foreach ($site['threads'] as $thread) {
		dout("Crawling thread: " . $thread);
		curl_setopt($ch, CURLOPT_URL, $thread['url']);
		curl_setopt($ch, CURLOPT_HTTPGET, TRUE);

		$transfer = curl_exec($ch);

		$links = array();
		preg_match_all('/(https?)(:|&#58;)\/\/[-A-Z0-9+&@#\/%?=~_|!:,.;]*[A-Z0-9+&@#\/%=~_|]/is', $transfer, $links);
		$links = $links[0];

		foreach ($links as $idx => &$link) {
			$link = str_replace('&#58;', ':', $link);
			$url = parse_url($link);
			if (in_array($url['host'], $hosts)) {
				$result[] = $link;
			}
		}
		dout("... found " . count($result) . " links.");
	}

	curl_close($ch);

	return $result;
}
