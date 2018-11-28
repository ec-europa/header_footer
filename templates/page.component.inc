<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_corporate_preprocess_page(&$variables) {
  if (!path_is_admin(current_path())) {

    // Adding CSS and JS files.
    $path_module = drupal_get_path('module', 'header_footer_corporate');
    drupal_add_js($path_module . '/assets/europa/scripts/europa.min.js',
      array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
      ));
    drupal_add_css($path_module . '/assets/europa/styles/europa.min.css',
      array(
        'group' => 300, // more than CSS_THEME (=100) to not be overrided.
        'weight' => 100,
      ));
    drupal_add_css($path_module . '/css/header_footer_corporate.css',
      array(
        'group' => 300, // more than CSS_THEME (=100) to not be overrided.
        'weight' => 101,
        'cache' => FALSE,
      ));

    // Define custom variables to be used in .tpl files.
    $variables['header__ec_corporate'] = theme('header__ec_corporate', array(
      'site_name' => $variables['site_name'],
    ));
    $variables['footer__ec_corporate'] = theme('footer__ec_corporate', array(
      'site_name' => $variables['site_name'],
    ));
  }
}
