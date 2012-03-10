<?php 

include "config.inc";
include "jdremote.api.inc";
include "sources.api.inc";

jdremote_init();

$site = array(
	'login' => "http://www.warez-bb.org/login.php",
	'login_post' => 'login=Log+in&username=__USER__&password=__PASS__',
	'user' => 'colamad',
	'pass' => '12345678',
	'threads' => array(
		array('url' => 'http://www.warez-bb.org/viewtopic.php?t=12225624'),
	),
);

$links = sources_fetch_links($site);

foreach($links as $link) {
	jdremote_download($link);
}

jdremote_close();
