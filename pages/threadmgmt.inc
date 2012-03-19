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

function threadmgmt_delete_page() {
	global $HOSTS, $SITES;
	interface_set_title("Confirm Thread Delete");
	$vars = array();
	$vars['site_name'] = $_GET['site_name'];
	$vars['thread_url'] = $_GET['thread_url'];
	$vars['thread_title'] = $_GET['thread_title'];
		
	return templates_exec("thread_delete_confirm", $vars);	
}

function threadmgmt_delete_submit_page() {
	global $HOSTS, $SITES, $LINK_CACHE;
	interface_set_title("Thread Deleted");
	$vars = array();
	$vars['site_name'] = $_POST['site_name'];
	$vars['thread_url'] = $_POST['thread_url'];
	$vars['thread_title'] = $_POST['thread_title'];
	$vars['leave_cache'] = $_POST['leave_cache'];
	
	$site_idx = datafile_find($SITES, 'name', $vars['site_name']);
	$thread_idx = datafile_find($SITES[$site_idx]['threads'], 'url', $vars['thread_url']);
	unset($SITES[$site_idx]['threads'][$thread_idx]);
	
	if($_POST['leave_cache'] != 'yes') {
		foreach($LINK_CACHE['_threads'][$vars['thread_url']]['links'] as $url) {
			unset($LINK_CACHE[$url]);
		}
		unset($LINK_CACHE['_threads'][$vars['thread_url']]);
	}
	

	return templates_exec("thread_delete_status", $vars);	
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
	