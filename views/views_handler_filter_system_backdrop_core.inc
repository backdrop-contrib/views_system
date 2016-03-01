<?php

/**
 * @file
 * Definition of views_handler_filter_system_backdrop_core.
 */


/**
 * Checks if the module or theme is part of Backdrop core.
 */
class views_handler_filter_system_backdrop_core extends views_handler_filter_boolean_operator {


  function query() {

    $this->ensure_my_table();

    $field = "$this->table_alias.$this->real_field ";
    $operator = empty($this->value) ? 'NOT LIKE' : 'LIKE';

    $this->query->add_where($this->options['group'], $field, db_like('core/') . '%', $operator);
  }
}
