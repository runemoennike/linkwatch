<?php
function jdremote_init() {
	global $JDREMOTE;
	
	$JDREMOTE['ch'] = curl_init();
	curl_setopt($JDREMOTE['ch'], CURLOPT_RETURNTRANSFER, TRUE);
	
	if(jdremote_alive()) {
		return true;	
	} else {
		jdremote_close();
		return false;
	}
}

function jdremote_close() {
	global $JDREMOTE;
	
	curl_close($JDREMOTE['ch']);
}

function jdremote_download($link) {
	return _jdremote_send('action/add/links/grabber0/start1/' . $link);
}

function jdremote_start() {
	return _jdremote_send('action/start');
}

function jdremote_alive() {
	return _jdremote_send('get/version');
}

function _jdremote_send($cmd) {
	global $CONFIG, $JDREMOTE;
	
	curl_setopt($JDREMOTE['ch'], CURLOPT_URL, $CONFIG['jdremote'] . $cmd);
	$result = curl_exec($JDREMOTE['ch']);
	
	return $result !== FALSE;
}
