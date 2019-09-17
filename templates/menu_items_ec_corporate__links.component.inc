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
  if(empty($variables['links']['items'])){
    continue;
  }
  
  // Set heading markup.
  if( empty($variables['heading']) ){
    $variables['heading_markup'] = '';
  }
  else{
    $heading = $variables['heading'];
    $variables['heading_markup'] = array(
      '#markup' => '<'. $heading['level'] .' '. drupal_attributes(array('class' => $heading['class'])) . '>'. check_plain($heading['text']) . '</' .  $heading['level'] . '>'
    );
  }
  
  // Set links.
  foreach($variables['links']['items'] as &$link){
    // Set $link['attributes']['class'].
    if (!isset($link['attributes'])) {
      $link['attributes'] = array('class' => array());
    }
    elseif (!isset($link['attributes']['class'])) {
      $link['attributes']['class'] = array();
    }
    $link['attributes']['class'] = array_merge($link['attributes']['class'], $variables['links']['class']);
    HeaderFooterCorporateHelpers::setLinkIconsPrefixSuffix($link);
  }
  $variables['links'] = $variables['links']['items'];
}
