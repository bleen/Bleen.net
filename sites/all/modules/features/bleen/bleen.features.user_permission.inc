<?php
/**
 * @file
 * bleen.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function bleen_user_default_permissions() {
  $permissions = array();

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
  );

  // Exported permission: access devel information
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'devel',
  );

  // Exported permission: access environment indicator
  $permissions['access environment indicator'] = array(
    'name' => 'access environment indicator',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: add twitter accounts
  $permissions['add twitter accounts'] = array(
    'name' => 'add twitter accounts',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: admin_display_suite
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: admin_fields
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: admin_view_modes
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: administer breadcrumbs
  $permissions['administer breadcrumbs'] = array(
    'name' => 'administer breadcrumbs',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'disable_breadcrumbs',
  );

  // Exported permission: administer empty page callbacks
  $permissions['administer empty page callbacks'] = array(
    'name' => 'administer empty page callbacks',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'empty_page',
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: administer google analytics
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: administer pathauto
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
  );

  // Exported permission: disable node breadcrumbs
  $permissions['disable node breadcrumbs'] = array(
    'name' => 'disable node breadcrumbs',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'disable_breadcrumbs',
  );

  // Exported permission: execute php code
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: import own tweets
  $permissions['import own tweets'] = array(
    'name' => 'import own tweets',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: make twitter accounts global
  $permissions['make twitter accounts global'] = array(
    'name' => 'make twitter accounts global',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'twitter',
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: notify of path changes
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: opt-in or out of tracking
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: switch users
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: use PHP for tracking visibility
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: use global twitter account
  $permissions['use global twitter account'] = array(
    'name' => 'use global twitter account',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'twitter',
  );

  return $permissions;
}
