<?php

/**
 * Implimentats hook_css_alter().
 */
function soft_css_alter(&$css) {
  // Turn off some styles from the system module.
  unset($css[drupal_get_path('module', 'system') . '/system.messages.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
}

/**
 * Theme override function.
 */
function soft_links__system_main_menu($variables) {
  $output = '';
  $links = $variables['links'];
  $attributes = $variables['attributes'];

  if (count($links) > 0) {
    $output .= '<nav' . drupal_attributes($attributes) . '>';
    foreach ($links as $key => $link) {
      if (isset($link['href'])) {
        $class = array($key);
        if ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page())) {
          $class[] = 'active';
        }

        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
    }
    $output .= '</nav>';
  }

  return $output;
}
