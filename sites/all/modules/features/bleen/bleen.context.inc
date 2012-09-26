<?php
/**
 * @file
 * bleen.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function bleen_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = '';
  $context->tag = 'Global Contexts';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'bleen-bleen_definition' => array(
          'module' => 'bleen',
          'delta' => 'bleen_definition',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar',
          'weight' => '-16',
        ),
        'views-site_tweets-site_tweets_block' => array(
          'module' => 'views',
          'delta' => 'site_tweets-site_tweets_block',
          'region' => 'sidebar',
          'weight' => '-15',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global Contexts');
  $export['global'] = $context;

  return $export;
}
