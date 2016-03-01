<?php

/**
 * @file
 * Definition of views_handler_sort_system_info_name.
 */


/**
 * Sorts queries by the human readable name of the module or theme.
 */
class views_handler_sort_system_info_name extends views_handler_sort {


  function query() {

    $this->ensure_my_table();

    $formula = 'SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(' . $this->real_field . ', \'s:4:"name";\', -1), \'"\', 2), \'"\', -1)';

    $this->query->add_orderby(NULL, $formula, $this->options['order'], $this->table_alias . '_' . $this->field);
  }
}
