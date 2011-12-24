<?php
kpr($vars);

  // Mark author comments as special.
  if ($vars['comment']->uid == $vars['node']->uid) {
    $vars['attributes']['class'][] = 'comment-by-author';
  }

  // Add some render arrays for consistency.
  $vars['author'] = array(
    '#markup' => $vars['author'],
  );
  $vars['title'] = array(
    '#markup' => '<h3 class="comment-title">' . check_plain($vars['comment']->subject) . '</h3>',
  );

  // Format the created date.
  $created_display = format_date($vars['comment']->created, 'short');
  $created_iso = format_date($vars['comment']->created, 'html5_tools_iso8601');
  $vars['created'] = theme('html5_tools_time', array('date' => $created_display, 'isodate' => $created_iso));
