Adding thread to site "<?php echo $site_name ?>"

<form action="<?php echo interface_url(array('page' => 'threadmgmt', 'action' => 'add_preview')) ?>" method="post">
<input type="hidden" name="site_name" value="<?php echo $site_name ?>" />
Url: <input name="thread_url" />
<input type="submit" />
</form>