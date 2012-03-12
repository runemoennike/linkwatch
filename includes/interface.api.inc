<?php

function interface_set_default($page) {
	global $INTERFACE;
	
	$INTERFACE['default_page'] = $page;
}

function interface_set_baseurl($baseurl) {
	global $INTERFACE;
	
	$INTERFACE['baseurl'] = $baseurl;
}

function interface_exec($page) {
	global $INTERFACE;
	
	$action_page = preg_replace('/[^a-z]/i', '', strtolower($_GET['page']));
	
	if(! is_file('pages/' . $action_page . '.inc')) {
		$action_page = $INTERFACE['default_page'];
	}
	
	include 'pages/' . $action_page . '.inc';
	
	$vars = array();
	$vars['content'] = call_user_func($action_page . '_page');
	$vars['title'] = $INTERFACE['title'];
	
	echo templates_exec("page", $vars);
}

function interface_set_title($title) {
	global $INTERFACE;
	
	$INTERFACE['title'] = $title;
}

function interface_link($title, $opts) {
	global $INTERFACE; 
	
	$query_parts = array();
	foreach($opts as $key => $val) {
		$query_parts[] = $key . '=' . $val;
	}
	echo '<a href="' . $INTERFACE['baseurl'] . '?' . implode('&', $query_parts) . '">' . $title . '</a>';
}
	