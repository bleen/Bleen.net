<?php

  // Remove undesired menu items
  $unwanted = array('projects');
  foreach ($vars['main_menu'] as $key => $val) {
    if (in_array($val['href'], $unwanted)) {
      unset($vars['main_menu'][$key]);
    }
  }
