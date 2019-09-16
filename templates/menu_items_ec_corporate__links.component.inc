<?php

/**
 * @file
 * Contains component file.
 */
 
use HeaderFooterCorporate\HeaderFooterCorporateHelpers;

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_corporate_preprocess_menu_items_ec_corporate__links(&$variables) {
  if(empty($variables['links'])){
    continue;
  }
  
  // Set heading markup.
  $heading = $variables['heading'];
  $variables['heading_markup'] = array(
    '#markup' => '<'. $heading['level'] .' '. drupal_attributes(array('class' => $heading['class'])) . '>'. check_plain($heading['text']) . '</' .  $heading['level'] . '>'
  );
  
  // Clean links.
  $options = HeaderFooterCorporateHelpers::getSocialMediaNetworksValues();
  $titles = array_column($options, 'title');
  foreach($variables['links'] as &$link){
    // Test if we have to an icon in prefix.
    $link['icon'] = '';
    if( ($found_key = array_search($link['title'], $titles) ) !== FALSE ){
      if(isset($options[$found_key]['icon'])){
        $link['icon'] = $options[$found_key]['icon'];
      }
    }
  }
}
