<?php
/**
 * @file
 * bleen.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bleen_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bleen_definition';
  $strongarm->value = '<p>&quot;Scientists at CalTech announced today that they have discovered a new number; that new number is bleen. They claim it come between six and seven.&quot;&nbsp;&mdash;&nbsp;George Carlin</p>
<p>adj. - Of an object, blue when first observed before a specified time or green when first observed after that time. See also <a href="http://en.wiktionary.org/wiki/grue">grue</a>.&nbsp;&mdash;&nbsp;Wiktionary</p>
<p>In Dutch, bleen means &quot;diaper.&quot;</p>
';
  $export['bleen_definition'] = $strongarm;

  return $export;
}
