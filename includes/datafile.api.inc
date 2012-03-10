<?php
function datafile_read($filename) {
	$result = array();
	$result['_'] = $filename;
	$lines = file($filename);

	$current = array();
	$current_keys = array();
	
	foreach ($lines as $line) {
		list($key, $val) = preg_split('/(\s+)/', $line, 2);
		$val = trim($val);
		$key = strtolower($key);

		if (strlen(trim($line)) == 0 || in_array($key, $current_keys)) {
			$result[] = $current;
			$current = array();
			$current_keys = array();
		} 
		
		if(strlen(trim($key)) != 0) {
			$current_keys[] = $key;
			
			if (substr($key, 0, 1) == '@') {
				$subfile = dirname($filename) . '/' . $val;
				if (is_readable($subfile)) {
					$current[substr($key, 1)] = datafile_read($subfile);
				}
			} elseif ($key == '#') {
				$result[] = $val;
			} else {
				$current[$key] = $val;
			}
		}
	}

	if (count($current) > 0) {
		$result[] = $current;
	}

	return $result;
}

function datafile_write($data) {
	if (isset($data['_'])) {
		$fh = fopen($data['_'], 'w');
		unset($data['_']);

		foreach ($data as $block) {
			foreach ($block as $key => $val) {
				$key = strtoupper($key);
				if (is_array($val)) {
					if (isset($val['_'])) {
						fwrite($fh, "@" . $key . "\t" . $val['_']);
						datafile_write($val);
					} else {
						fwrite($fh, "$" . $key . "\t" . serialize($val));
					}
				} else {
					fwrite($fh, $key . "\t" . $val);
				}
				fwrite($fh, "\n");
			}
			fwrite($fh, "\n");
		}

		fclose($fh);
	}
}
