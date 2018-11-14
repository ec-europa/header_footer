<?php

/**
 * @file
 * Defines theme_button().
 */

/**
 * Returns HTML for a button.
 */
function _header_footer_corporate_theme_button(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  if (isset($element['#ecl-buttontype'])) {
    $key = array_search('btn-search', $element['#attributes']['class']);
    unset($element['#attributes']['class'][$key]);
  }
  element_set_attributes($element, array('id', 'name', 'value'));
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }
  if (isset($element['#ecl-buttontype']) && $element['#ecl-buttontype'] == 'button') {
    /* classes for the ecl-search button */
    $element['#attributes']['class'][] = 'ecl-button';
    $element['#attributes']['class'][] = 'ecl-button--form';
    $element['#attributes']['class'][] = 'ecl-search-form__button';
    $value = $element['#value'];
    unset($element['#attributes']['value']);
    return '<button' . drupal_attributes($element['#attributes']) . '>' . filter_xss_admin($value) . '</button>';
  }
  else {
    return '<input' . drupal_attributes($element['#attributes']) . ' />';
  }
}
