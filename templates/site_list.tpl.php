<ul>
<?php foreach($SITES as $site) : 
	if(!is_array($site)) continue;?>
	<li>
		<?php echo ucwords($site['name']) ?>
		(<?php echo interface_link('Add thread', array('page' => 'threadmgmt', 'action' => 'add', 'site' => $site['name'])); ?>) 
		<?php echo templates_exec('site_thread_list', array('threads' => $site['threads'], 'site' => $site)); ?>
	</li>
<?php endforeach; ?>
</ul>