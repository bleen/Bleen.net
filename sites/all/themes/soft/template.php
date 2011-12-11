<?php
/**
 * Your themes template.php file
 */
function soft_css_alter(&$css) {
  // Turn off some styles from the system module.
  unset($css[drupal_get_path('module', 'system') . '/system.messages.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
}

function soft_preprocess_page(&$variables) {
  kpr($variables);
  dargs();
}
