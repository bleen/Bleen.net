<?php
/**
  * Implements hook_preprocess_html()
  */
function placid_preprocess_html(&$vars) {
  // Be sure replace this with a custom Modernizr build!
  drupal_add_js(drupal_get_path('theme', 'placid') . '/javascripts/modernizr-2.5.3.js', array('force header' => true));
  
  // yep/nope for conditional JS loading!
  drupal_add_js(drupal_get_path('theme', 'placid') . '/javascripts/loader.js');
}
