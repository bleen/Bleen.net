<?php
$node = $vars['node'];

if ($vars['view_mode'] == 'full' && $vars['page']) {
  $vars['classes_array'][] = 'node-full';
}

$vars['node_attributes']        = bizcard_build_node_attributes($node, $vars['classes_array'], $vars['attributes_array']);
$vars['title']                  = bizcard_build_node_title($node, $vars);
$vars['content_attributes']     = bizcard_build_node_content_attributes($vars['content_attributes_array']);
$vars['content']                = bizcard_build_node_content($node, $vars);
$vars['date']                   = bizcard_build_node_date($node);