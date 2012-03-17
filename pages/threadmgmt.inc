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
	$vars['thread_title'] = $site['threads'][0]['title'];
	return templates_exec("thread_add_preview", $vars);	
}

function threadmgmt_thread_add_submit_page() {
	global $HOSTS, $SITES;
	interface_set_title("Thread Added");
	
	$vars['site_name'] = $_POST['site_name'];
	$vars['thread_url'] = $_POST['thread_url'];
	$vars['thread_title'] = $_POST['thread_title'];
	
	$SITES[datafile_find($SITES, 'name', $vars['site_name'])]['threads'][] = array('url' => $vars['thread_url'], 'title' => $vars['thread_title']);
	
	if(is_array($_POST['skip'])) {
		foreach($_POST['skip'] as $url) {
			$link_cache[$url]['downloaded'] = true;
		}
	}
	
	return templates_exec('thread_add_submit_status', $vars);
}
	