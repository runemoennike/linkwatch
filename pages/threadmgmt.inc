<?php

function threadmgmt_page() {
	interface_set_title("Overview");
	$vars = array();
	return templates_exec("overview", $vars);
}

function threadmgmt_add_page() {
	interface_set_title("Add Thread");
	$vars = array();
	$vars['site_name'] = $_GET['site'];
	return templates_exec("thread_add", $vars);
}

function threadmgmt_add_preview_page() {
	global $HOSTS, $SITES;
	interface_set_title("Add Thread (preview)");
	$vars = array();
	$vars['site_name'] = $_POST['site_name'];
	$vars['thread_url'] = $_POST['thread_url'];
	
	$site = $SITES[datafile_find($SITES, 'name', $vars['site_name'])];
	$site['threads'] = array(array('url' => $vars['thread_url']));
	
	$vars['links'] = sources_fetch_links($site, $HOSTS);
	return templates_exec("thread_add_preview", $vars);	
}
	