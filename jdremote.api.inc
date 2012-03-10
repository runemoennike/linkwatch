<?php
function jdremote_init() {
	global $JDREMOTE;
	
	$JDREMOTE['ch'] = curl_init();
	curl_setopt($JDREMOTE['ch'], CURLOPT_RETURNTRANSFER, TRUE);
}

function jdremote_close() {
	global $JDREMOTE;
	
	curl_close($JDREMOTE['ch']);
}

function jdremote_download($link) {
	global $CONFIG, $JDREMOTE;
	
	curl_setopt($JDREMOTE['ch'], CURLOPT_URL, $CONFIG['jdremote'] . 'action/add/links/grabber0/start1/' . $link);
	curl_exec($JDREMOTE['ch']);
}
