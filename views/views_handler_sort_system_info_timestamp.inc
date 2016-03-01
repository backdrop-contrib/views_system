<?php

/**
 * @file
 * Definition of views_handler_sort_system_info_timestamp.
 */


/**
 * Sorts queries by the release date of the modules and themes.
 */
class views_handler_sort_system_info_timestamp extends views_handler_sort {


  function query() {

    $this->ensure_my_table();

    $formula = 'SUBSTRING_INDEX(SUBSTRING_INDEX(SUBSTRING_INDEX(' . $this->real_field . ', \'s:9:"timestamp";\', -1), \'"\', 2), \'"\', -1)';

    $this->query->add_orderby(NULL, $formula, $this->options['order'], $this->table_alias . '_' . $this->field);
  }
}
