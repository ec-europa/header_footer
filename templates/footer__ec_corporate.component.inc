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
    'heading' => array(
      'class' => array('ecl-footer__identity-label'),
      'level' => 'span',
      'text' => t('Follow us:'),
    ),
    'links' => array(
      'items' => menu_navigation_links('menu-footer-follow-us'),
      'class' => array('ecl-footer__identity-link'),
    ),
  ));
  // Custom footer right.
  $variables['ecl_footer_identity_info'] = theme('menu_items_ec_corporate__links', array(
    'links' => array(
      'items' => menu_navigation_links('menu-footer-right'),
      'class' => array('ecl-footer__identity-link'),
    ),
  ));
  // Corporate footer left.
  $variables['ecl_footer_ec_menu'] = theme('menu_items_ec_corporate__lists', array(
    'links' => array('items' => menu_navigation_links('menu-nexteuropa-site-links')),
    'heading' => array(
      'text' => t('European Commission'),
      'level' => 'h1',
      'class' => array('ecl-footer__section-title'),
    ),
  ));
  
  // Corporate footer middle.
  $variables['ecl_footer_follow_ec_menu'] = theme('menu_items_ec_corporate__lists', array(
    'links' => array(
      'items' => menu_navigation_links('menu-nexteuropa-social-media'),
      'class' => array('ecl-footer__section-link')
    ),
    'heading' => array(
      'text' => t('Follow the European Commission'),
      'level' => 'h1',
      'class' => array('ecl-footer__section-title'),
    ),
    'attributes' => array(
      'class' => array('ecl-footer__section-list--inline'))
  ));
  // Corporate footer right.
  $variables['ecl_footer_eu_menu'] = theme('menu_items_ec_corporate__lists', array(
    'links' => array(
      'items' => menu_navigation_links('menu-nexteuropa-inst-links'),
      'class' => array('ecl-footer__section-link')
    ),
    'heading' => array(
      'text' => t('European Union'),
      'level' => 'h1',
      'class' => array('ecl-footer__section-title'),
    ),
  ));
  // Service footer menu.
  $variables['ecl_footer_service_menu'] = theme('menu_items_ec_corporate__links', array(
    'links' => array(
      'items' => menu_navigation_links('menu-nexteuropa-service-links'),
      'class' => array('ecl-footer__common-link')
    ),
  ));
}
