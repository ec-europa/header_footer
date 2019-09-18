<?php

namespace HeaderFooterCorporate;

/**
 * Contains all Helpers functions used in the module.
 *
 * The target is to centralize code called more than once
 * in different places or to externalize rules for better understanding.
 */
abstract class HeaderFooterCorporateHelpers {

  /**
   * Return the array of Social Media networks values.
   */
  public static function getSocialMediaNetworksValues() {
    
    return array(
      'Facebook',
      'Flickr',
      'Instagram',
      'LinkedIn',
      'Other social networks',
      'RSS',
      'Twitter',
      'YouTube',
    );
  }
  
  /**
   * Set icons rules of footer links.
   */
  public static function setLinkIconsPrefixSuffix(&$link) {
    // Set ['attributes']['class'].
    if (!isset($link['attributes'])) {
      $link['attributes'] = array('class' => array());
    }
    elseif (!isset($link['attributes']['class'])) {
      $link['attributes']['class'] = array();
    }
    // Process.
    $icon_rules = self::getSocialMediaNetworksValues() + array(
      'EU institutions'       => 'ui--external',
      'European Union'        => 'ui--external',
      'Facebook'              => 'branded--facebook',
      'Instagram'             => 'branded--instagram',
      'LinkedIn'              => 'branded--linkedin',
      'Other social networks' => 'ui--external',
      'Other social media'    => 'ui--external',
      'RSS'                   => 'branded--rss',
      'Twitter'               => 'branded--twitter',
      'YouTube'               => 'branded--youtube',
    );
    
    $default = array('ecl-link ecl-link--standalone');
    $link['attributes']['class'] = array_merge($default, $link['attributes']['class']);
    if( isset($icon_rules[$link['title']]) ){
      $icon_name = $icon_rules[$link['title']];
      $link['title'] = '<span class="ecl-link__label">' . $link['title'] . '</span>';
      $link['html'] = TRUE;
      $link['attributes']['class'][] = 'ecl-link--icon';
      $fixed_url = '<svg focusable="false" aria-hidden="true" class="ecl-link__icon ecl-icon ecl-icon--xs"><use xlink:href="'.static::getAssetsPath().'/images/icons/sprites/icons.svg#__MY_ICON_NAME"></use></svg>';
      if($icon_name == 'ui--external'){
        $link['attributes']['class'][] = 'ecl-link--icon-after';
        $link['title'] .= '&nbsp;'. str_replace('__MY_ICON_NAME', $icon_name, $fixed_url);
      }
      else{
        $link['attributes']['class'][] = 'ecl-link--icon-before';
        $link['title'] = str_replace('__MY_ICON_NAME', $icon_name, $fixed_url) . '&nbsp;' . $link['title'];
      }
    }
  }
  
  /**
   * Get assets path.
   */
  public static function getAssetsPath($type = 'url') {
    return 'https://cdn1.fpfis.tech.ec.europa.eu/ecl/v2.11.0/ec-preset-legacy-website';
  }
    
}
