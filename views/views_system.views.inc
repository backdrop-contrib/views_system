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
  // Table field: system.status
  $data['system']['status']['filter']['label'] = t('Status');
  $data['system']['status']['filter']['type'] = 'enabled-disabled';
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

  // Additional field: description key of system.info
  $data['system']['info_description'] = array(
    'real field' => 'info',
    'title' => t('Description'),
    'help' => t('The brief description of the module or theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_description',
    ),
  );
  // Additional filter: hidden key of system.info
  $data['system']['info_hidden'] = array(
    'real field' => 'info',
    'title' => t('Hidden'),
    'help' => t('Boolean indicating whether this module or theme is hidden.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_hidden',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_system_info_hidden',
      'label' => t('Is hidden'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_system_info_hidden',
    ),
  );
  // Additional field: mtime key of system.info
  $data['system']['info_mtime'] = array(
    'real field' => 'info',
    'title' => t('Modification time'),
    'help' => t('The info file modification time of the module or theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_mtime',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_system_info_mtime',
    ),
  );
  // Additional field: name key of system.info
  $data['system']['info_name'] = array(
    'real field' => 'info',
    'title' => t('Name'),
    'help' => t('The human readable name of the module or theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_system_info_name',
    ),
  );
  // Additional field: package key of system.info
  $data['system']['info_package'] = array(
    'real field' => 'info',
    'title' => t('Package'),
    'help' => t('The name of the package the module belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_package',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_system_info_package',
    ),
  );
  // Additional field: php key of system.info
  $data['system']['info_php'] = array(
    'real field' => 'info',
    'title' => t('PHP'),
    'help' => t('The minimum PHP version that the module or theme requires.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_php',
    ),
  );
  // Additional field: project key of system.info
  $data['system']['info_project'] = array(
    'real field' => 'info',
    'title' => t('Project'),
    'help' => t('The name of the project the module or themes belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_project',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_system_info_project',
    ),
  );
  // Additional field: timestamp key of system.info
  $data['system']['info_timestamp'] = array(
    'real field' => 'info',
    'title' => t('Timestamp'),
    'help' => t('The release date of the module or theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_timestamp',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_system_info_timestamp',
    ),
  );
  // Additional field: version key of system.info
  $data['system']['info_version'] = array(
    'real field' => 'info',
    'title' => t('Version'),
    'help' => t('The version of the module or theme.'),
    'field' => array(
      'handler' => 'views_handler_field_system_info_version',
    ),
  );

  // Additional field: Backdrop core
  $data['system']['backdrop_core'] = array(
    'real field' => 'filename',
    'title' => t('Backdrop core'),
    'help' => t('Boolean indicating whether this module or theme is part of Backdrop core.'),
    'field' => array(
      'handler' => 'views_handler_field_system_backdrop_core',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_system_backdrop_core',
      'label' => t('Is part of Backdrop core'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_system_backdrop_core',
    ),
  );
}
