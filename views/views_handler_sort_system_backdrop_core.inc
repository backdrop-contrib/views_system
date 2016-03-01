<?php

/**
 * @file
 * Definition of views_handler_sort_system_backdrop_core.
 */


/**
 * Sorts queries whether the module or theme is part of Backdrop core.
 */
class views_handler_sort_system_backdrop_core extends views_handler_sort {


  function query() {

    $this->ensure_my_table();

    $formula = $this->view->base_field . ' LIKE \'' . db_like('core/') . '%\' ';

    $this->query->add_orderby(NULL, $formula, $this->options['order'], $this->table_alias . '_' . $this->field);
  }
}
