<?php

/**
 * Broadcast messages form builder.
 */
function broadcast_messages_form($form, &$form_state) {
  $form['#submit'][] = 'broadcast_messages_form_submit';
  $form['#validate'][] = 'broadcast_messages_form_validate';

  $messages = isset($form_state['messages']) ? $form_state['messages'] : variable_get('broadcast_messages', array());
  $form['messages'] = array(
    '#tree' => FALSE,
    '#prefix' => '<div class="clearfix" id="broadcast-messages">',
    '#suffix' => '</div>',
    '#theme' => 'broadcast_messages',
  );

  // Add existing messages to the form.
  foreach ($messages as $key => $message) {
    _broadcast_message_form($form, $key, $message);
  }
  // Add one blank set of message fields.
  _broadcast_message_form($form, count($messages) + 1);

  $form['messages']['broadcast_more_messages'] = array(
    '#type' => 'submit',
    '#value' => t('Add another message'),
    '#submit' => array('broadcast_more_messages_submit'),
    '#ajax' => array(
      'callback' => 'broadcast_more_messages_js',
      'wrapper' => 'broadcast-messages',
      'effect' => 'fade',
    ),
  );

  $form['access_keys'] = array(
    '#type' => 'fieldset',
    '#title' => t('Access Keys'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('If a passkey is set below, then it must be appended as an arg to all requests of the coresponding type. If left blank, then no key is required.'),
  );
  $form['access_keys']['broadcast_get_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Key (get)'),
    '#required' => TRUE,
    '#description' => t('Passkey to use when getting a broadcast message.'),
    '#default_value' => variable_get('broadcast_get_key', ''),
  );
  $form['access_keys']['broadcast_set_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Key (set)'),
    '#required' => TRUE,
    '#description' => t('Passkey to use when setting a broadcast message.'),
    '#default_value' => variable_get('broadcast_set_key', ''),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Form builder for an individual broadcast message.
 */
function _broadcast_message_form(&$form, $key, $message = array()) {
  $form['messages']['message-' . $key] = array(
    '#prefix' => '<div class="broadcast-message" id="broadcast-message-' . $key . '">',
    '#suffix' => '</div>',
  );
  $form['messages']['message-' . $key]['name'] = array(
    '#type' => 'textfield',
    '#title_display' => 'invisible',
    '#title' => 'Message name',
    '#size' => 40,
    '#default_value' => isset($message['name']) ? $message['name'] : '',
    '#parents' => array('messages', $key, 'name'),
  );
  $form['messages']['message-' . $key]['message'] = array(
    '#type' => 'textfield',
    '#title_display' => 'invisible',
    '#title' => 'Message',
    '#default_value' => isset($message['message']) ? $message['message'] : '',
    '#parents' => array('messages', $key, 'message'),
  );
}

/**
 * Validate handler for the broadcast messages form.
 */
function broadcast_messages_form_validate($form, $form_state) {
  // Do not validate unless the save button is pressed.
  if ($form_state['values']['op'] != 'Save') {
    return;
  }

  // Validate the access keys.
  if (preg_match('@[^a-z0-9_]+@', $form_state['values']['broadcast_get_key'])) {
    form_set_error('broadcast_get_key', t('Access keys must contain only lowercase letters, numbers, and underscores.'));
  }
  if (preg_match('@[^a-z0-9_]+@', $form_state['values']['broadcast_set_key'])) {
    form_set_error('broadcast_set_key', t('Access keys must contain only lowercase letters, numbers, and underscores.'));
  }

  // Validate the broadcast messages.
  $names = array();
  foreach ($form_state['values']['messages'] as $key => $message) {
    if (!empty($message['name']) && in_array($message['name'], $names)) {
      form_set_error("messages][$key][name", 'Message names must be unique.');
    }
    else {
      $names[] = $message['name'];
    }

    if (preg_match('@[^a-z0-9_]+@', $message['name'])) {
      form_set_error("messages][$key][name", t('Message names must contain only lowercase letters, numbers, and underscores.'));
    }

    if (empty($message['name']) && !empty($message['message'])) {
      form_set_error("messages][$key][message", t('Messages must have a value'));
    }

    if (!empty($message['name']) && empty($message['message'])) {
      form_set_error("messages][$key][name", t('Messages must have a name'));
    }
  }
}

/**
 * Submit handler for the broadcast messages form.
 */
function broadcast_messages_form_submit($form, $form_state) {
  // Trim empty messages.
  foreach ($form_state['values']['messages'] as $key => $message) {
    if (empty($message['name']) && empty($message['message'])) {
      unset($form_state['values']['messages'][$key]);
    }
  }

  // Save values.
  variable_set('broadcast_get_key', $form_state['values']['broadcast_get_key']);
  variable_set('broadcast_set_key', $form_state['values']['broadcast_set_key']);
  variable_set('broadcast_messages', $form_state['values']['messages']);

  drupal_set_message(t('Broadcast settings have been saved.'));
}

/**
 * Submit handler to add more choices to the broadcast messages form.
 */
function broadcast_more_messages_submit($form, &$form_state) {
  $form_state['messages'] = $form_state['values']['messages'];
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax callback for adding new messages to the broadcast messages form.
 */
function broadcast_more_messages_js($form, $form_state) {
  return $form['messages'];
}

/**
 * Theme function for the broadcast messages form.
 */
function theme_broadcast_messages($variables) {
  $form = $variables['form'];

  $more_button = drupal_render($form['broadcast_more_messages']);
  unset($form['broadcast_more_messages']);

  $headers = array(t('Message Name'), t('Message'));
  $rows = array();
  foreach (element_children($form) as $key) {
    $rows[] = array(drupal_render($form[$key]['name']), drupal_render($form[$key]['message']));
  }

  return theme('table', array('header' => $headers, 'rows' => $rows)) . $more_button;
}
