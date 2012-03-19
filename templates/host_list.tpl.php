<ul>
<?php foreach($HOSTS as $host) :
	if(!is_array($host)) continue; ?>
	<li><?php echo $host['pattern']?> (<?php echo interface_link('Remove', array('page' => 'hostmgmt', 'action' => 'delete', 'host' => $host['pattern'])); ?>)</li>
<?php endforeach; ?>
</ul>