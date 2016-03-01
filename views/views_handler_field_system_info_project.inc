<?php

/**
 * @file
 * Definition of views_handler_field_system_info_project.
 */


/**
 * Displays value of the project key of the .info file.
 */
class views_handler_field_system_info_project extends views_handler_field {


  function option_definition() {

    $options = parent::option_definition();

    $options['system_info_project_na'] = array('default' => TRUE);

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['system_info_project_na'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display <em>N/A</em> if field does not exists otherwise blank'),
      '#default_value' => !empty($this->options['system_info_project_na']),
    );
  }


  function render($values) {

    $info = unserialize($this->get_value($values));

    if (isset($info['project'])) {
      return $this->sanitize_value($info['project']);
    }
    else {
      return !empty($this->options['system_info_project_na']) ? t('N/A') : '';
    }
  }
}
