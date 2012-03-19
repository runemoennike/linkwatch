<h2>Deleted: <i><?php echo $thread_title; ?></i></h2>

From site <i><?php echo $site_name ?></i>

<p>
	<?php if($leave_cache == 'yes') : ?>
		Links crawled from this thread were not forgotten.
	<?php else : ?>
		Links crawled from this thread were forgotten, and will be readded if the thread is readded.
	<?php endif; ?>
</p>

<p><?php echo interface_link('Return to Overview', array('page' => 'overview')); ?></p>