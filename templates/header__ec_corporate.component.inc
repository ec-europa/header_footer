<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_corporate_preprocess_header__ec_corporate(&$variables) {
  global $language;

  // Language switcher.
  $variables['language_switcher_url'] = url(
    'language-selector/site-language', array(
      'html' => TRUE,
      'query' => array(
        drupal_get_destination(),
      ),
    )
  );
  $variables['language_switcher_label'] = $language->native;
  $variables['language_switcher_code'] = $language->language;

  // Search form.
  $search_form = drupal_get_form('nexteuropa_europa_search_search_form');
  $variables['ecl_search_block'] = drupal_render($search_form);
  $variables['ecl_search_block'] = str_replace('form-item form-type-textfield form-item-QueryText', 'ecl-search-form__textfield-wrapper', $variables['ecl_search_block']);
  $variables['ecl_search_block'] = str_replace('ecl-text-input ecl-search-form__textfield form-control form-text', 'ecl-text-input ecl-search-form__textfield', $variables['ecl_search_block']);

  $easy_breadcrumb_block = module_invoke('easy_breadcrumb', 'block_view', 'easy_breadcrumb');
  $variables['easy_breadcrumb_block'] = render($easy_breadcrumb_block['content']);
}
