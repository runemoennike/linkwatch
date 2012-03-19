<ul>
	<li>JDRemote: <?php echo (jdremote_alive() ? 'Alive' : 'Unavailable'); ?></li>
	<li>Host: <?php echo $CONFIG['jdremote'];?></li>
	<li>Total files in JD: <?php echo jdremote_get_count_all(); ?></li>
	<li>Currently downloading : <?php echo jdremote_get_count_current(); ?></li>
	<li>Finished downloads: <?php echo jdremote_get_count_finished(); ?></li>
</ul>