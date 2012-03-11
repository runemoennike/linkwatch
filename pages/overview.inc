<?php

function overview_page() {
	interface_set_title("Overview");
	$vars = array();
	return templates_exec("overview", $vars);
}
	