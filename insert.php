<?php 

  file_put_contents($_GET['path'], "notify", LOCK_EX);
  file_put_contents("c:/folder1/file.txt", "notify", LOCK_EX);
  
?>
