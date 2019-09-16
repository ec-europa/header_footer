<?php

namespace HeaderFooterCorporate;

/**
 * Contains all Helpers functions used in the module.
 *
 * The target is to centralize code called more than once
 * in different places.
 */
abstract class HeaderFooterCorporateHelpers {

  /**
   * Return the array of Social Media networks values.
   */
  public static function getSocialMediaNetworksValues() {
    $fixed_url = '<svg focusable="false" aria-hidden="true" class="ecl-link__icon ecl-icon ecl-icon--xs"><use xlink:href="https://cdn1.fpfis.tech.ec.europa.eu/ecl/v2.11.0/ec-preset-legacy-website/images/icons/sprites/icons.svg#branded--__MY_ICON_NAME"></use></svg>';
    return array(
      array(
        'title' => 'Facebook',
        'icon'  => str_replace('__MY_ICON_NAME', 'facebook', $fixed_url),
      ),
      array(
        'title' => 'Flickr',
        'icon'  => str_replace('__MY_ICON_NAME', 'external', $fixed_url),
      ),
      array(
        'title' => 'Instagram',
        'icon'  => str_replace('__MY_ICON_NAME', 'instagram', $fixed_url),
      ),
      array(
        'title' => 'LinkedIn',
        'icon'  => str_replace('__MY_ICON_NAME', 'linkedin', $fixed_url),
      ),
      array(
        'title' => 'RSS',
        'icon'  => str_replace('__MY_ICON_NAME', 'rss', $fixed_url),
      ),
      array(
        'title' => 'Twitter',
        'icon'  => str_replace('__MY_ICON_NAME', 'twitter', $fixed_url),
      ),
      array(
        'title' => 'YouTube',
        'icon'  => str_replace('__MY_ICON_NAME', 'youtube', $fixed_url),
      ),
    );
  }

}
