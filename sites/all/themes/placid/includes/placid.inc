<?php

/**
 * Invokes a preprocess or process hook by including the corresponding .inc
 * file and calling the associated function.
 *
 * @param $type
 *   The type of the hook. Can be preprocess or process.
 * @param $hook
 *   The name of the hook.
 * @param &$vars
 *   An array of variables belonging to the (pre)process hook.
 *   Handed by reference.
 */
function placid_invoke($type, $hook, &$vars) {
  $function = 'placid_' . $type . '_' . $hook;

  if (!function_exists($function)) {
    $file = dirname(__FILE__) . '/' . $type . '/' . $type . '-' . str_replace('_', '-', $hook) . '.inc';

    if (is_file($file)) {
      include $file;
    }
  }

  if (function_exists($function)) {
    $function($vars);
  }
}
