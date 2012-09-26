<?php

/* ==========================  L O C A L  ========================= */
$aliases['local'] = array(
  'parent' => '@parent',
  'env' => 'local',
  '%dump-dir' => '/tmp/php',
);


/* ===========================  P R O D  ========================== */
$aliases['prod'] = array(
  'parent' => '@parent',
  'env' => 'dev',
  'root' => '/home/alexross/sites/bleen.net/docroot',
  'path-aliases' => array(
    '%dump-dir' => '/tmp',
    '%drush' => '/home/alexross/bin/drush',
    '%drush-script' => '/home/alexross/bin/drush/drush',
  ),
  'remote-host' => 'bleen.net',
  'remote-user' => 'alexross',
);

