<?
$element = $vars['element'];

switch ($element['#field_name']) {

}

switch ($element['#field_type']) {
  case 'email':
    if ($element['#formatter'] == 'email_plain') {
      // Obfuscating email addresses to prevent spambots.
      $element[0]['#markup'] = bizcard_markup_tag('span', strrev($element[0]['#markup']), array('style' => 'direction:rtl'));
    }
    break;
}