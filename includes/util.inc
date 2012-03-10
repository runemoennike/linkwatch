<?php

function dout($text) {
	global $CONFIG;
	if($CONFIG['verbose']) {
		echo $text . "\n";
		flush();		
		ob_flush();
	}
}
	