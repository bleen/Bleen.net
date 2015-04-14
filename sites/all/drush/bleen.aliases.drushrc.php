<?php

/* ==========================  L O C A L  ========================= */
$aliases['local'] = array(
  'env' => 'local',
  '%dump-dir' => '/tmp/php',
);


/* ===========================  P R O D  ========================== */
$aliases['prod'] = array(
  'env' => 'prod',
  'root' => '/home/alexross/sites/bleen.net/docroot',
  'path-aliases' => array(
    '%dump-dir' => '/tmp',
    '%drush' => '/home/alexross/.composer/vendor/bin',
    '%drush-script' => '/home/alexross/.composer/vendor/bin/drush',
  ),
  'remote-host' => 'bleen.net',
  'remote-user' => 'alexross',
);

