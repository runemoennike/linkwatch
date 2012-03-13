Adding thread to site "<?php echo $site_name ?>"

<h2>Preview</h2>

<p>Found the following valid links in the given thread, please select the ones you do NOT wish to download:</p>

<form action="<?php echo interface_url(array('page' => 'threadmgmt', 'action' => 'thread_add_submit')); ?>" method="post">
<input type="hidden" name="site_name" value="<?php echo $site_name; ?>" />
<input type="hidden" name="thread_url" value="<?php echo $thread_url; ?>" />
<ul>
<?php foreach($links as $link) : ?>
	<li><input type="checkbox" name="skip" value="<?php echo $link['link']; ?>" /><?php echo $link['link']; ?></li>	
<?php endforeach; ?>
</ul>

<p>
	<input type="submit" />
</p>
</form>