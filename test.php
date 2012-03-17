<?php

include_once "includes/config.inc";
include_once "includes/util.inc";
include_once "includes/jdremote.api.inc";
include_once "includes/sources.api.inc";
include_once "includes/datafile.api.inc";

$sites = datafile_read('data/sites');
$hosts = datafile_read('data/hosts');

datafile_write($sites);
datafile_write($hosts);