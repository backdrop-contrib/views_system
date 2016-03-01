<?php

/**
 * @file
 * Definition of views_handler_field_system_info_description.
 */


/**
 * Displays the description of the .info file.
 */
class views_handler_field_system_info_description extends views_handler_field {


  function option_definition() {

    $options = parent::option_definition();

    $options['system_info_description_na'] = array('default' => TRUE);

    return $options;
  }


  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['system_info_description_na'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display <em>N/A</em> if field does not exists otherwise blank'),
      '#default_value' => !empty($this->options['system_info_description_na']),
    );
  }


  function render($values) {

    $info = unserialize($this->get_value($values));

    if (isset($info['description'])) {
      return $this->sanitize_value($info['description']);
    }
    else {
      return !empty($this->options['system_info_description_na']) ? t('N/A') : '';
    }
  }
}
