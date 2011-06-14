<?php

include_once('template_functions.php');

/**
 * Process variables for all preprocess hooks.
 */
function bizcard_preprocess(&$vars, $hook){
  _bizcard_include_preprocess_process_file($vars, $hook, 'preprocess');
}

/**
 * Process variables for all process hooks.
 */
function bizcard_process(&$vars, $hook){
  _bizcard_include_preprocess_process_file($vars, $hook, 'process');
}

/**
 * Inlucde a file for the given preprocess or process hook.
 * We cache the existance of the files to avoid excess disk IO which is slow.
 */
function _bizcard_include_preprocess_process_file(&$vars, $hook, $mode) {
  static $files = array();
  $cid = $mode . ':' . $hook;

  // Check if the location of the file exists. 
  if (!isset($files[$cid])) {
    $cache_obj = cache_get($cid);

    if (!$cache_obj) {
      // The file location does not exist in cache. If the preprocess file does
      // exist, add its location to cache otherwise add "none" to the cache.
      $filename = $mode . '/' . $mode .'-'. str_replace('_', '-', $hook) . '.inc';;
      $files[$cid] = is_file(drupal_get_path('theme', 'bizcard') . '/' . $filename) ? $filename : 'none';
      cache_set($cid, $files[$cid]);
    }
    else {
      $files[$cid] = $cache_obj->data;
    }
  }

  // If the file is not called "none" include it.
  if ($files[$cid] != 'none') {
    include($files[$cid]);
  }

  if ($hook == 'page') {
    // Reset styles & scripts in case anything was added during preprocess.
    $vars['styles'] = drupal_get_css();
    $vars['scripts'] = drupal_get_js();
  }
}