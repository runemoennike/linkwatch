<ul>
<?php foreach($HOSTS as $host) :
	if(!is_array($host)) continue; ?>
	<li><?php echo $host['pattern']?></li>
<?php endforeach; ?>
</ul>