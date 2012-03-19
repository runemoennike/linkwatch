<?php

function sitemgmt_page() {
	interface_set_title("Overview");
	$vars = array();
	return templates_exec("overview", $vars);
}

function sitemgmt_add_page() {
	interface_set_title("Add Site");
	$vars = array();
	return templates_exec("site_add", $vars);
}

function sitemgmt_add_submit_page() {
	global $SITES;
	
	interface_set_title("Site Added");
	
	$site = array(
		'name' => preg_replace('/[^a-zA-Z0-9\-_\(\)\/]/', '_', $_POST['name']),
		'login' => $_POST['login'],
		'login_post' => $_POST['login_post'],
		'user' => $_POST['user'],
		'pass' => $_POST['pass'],
		'title_pattern' => $_POST['title_pattern'],
		'title_pattern_idx' => $_POST['title_pattern_idx'],
		'threads' => array(
			'_' => 'data/threads_' . $_POST['name']
		),
	);
	$SITES[] = $site;
	
	$vars = array();
	$vars['site'] = $site;
	return templates_exec('site_add_submit_status', $vars); 
}
	