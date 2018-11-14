<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_corporate_preprocess_footer__ec_corporate(&$variables) {
  // Footer middle menu.
  $ecl_footer_follow_us_menu = menu_navigation_links('menu-footer-follow-us');
  $variables['ecl_footer_follow_us_menu'] = theme('links__ecl_menus', array(
    'links' => $ecl_footer_follow_us_menu,
    'attributes' => array(
      'id' => 'ecl-footer-follow-us-menu',
      'class' => array('ecl-footer__menu'),
    ),
    'heading' => array(
      'text' => t('Follow us:'),
      'level' => 'p',
      'class' => array('ecl-footer__label'),
    ),
  ));
  // Footer right menu.
  $ecl_footer_improved_menu = menu_navigation_links('menu-footer-right');
  $variables['ecl_footer_improved_menu'] = theme('links__ecl_menus', array(
    'links' => $ecl_footer_improved_menu,
    'attributes' => array(
      'id' => 'ecl-footer-improved-menu',
      'class' => array('ecl-footer__menu'),
    ),
  ));
  // Corporate footer left menu.
  $ecl_footer_ec_menu = menu_navigation_links('menu-nexteuropa-site-links');
  $variables['ecl_footer_ec_menu'] = theme('links__ecl_menus', array(
    'links' => $ecl_footer_ec_menu,
    'attributes' => array(
      'id' => 'ecl-footer-ec_menu',
      'class' => array('ecl-footer__menu'),
    ),
    'heading' => array(
      'text' => t('European Commission'),
      'level' => 'h4',
      'class' => array('ecl-h4', 'ecl-footer__title'),
    ),
  ));
  // Corporate footer middle menu.
  $ecl_footer_follow_ec_menu = menu_navigation_links('menu-nexteuropa-social-media');
  $variables['ecl_footer_follow_ec_menu'] = theme('links__ecl_menus', array(
    'links' => $ecl_footer_follow_ec_menu,
    'attributes' => array(
      'id' => 'ecl-footer-follow-ec-menu',
      'class' => array('ecl-footer__menu', 'ecl-footer__social-links'),
    ),
    'heading' => array(
      'text' => t('Follow the European Commission'),
      'level' => 'h4',
      'class' => array('ecl-h4', 'ecl-footer__title'),
    ),
  ));
  // Corporate footer right menu.
  $ecl_footer_eu_menu = menu_navigation_links('menu-nexteuropa-inst-links');
  $variables['ecl_footer_eu_menu'] = theme('links__ecl_menus', array(
    'links' => $ecl_footer_eu_menu,
    'attributes' => array(
      'id' => 'ecl-footer-eu-menu',
      'class' => array('ecl-footer__menu'),
    ),
    'heading' => array(
      'text' => t('European Union'),
      'level' => 'h4',
      'class' => array('ecl-h4', 'ecl-footer__title'),
    ),
  ));
  // Service footer menu.
  $ecl_footer_service_menu = menu_navigation_links('menu-nexteuropa-service-links');
  $variables['ecl_footer_service_menu'] = theme('links__ecl_menus', array(
    'links' => $ecl_footer_service_menu,
    'attributes' => array(
      'id' => 'ecl-footer-service-menu',
      'class' => array('ecl-footer__menu'),
    ),
  ));
}
