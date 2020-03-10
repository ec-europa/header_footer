<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_process_HOOK().
 */
function header_footer_preprocess_textfield(&$variables) {
  global $language;
  if (!empty($variables['element']['#ecl-header_footer']['header'])) {
    $element = &$variables['element'];
    $element['#field_prefix'] = '<label class="ecl-search-form__label ecl-form-label" for="edit-querytext">' . i18n_string_translate('blocks:nexteuropa_europa_search:nexteuropa_europa_search_form:title', 'Search', array('langcode' => $language->language)) . '</label>';
    unset($element['#title']);
    $element['#attributes'] = array(
      'class' => array(
          'ecl-search-form__text-input',
          'ecl-text-input',
        ),
    );
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_preprocess_form_element(&$variables) {
  if(!empty($variables['element']['#ecl-header_footer'])){
    $variables['element']['#title_display'] = 'none';
  }
}