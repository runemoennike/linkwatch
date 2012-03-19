<?php

function hostmgmt_page() {
	interface_set_title("Overview");
	$vars = array();
	return templates_exec("overview", $vars);
}

function hostmgmt_add_page() {
	interface_set_title("Add Accepted Host");
	$vars = array();
	return templates_exec("host_add_form", $vars);
}

function hostmgmt_add_submit_page() {
	global $HOSTS;
	
	interface_set_title("Accepted Host Added");
	
	$host = array(
		'pattern' => $_POST['pattern'],
	);
	$HOSTS[] = $host;
	
	$vars = array();
	$vars['host'] = $host;
	return templates_exec('host_add_submit_status', $vars); 
}
	
function hostmgmt_delete_page() {
	global $HOSTS;
	
	interface_set_title("Accepted Host Removed");
	
	$idx = datafile_find($HOSTS, 'pattern', $_GET['host']);
	unset($HOSTS[$idx]);
	
	$vars = array();
	$vars['host'] = $_GET['host'];
	return templates_exec('host_remove_submit_status', $vars); 
}
	