<?php

touch('data/log');
touch('data/sites');

if(! file_exists('data/hosts')) {
	file_put_contents('data/hosts', "PATTERN\trapidshare.com\n\nPATTERN\twww.rapidshare.com\n");
}

touch('data/installed');

header('Location: manage.php');