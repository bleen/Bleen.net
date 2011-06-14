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
 * Build the markup for the page logo
 */
function bizcard_build_page_logo($logo) {
  $output = '';

  if (!empty($logo)) {
    $img = theme('image', array('path' => $logo, 'alt' => t('Home')));
    $output = l($img, '<front>', array('html' => TRUE));
  }

  return $output;
}
