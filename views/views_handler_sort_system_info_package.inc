<?php

/**
 * @file
 * Definition of views_handler_sort_system_info_package.
 */


/**
 * Sorts queries by the name of the package the module belongs to.
 */
class views_handler_sort_system_info_package extends views_handler_sort {


  function query() {

    $this->ensure_my_table();

    $formula = 'SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(' . $this->real_field . ', \'s:7:"package";\', -1), \'"\', 2), \'"\', -1)';

    $this->query->add_orderby(NULL, $formula, $this->options['order'], $this->table_alias . '_' . $this->field);
  }
}
