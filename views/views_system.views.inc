<?php

/**
 * @file
 * Provide views data and handlers for the views_system module.
 */


/**
 * Implements of hook_views_data_alter().
 */
function views_system_views_data_alter(&$data) {

  // Table field: system.owner
  $data['system']['owner'] = array(
    'title' => t('Owner'),
    'help' => t("A theme's 'parent'. Can be either a theme or an engine."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'owner',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // Table field: system.bootstrap
  $data['system']['bootstrap'] = array(
    'title' => t('Bootstrap'),
    'help' => t("Boolean indicating whether this module is loaded during Backdrop's early bootstrapping phase (e.g. even before the page cache is consulted)."),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'bootstrap',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // Table field: system.weight
  $data['system']['weight'] = array(
    'title' => t('Weight'),
    'help' => t("The order in which this module's hooks should be invoked relative to other modules. Equal-weighted modules are ordered by name."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'weight',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  // Table field: system.info
  $data['system']['info'] = array(
    'title' => t('Info'),
    'help' => t("A serialized array containing information from the module's .info file; keys can include name, description, package, version, core, dependencies, and php."),
    'field' => array(
      'handler' => 'views_handler_field_serialized',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );
}
