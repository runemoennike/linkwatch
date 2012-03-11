<?php

function templates_exec($template, $vars) {
	ob_start();
	ob_implicit_flush(false);
	
	foreach($vars as $key => $val) {
		$$key = $val;	
	}
	
	foreach($GLOBALS as $key => $val) {
		$$key = $val;	
	}

	require('templates/' . $template . '.tpl.php');
	
	$out = ob_get_contents();
	ob_end_clean();
	
	return $out;
}