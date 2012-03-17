<h2>Added site: <i><?php echo $site['name']; ?></i></h2>

<pre>
<?php echo htmlentities(print_r($site, true)) ?>
</pre>

<?php echo interface_link('Return to Overview', array('page' => 'overview')); ?>