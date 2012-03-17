<?php

function interface_set_default($page) {
	global $INTERFACE;
	
	$INTERFACE['default_page'] = $page;
}

function interface_set_baseurl($baseurl) {
	global $INTERFACE;
	
	$INTERFACE['baseurl'] = $baseurl;
}

function interface_exec($page, $action = '') {
	global $INTERFACE;
	
	$action_page = preg_replace('/[^a-z]/i', '', strtolower($_GET['page']));
	
	if(! is_file('pages/' . $action_page . '.inc')) {
		$action_page = $INTERFACE['default_page'];
	}
	
	include 'pages/' . $action_page . '.inc';
	
	$vars = array();
	$vars['content'] = call_user_func($action_page . (strlen($action) > 0 ? '_' . $action : '') . '_page');
	$vars['title'] = $INTERFACE['title'];
	
	echo templates_exec("page", $vars);
}

function interface_set_title($title) {
	global $INTERFACE;
	
	$INTERFACE['title'] = $title;
}

function interface_link($title, $opts) {
	echo '<a href="' . interface_url($opts) . '">' . $title . '</a>';
}
	
function interface_url($opts) {
	global $INTERFACE; 
	
	if(is_string($opts)) {
		return $opts;
	}
	
	$query_parts = array();
	foreach($opts as $key => $val) {
		$query_parts[] = $key . '=' . $val;
	}
	return $INTERFACE['baseurl'] . '?' . implode('&', $query_parts);
}
	