<?php

/**
 * @file
 * Defines theme_button().
 */

/**
 * Returns HTML for a button.
 * 
 * Inspired from form.inc:theme_button().
 */
function _header_footer_corporate_theme_button(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  if (isset($element['#ecl-buttontype'])) {
    $key = array_search('btn-search', $element['#attributes']['class']);
    if($key !== FALSE){
      unset($element['#attributes']['class'][$key]);
    }
  }
  element_set_attributes($element, array('id', 'name', 'value'));
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }
  if (isset($element['#ecl-buttontype']) && $element['#ecl-buttontype'] == 'button') {
    $value = $element['#value'];
    unset($element['#attributes']['value']);
    return '<button' . drupal_attributes($element['#attributes']) . '>' . $value . '</button>';
  }
  else {
    return '<input' . drupal_attributes($element['#attributes']) . ' />';
  }
}
