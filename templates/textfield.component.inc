<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_process_HOOK().
 */
function header_footer_corporate_process_textfield(&$variables) {
  if(!empty($variables['element']['#ecl-header_footer_corporate']['header'])){
    $element = &$variables['element'];
    $element['#field_prefix'] = '<label class="ecl-search-form__label ecl-form-label" for="edit-querytext">'.t('Search').'</label>';
    unset($element['#title']);
    $element['#attributes'] = array(
      'class' =>
        array(
          'ecl-search-form__text-input',
          'ecl-text-input',
    ));
  }
}
