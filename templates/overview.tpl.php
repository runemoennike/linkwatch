<h2>Stats</h2>
<ul>
	<li>JDRemote: <?php echo (jdremote_alive() ? 'Alive' : 'Unavailable'); ?></li>
	<li>Host: <?php echo $CONFIG['jdremote'];?></li>
	<li>Total files in JD: <?php echo jdremote_get_count_all(); ?></li>
	<li>Currently downloading : <?php echo jdremote_get_count_current(); ?></li>
	<li>Finished downloads: <?php echo jdremote_get_count_finished(); ?></li>
</ul>

<h2>Watching</h2>
<ul>
<?php foreach($SITES as $site) : 
	if(!is_array($site)) continue;?>
	<li>
		<?php echo ucwords($site['name']) ?>
		(<?php echo interface_link('Add thread', array('page' => 'threadmgmt', 'action' => 'add', 'site' => $site['name'])); ?>) 
		<ul>
		<?php foreach($site['threads'] as $thread) :
			if(!is_array($thread)) continue;?>
			<li>
				<?php echo $thread['url']; ?> 
				(<?php echo count($LINK_CACHE['_threads'][$thread['url']]['links']); ?> valid links in total, 
				last scanned <?php echo date("F j, Y, H:i", $LINK_CACHE['_threads'][$thread['url']]['last_scan']); ?>)
			</li>
		<?php endforeach; ?>
		</ul>
	</li>
<?php endforeach; ?>
</ul>

<h2>Last crawl output</h2>
<pre><?php echo file_get_contents('data/log') ?>
</pre>