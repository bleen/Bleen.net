<?php
/**
 * @file
 * resume.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function resume_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_education|full';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_education';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_school' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'school',
      ),
    ),
    'field_degree' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'div',
        'fi-cl' => 'degree',
      ),
    ),
    'field_graduation_date' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'time',
        'fi-cl' => 'graduation-date',
      ),
    ),
  );
  $export['field_collection_item|field_education|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_experience|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_experience';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_employer' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'h4',
        'fi-cl' => 'emplyer',
      ),
    ),
    'field_job_title' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'h3',
        'fi-cl' => 'job-title',
      ),
    ),
    'field_job_dates' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'time',
        'fi-cl' => 'dates-of-employment',
      ),
    ),
    'field_job_responsibilities' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
  );
  $export['field_collection_item|field_experience|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_experience|full';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_experience';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_employer' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'h4',
        'fi-cl' => 'employer',
      ),
    ),
    'field_job_title' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'h3',
        'fi-cl' => 'job-title',
      ),
    ),
    'field_job_dates' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'time',
        'fi-cl' => 'dates-of-employment',
      ),
    ),
    'field_job_responsibilities' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
  );
  $export['field_collection_item|field_experience|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_info_list|full';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_info_list';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_info_title' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'fi' => TRUE,
        'fi-el' => 'h3',
        'fi-cl' => 'info-title',
      ),
    ),
    'field_info_items' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
  );
  $export['field_collection_item|field_info_list|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resume|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resume';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'field_education' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'lb-el' => 'label',
        'lb-cl' => 'education',
        'lb-col' => TRUE,
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'education',
      ),
    ),
    'field_experience' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
        'ow' => TRUE,
        'ow-el' => 'div',
        'ow-cl' => 'experience',
      ),
    ),
    'field_info_list' => array(
      'ft' => array(
        'func' => 'theme_ds_field_expert',
      ),
    ),
  );
  $export['node|resume|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function resume_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_education|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_education';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
  );
  $export['field_collection_item|field_education|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_education|full';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_education';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_degree',
        1 => 'field_school',
        2 => 'field_graduation_date',
      ),
    ),
    'fields' => array(
      'field_degree' => 'ds_content',
      'field_school' => 'ds_content',
      'field_graduation_date' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['field_collection_item|field_education|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_experience|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_experience';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'html5_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'classes' => array(),
  );
  $export['field_collection_item|field_experience|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_experience|full';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_experience';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_job_title',
        1 => 'field_employer',
        2 => 'field_job_dates',
        3 => 'field_job_responsibilities',
      ),
    ),
    'fields' => array(
      'field_job_title' => 'ds_content',
      'field_employer' => 'ds_content',
      'field_job_dates' => 'ds_content',
      'field_job_responsibilities' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['field_collection_item|field_experience|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_info_list|full';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_info_list';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_info_title',
        1 => 'field_info_items',
      ),
    ),
    'fields' => array(
      'field_info_title' => 'ds_content',
      'field_info_items' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['field_collection_item|field_info_list|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resume|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resume';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
  );
  $export['node|resume|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resume|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resume';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'html5_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'left' => array(
        0 => 'field_experience',
        1 => 'field_education',
      ),
      'right' => array(
        0 => 'field_info_list',
      ),
    ),
    'fields' => array(
      'field_experience' => 'left',
      'field_education' => 'left',
      'field_info_list' => 'right',
    ),
    'classes' => array(),
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|resume|full'] = $ds_layout;

  return $export;
}
