<form action="<?php echo interface_url(array('page' => 'sitemgmt', 'action' => 'add_submit')) ?>" method="post">
Name: <input name="name" size="60" /><br/>
Login url: <input name="login" value="http://www.---.org/login.php" size="60"  /><br/>
Login POST data: <input name="login_post" value="login=Log+in&username=__USER__&password=__PASS__" size="60"  /> (__PASS__ and __USER__ will be replaced by username and password from below) <br/>
Username: <input name="user" size="60" /> <br/>
Password: <input name="pass" size="60" /> <br/>
Title regexp: <input name="title_pattern" value="/<title>(\[.*?\])? ?(.*?)( ::.*?)?<\/title>/i" size="60" /> <br/>
Title index from regexp <input name="title_pattern_idx" value="2" size="60" /> <br/>
<input type="submit" />
</form>