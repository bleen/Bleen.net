<?php

require_once dirname(__FILE__) . '/includes/placid.inc';

/**
 * Implements hook_preprocess().
 */
function placid_preprocess(&$vars, $hook) {
  placid_invoke('preprocess', $hook, $vars);
}

/**
 * Implements hook_process().
 */
function placid_process(&$vars, $hook) {
  placid_invoke('process', $hook, $vars);
}

/**
  * Implements hook_preprocess_html()
  */
function placid_preprocess_html(&$vars) {
  // Be sure replace this with a custom Modernizr build!
  drupal_add_js(drupal_get_path('theme', 'placid') . '/javascripts/modernizr-2.5.3.js', array('force header' => true));

  // yep/nope for conditional JS loading!
  drupal_add_js(drupal_get_path('theme', 'placid') . '/javascripts/loader.js');
}

/**
 * Alter the comments form.
 */
function placid_form_comment_form_alter(&$form, &$form_state) {
  $form['author']['homepage']['#access'] = FALSE;
  $form['author']['name']['#required'] = TRUE;
  $form['author']['mail']['#description'] = '';
  $form['#after_build'][] = 'placid_form_comment_form_afterbuild';
}

/**
 * Comment form afterbuild function.
 */
function placid_form_comment_form_afterbuild(&$form, $form_state) {
  $form['comment_body'][LANGUAGE_NONE][0]['format']['#access'] = FALSE;

  $form['title'] = array(
    '#markup' => '<h2 class="form-title">' . t('Leave a comment') . '</h3>',
    '#weight' => -100,
  );

  return $form;
}

/**
 * Theme override function.
 */
function placid_pager($vars) {
  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $quantity = $vars['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ newer')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('older ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current', 'button'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }

    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}

/**
 * Theme override function.
 */
function placid_pager_link($vars) {
  $text = $vars['text'];
  $page_new = $vars['page_new'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $attributes = $vars['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
      $attributes['class'][] = 'button';
    }
  }

  return l($text, $_GET['q'], array('attributes' => $attributes, 'query' => $query));
}

/**
 * Theme override function.
 */
function placid_captcha(&$vars) {
  $element = $vars['element'];

  if (!empty($element['#description']) && isset($element['captcha_widgets'])) {
    $element['captcha_widgets']['captcha_response']['#title'] = $element['#description'];
  }

  return '<div class="captcha clearfix">' . drupal_render_children($element) . '</div>';
}

/**
 * Define display suite preprocess fields defined in preprocess-node.inc
 */
function placid_ds_fields_info($entity_type) {
  $fields = array();
  $fields['read_on'] = array(
    'title' => t('Read on button'),
    'field_type' => DS_FIELD_TYPE_PREPROCESS,
  );
  return array('node' => $fields);
}

/**
 * Process function for date displays. This ensures that "to Present" is used on
 * job dates fields when no "to" date is provided.
 */
function placid_process_date_display_combination(&$vars) {
  $date1 = &$vars['dates']['value']['formatted'];
  $date2 = &$vars['dates']['value2']['formatted'];
  if ($vars['field']['field_name'] == 'field_job_dates' &&  ($date1 == $date2 || empty($date2))) {
    $date2 = t('Present');
  }
}
