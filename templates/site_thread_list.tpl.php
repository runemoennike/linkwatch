<ul>
<?php foreach($threads as $thread) :
	if(!is_array($thread)) continue;?>
	<li>
		<i><?php echo strlen($thread['title']) > 0 ? $thread['title'] : $thread['url']; ?></i>
		(<?php echo interface_link('Go', $thread['url']); ?>) 
		<?php if(isset($LINK_CACHE['_threads'][$thread['url']]) && $LINK_CACHE['_threads'][$thread['url']]['last_scan'] > 0) : ?>
			(<?php echo count($LINK_CACHE['_threads'][$thread['url']]['links']); ?> valid links in total, 
			last scanned <?php echo date("F j, Y, H:i", $LINK_CACHE['_threads'][$thread['url']]['last_scan']); ?>)
		<?php else : ?>
			Not yet scanned.
		<?php endif; ?>
	</li>
<?php endforeach; ?>
</ul>