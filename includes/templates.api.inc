<?php

function templates_exec($template, $vars) {
	ob_start();
	
	foreach($vars as $key => $val) {
		$$key = $val;	
	}
	
	include('templates/' . $template . '.tpl.php');
	
	return ob_get_clean();
}
	