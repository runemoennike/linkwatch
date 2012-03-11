<?php
function jdremote_init() {
	global $JDREMOTE;
	
	$JDREMOTE['status'] = true;
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
	$JDREMOTE['status'] = false;
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

function jdremote_get_count_all() {
	return _jdremote_send('get/downloads/allcount', true);
}

function jdremote_get_count_current() {
	return _jdremote_send('get/downloads/currentcount', true);
}

function jdremote_get_count_finished() {
	return _jdremote_send('get/downloads/finishedcount', true);
}

function _jdremote_send($cmd, $return = false) {
	global $CONFIG, $JDREMOTE;
	
	if($JDREMOTE['status']) {
		curl_setopt($JDREMOTE['ch'], CURLOPT_URL, $CONFIG['jdremote'] . $cmd);
		$result = curl_exec($JDREMOTE['ch']);
		return $return ? $result : $result !== FALSE;
	} else {
		return false;
	}	
}
