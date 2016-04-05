<?php

/**
 * @file
 * Definition of views_handler_field_views_system_dependencies.
 */


/**
 * Field handler to display all dependencies of a module.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_views_system_dependencies extends views_handler_field_prerender_list {

  function pre_render(&$values) {
    $this->items = array();

    foreach ($values as $result) {

      $field = $this->get_value($result, NULL, TRUE);
      if (!empty($field) && !isset($this->items[$field])) {

        foreach (unserialize($field) as $name => $module) {

          $this->items[$field][$name]['label'] = $module['label'];
          $this->items[$field][$name]['name'] = $module['name'];
          $this->items[$field][$name]['version'] = $module['version'];
        }
      }
    }
  }

  function render_item($count, $item) {
    return !empty($item['version']) ? $item['label'] . ' ' . $item['version'] : $item['label'];
  }

  function document_self_tokens(&$tokens) {
    $tokens['[' . $this->options['id'] . '-label' . ']'] = t('The human readable name of the module.');
    $tokens['[' . $this->options['id'] . '-name' . ']'] = t('The machine-name of the module.');
    $tokens['[' . $this->options['id'] . '-version' . ']'] = t('The version of the module.');
  }

  function add_self_tokens(&$tokens, $item) {
    if (!empty($item['name'])) {
      $tokens['[' . $this->options['id'] . '-label' . ']'] = $item['label'];
      $tokens['[' . $this->options['id'] . '-name' . ']'] = $item['name'];
      $tokens['[' . $this->options['id'] . '-version' . ']'] = $item['version'];
    }
  }
}
