<?php 

include "includes/config.inc";
include "includes/jdremote.api.inc";
include "includes/sources.api.inc";
include "includes/datafile.api.inc";

jdremote_init();

$sites = datafile_read('data/sites');

die();

foreach($sites as $site) {
	$links = sources_fetch_links($site);

	foreach($links as $link) {
		jdremote_download($link);
	}
}

jdremote_close();
