<?php

include "includes/config.inc";
include "includes/util.inc";
include "includes/jdremote.api.inc";
include "includes/sources.api.inc";
include "includes/datafile.api.inc";

jdremote_init();

dout("Loading data...");
$sites = datafile_read('data/sites');
$hosts = datafile_read('data/hosts');

dout("Loading link cache...");
if(is_readable('data/cache')) {
	$link_cache = unserialize(file_get_contents('data/cache'));
} else {
	$link_cache = array();
}

foreach ($sites as &$site) {
	if(! is_array($site)) continue;
	
	$links = sources_fetch_links($site, $hosts);
	$skipped_count = 0;
	$new_count = 0;
	$new_fail_count = 0;
	
	dout("Site crawl resulted in " . count($links) . " total links.");

	foreach ($links as $link) {
		if (!isset($link_cache[$link])) {
			$link_cache[$link] = array('added_time' => time(), 'downloaded' => false);
		}

		if (!$link_cache[$link]['downloaded']) {
			$new_count ++;
			dout("Sending link to download: " . $link);
			if (jdremote_download($link)) {
				$link_cache[$link]['downloaded'] = true;
				$link_cache[$link]['downloaded_time'] = time();
			} else {
				$new_fail_count ++;
				dout("... FAILED.");
			}
		} else {
			$skipped_count ++;
		}
	}
	
	dout("Site crawl results: " . $new_count . " new links, of which " . $new_fail_count . " could not be sent to JD. " . $skipped_count . " links where skipped.");
}

dout("Writing link cache...");
file_put_contents('data/cache', serialize($link_cache));

dout("Sending start to JD.");
jdremote_start();

jdremote_close();

dout("FINISHED.");
