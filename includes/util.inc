<?php

function dout($text) {
	global $CONFIG;
	if($CONFIG['verbose']) {
		echo $text . "\n";
		flush();		
		ob_flush();
	}
	return $text;
		
}
	
function dlog($text) {
	global $CONFIG;
	$log = file($CONFIG['log_file']);
	array_unshift($log, date("[F j, Y, H:i:s] ", time()) . $text . "\n");
	$log = array_slice($log, 0, $CONFIG['log_limit']);
	file_put_contents($CONFIG['log_file'], $log);
}
	