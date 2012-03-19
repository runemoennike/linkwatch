<h2>Stats</h2>
<?php echo templates_exec('stats_simple'); ?>

<h2>Sites being Watched</h2>
<?php echo interface_link('Add Site', array('page' => 'sitemgmt', 'action' => 'add')); ?>
<?php echo templates_exec('site_list', array()) ?>

<h2>Last crawl output</h2>
<?php echo interface_link('Crawl Now', 'crawl.php') ?>
<?php echo templates_exec('log_output'); ?>

<h2>Configuration</h2>

<h3>Accepted Hosts</h3>
<?php echo interface_link('Add Host', array('page' => 'hostmgmt', 'action' => 'add')); ?>
<?php echo templates_exec('host_list'); ?>