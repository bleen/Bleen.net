<?php

/**
 * Build an HTML tag.
 *
 * @param $tag
 *   The html tag to build.
 *
 * @param $content
 *   The inner-html that will be placed inside the tag. For short tags like
 *   <img> or <br> use paws_markup_short_tag.
 *
 * @param $attributes
 *   An array of attributes appropriate for the drupal_attributes() function.
 */
function bizcard_markup_tag($tag, $value = '', $attributes = array(), $prefix = '', $suffix = '') {
  if (empty($value)) {
    return '';
  }

  $tag = array(
    '#tag' => $tag,
    '#value' => $value,
    '#attributes' => $attributes,
    '#value_prefix' => $prefix,
    '#value_suffix' => $suffix,
  );

  return theme('html_tag', array('element' => $tag));
}

/**
 * Build the markup for the page logo.
 */
function bizcard_build_page_logo($logo) {
  $output = '';

  if (!empty($logo)) {
    $img = theme('image', array('path' => $logo, 'alt' => t('Home')));
    $output = l($img, '<front>', array('html' => TRUE, 'attributes' => array('class' => array('logo'))));
  }

  return $output;
}

function bizcard_build_hands() {
  $output = '';

  if (!drupal_is_front_page()) {
    $left_hand = bizcard_markup_tag('div', '&nbsp;', array('class' => 'hand left'));
    $right_hand = bizcard_markup_tag('div', '&nbsp;', array('class' => 'hand right'));
    $output .= $left_hand . $right_hand;
  }

  return $output;
}

/**
 * Build the markup for the main menu.
 */
function bizcard_build_page_main_menu($main_menu) {
  $output = '';

  if (!empty($main_menu)) {
    $menu = array(
      'links' => $main_menu,
      'attributes' => array(
        'id' => 'main-menu-links',
        'class' => array('links', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    );

    $menu = theme('links__system_main_menu', $menu);
    $output = bizcard_markup_tag('div', $menu, array('class' => 'ribbon'));
  }

  return $output;
}

function bizcard_build_node_attributes($node, $classes, $attributes) {
  $attributes['id']       = 'node-' . $node->nid;
  $attributes['class']    = $classes;
  $attributes['class'][]  = 'clearfix';

  return drupal_attributes($attributes);
}

function bizcard_build_node_title($node, $vars) {
  $title = '';

  if (!$vars['page']) {
    $title .= render($title_prefix);
    $title .= bizcard_markup_tag('h2', $vars['title'], $vars['title_attributes_array']);
    $title .= render($title_suffix);
  }

  return $title;
}

function bizcard_build_node_date($node) {
  switch ($node->nid) {
    case 1:
      $date = '';
      break;
    default: 
      $date = format_date($node->created);
  }

  return $date;
}

function bizcard_build_node_content_attributes($attributes) {
  $attributes['class'][] = 'content';
  $attributes['class'][] = 'clearfix';

  return drupal_attributes($attributes);
}

function bizcard_build_node_content($node, $vars) {
  $content = $vars['content'];

  hide($content['links']);

  switch ($node->nid) {
    case 1:
      // Rejigger the render array for "resume".
      $content['#sorted'] = TRUE;
      $content['left'] = array(
        '#prefix'   => '<div class="left-col">',
        '#suffix'   => '</div>',
      );
      $content['left']['field_experience'] = $content['field_experience'];
      $content['left']['field_education'] = $content['field_education'];

      $content['right'] = array(
        '#prefix'   => '<div class="right-col">',
        '#suffix'   => '</div>',
      );
      $content['right']['field_info_list'] = $content['field_info_list'];

      unset($content['field_experience'], $content['field_education'], $content['field_info_list']);
      break;
  }

  return $content;
}