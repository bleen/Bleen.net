<?php

  // Remove undesired menu items
  $unwanted = array('projects', 'node/1');
  foreach ($vars['main_menu'] as $key => $val) {
    if (in_array($val['href'], $unwanted)) {
      unset($vars['main_menu'][$key]);
    }
  }
