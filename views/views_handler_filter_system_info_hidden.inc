<?php

/**
 * @file
 * Definition of views_handler_filter_system_info_hidden.
 */


/**
 * Checks if a module or theme is hidden or not.
 */
class views_handler_filter_system_info_hidden extends views_handler_filter_boolean_operator {


  function query() {

    $this->ensure_my_table();

    $field = "$this->table_alias.$this->real_field ";
    $operator = empty($this->value) ? 'NOT LIKE' : 'LIKE';

    $this->query->add_where($this->options['group'], $field, '%' . db_like('s:6:"hidden";b:1;') . '%', $operator);
  }
}
