<?php
/**
 * @file
 * resume.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function resume_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function resume_node_info() {
  $items = array(
    'resume' => array(
      'name' => t('Resume'),
      'base' => 'node_content',
      'description' => t('Use <em>resume</em> to create a basic resume page.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
