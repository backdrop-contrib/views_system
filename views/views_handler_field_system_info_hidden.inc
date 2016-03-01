<?php

/**
 * @file
 * Definition of views_handler_field_system_info_hidden.
 */


/**
 * Displays if the module or theme is part of Backdrop core.
 */
class views_handler_field_system_info_hidden extends views_handler_field_boolean {


  function render($values) {

    $value = (bool) preg_match('/s:6:"hidden";b:1/', $this->get_value($values));
    if (!empty($this->options['not'])) {
      $value = !$value;
    }

    if ($this->options['type'] == 'custom') {
      return $value ? filter_xss_admin($this->options['type_custom_true']) : filter_xss_admin($this->options['type_custom_false']);
    }
    elseif (isset($this->formats[$this->options['type']])) {
      return $value ? $this->formats[$this->options['type']][0] : $this->formats[$this->options['type']][1];
    }
    else {
      return $value ? $this->formats['yes-no'][0] : $this->formats['yes-no'][1];
    }
  }
}
