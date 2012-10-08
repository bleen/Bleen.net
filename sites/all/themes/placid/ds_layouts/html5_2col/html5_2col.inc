<?php

/**
 * @file
 * Display Suite html5_2col configuration.
 */

function ds_html5_2col() {
  return array(
    'label' => t('HTML5 two column'),
    'regions' => array(
      'left' => t('Left'),
      'right' => t('Right'),
    ),
    'css' => TRUE,
  );
}
