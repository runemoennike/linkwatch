<?php

function sitemgmt_page() {
	interface_set_title("Overview");
	$vars = array();
	return templates_exec("overview", $vars);
}

function sitemgmt_add_page() {
	interface_set_title("Add Thread");
	$vars = array();
	return templates_exec("thread_add", $vars);
}
	