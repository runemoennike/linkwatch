<h2>Confirm delete thread: <i><?php echo $thread_title; ?></i></h2>

From site <i><?php echo $site_name ?></i>, url: <i><?php echo $thread_url; ?></i>

<p>When deleted, all previously crawled links from this thread will be forgotten. Thus they will be readded to JD if the thread is readded.</p>

<form action="<?php echo interface_url(array('page' => 'threadmgmt', 'action' => 'delete_submit')); ?>" method="post">
<input type="hidden" name="site_name" value="<?php echo $site_name; ?>" />
<input type="hidden" name="thread_url" value="<?php echo $thread_url; ?>" />
<input type="hidden" name="thread_title" value="<?php echo $thread_title; ?>" />
<input type="checkbox" name="leave_cache" value="yes" /> Don't forget crawled links from this thread<br/>

<input type="submit" value="Delete" />
</form>

<p><?php echo interface_link('Return to Overview', array('page' => 'overview')); ?></p>