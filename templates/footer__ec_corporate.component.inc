<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_corporate_preprocess_footer__ec_corporate(&$variables) {
  // Custom footer middle.
  $variables['ecl_footer_follow_us_menu'] = theme('menu_items_ec_corporate__links', array(
    'links' => menu_navigation_links('menu-footer-follow-us'),
    'heading' => array(
      'class' => array('ecl-footer__identity-label'),
      'level' => 'span',
      'text' => t('Follow us:'),
    ),
  ));
  // Custom footer right.
  $ecl_footer_improved_menu = menu_navigation_links('menu-footer-right');
  $variables['ecl_footer_improved_menu'] = theme('menu_items_ec_corporate__lists', array(
    'links' => $ecl_footer_improved_menu,
    'attributes' => array(
      'id' => 'ecl-footer-improved-menu',
      'class' => array('ecl-footer__menu'),
    ),
  ));
  // Corporate footer left.
  $ecl_footer_ec_menu = menu_navigation_links('menu-nexteuropa-site-links');
  $variables['ecl_footer_ec_menu'] = theme('menu_items_ec_corporate__lists', array(
    'links' => $ecl_footer_ec_menu,
    'heading' => array(
      'text' => t('European Commission'),
      'level' => 'h1',
      'class' => array('ecl-footer__section-title'),
    ),
    'attributes' => array(
      'id' => 'ecl-footer-improved-menu',
      'class' => array('ecl-footer__menu'),
    ),
  ));
  
  // Corporate footer middle.
  $ecl_footer_follow_ec_menu = menu_navigation_links('menu-nexteuropa-social-media');
  $variables['ecl_footer_follow_ec_menu'] = theme('menu_items_ec_corporate__links', array(
    'links' => $ecl_footer_follow_ec_menu,
    'attributes' => array(
      'id' => 'ecl-footer-follow-ec-menu',
      'class' => array('ecl-footer__menu', 'ecl-footer__social-links'),
    ),
    'heading' => array(
      'text' => t('Follow the European Commission'),
      'level' => 'h1',
      'class' => array('ecl-footer__section-title'),
    ),
  ));
  // Corporate footer right.
  $ecl_footer_eu_menu = menu_navigation_links('menu-nexteuropa-inst-links');
  $variables['ecl_footer_eu_menu'] = theme('menu_items_ec_corporate__links', array(
    'links' => $ecl_footer_eu_menu,
    'attributes' => array(
      'id' => 'ecl-footer-eu-menu',
      'class' => array('ecl-footer__menu'),
    ),
    'heading' => array(
      'text' => t('European Union'),
      'level' => 'h1',
      'class' => array('ecl-footer__section-title'),
    ),
  ));
  // Service footer menu.
  $ecl_footer_service_menu = menu_navigation_links('menu-nexteuropa-service-links');
  $variables['ecl_footer_service_menu'] = theme('menu_items_ec_corporate__lists', array(
    'links' => $ecl_footer_service_menu,
    'attributes' => array(
      'id' => 'ecl-footer-service-menu',
      'class' => array('ecl-footer__menu'),
    ),
  ));
}
