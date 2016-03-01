<?php

/**
 * @file
 * Definition of views_handler_sort_system_info_hidden.
 */


/**
 * Sorts queries whether the module or theme is hidden.
 */
class views_handler_sort_system_info_hidden extends views_handler_sort {


  function query() {

    $this->ensure_my_table();

    $formula = $this->real_field . ' LIKE \'%' . db_like('s:6:"hidden";b:1;') . '%\' ';

    $this->query->add_orderby(NULL, $formula, $this->options['order'], $this->table_alias . '_' . $this->field);
  }
}
