<?php

if(file_exists('data/installed')) {
	header('Location: manage.php');
} else {
	header('Location: install.php');
}
