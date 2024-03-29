<?php

include_once "includes/config.inc";
include_once "includes/util.inc";
include_once "includes/jdremote.api.inc";
include_once "includes/sources.api.inc";
include_once "includes/datafile.api.inc";

if(! jdremote_init()) {
	dlog(dout("JDRemote not reachable. Aborting."));
	die();
}

dout("Loading data...");
$sites = datafile_read('data/sites');
$hosts = datafile_read('data/hosts');

dout("Loading link cache...");
if(is_readable('data/cache')) {
	$link_cache = unserialize(file_get_contents('data/cache'));
} else {
	$link_cache = array('_threads' => array());
}

$link_cache['_threads'] = array();

foreach ($sites as &$site) {
	if(! is_array($site)) continue;
		
	foreach($site['threads'] as $thread) {
		if(! is_array($thread)) continue;
		$link_cache['_threads'][$thread['url']]['last_scan'] = time();
	}
	
	$links = sources_fetch_links($site, $hosts);
	$skipped_count = 0;
	$new_count = 0;
	$new_fail_count = 0;
	
	dout("Site crawl resulted in " . count($links) . " total links.");

	foreach ($links as $link) {
		$thread = $link['thread'];
		$link = $link['link'];
		
		if (!isset($link_cache[$link])) {
			$link_cache[$link] = array('added_time' => time(), 'downloaded' => false);
		}
		
		if(! in_array($link, $link_cache['_threads'][$thread])) {
			$link_cache['_threads'][$thread]['links'][] = $link;
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

if($new_count + $new_fail_count + $skipped_count == 0) {
	dlog(dout("No threads or all threads failed.", true));
} else {
	dlog('New: ' . $new_count . ' Fail: ' . $new_fail_count . ' Skipped: ' . $skipped_count);
}

dout("Writing link cache...");
file_put_contents('data/cache', serialize($link_cache));

dout("Saving site data...");
datafile_write($sites);

dout("Sending start to JD.");
jdremote_start();

jdremote_close();
dout("FINISHED.");
