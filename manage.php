<?php

include_once "includes/config.inc";
include_once "includes/util.inc";
include_once "includes/jdremote.api.inc";
include_once "includes/sources.api.inc";
include_once "includes/datafile.api.inc";
include_once "includes/templates.api.inc";
include_once "includes/interface.api.inc";

global $SITES, $HOSTS, $LINK_CACHE;

jdremote_init();

$SITES = datafile_read('data/sites');
$HOSTS = datafile_read('data/hosts');

if(is_readable('data/cache')) {
	$LINK_CACHE = unserialize(file_get_contents('data/cache'));
} else {
	$LINK_CACHE = array();
}

interface_set_baseurl($_SERVER['PHP_SELF']);
interface_set_default("overview");
interface_exec($_GET['action']);