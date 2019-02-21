<?php

/**
 * @file
 * Redefines theme_easy_breadcrumb().
 */

/**
 * Theme function for the breadcrumb.
 *
 * Redefine the theme_easy_breadcrumb().
 */
function _header_footer_corporate_theme_easy_breadcrumb(&$variables) {
  $menu_crumbs = menu_tree('menu-breadcrumb-menu');
  $breadcrumb = $variables['breadcrumb'];
  $breadcrumbclass = "";
  $segments_quantity = $variables['segments_quantity'];
  $youarehere = t('You are here');
  $html = '<nav class="ecl-breadcrumbs " aria-label="breadcrumbs">';
  $html .= '<span class="ecl-u-sr-only">' . $youarehere . ':</span>';
  $html .= '<ol class="ecl-breadcrumbs__segments-wrapper">';
  foreach ($menu_crumbs as $value) {
    // Hide sitename on the homepage's breadcrumb.
    if (drupal_is_front_page() &&
      isset($value['#original_link']) &&
      $value['#original_link']['link_title'] === '[site:name]') {
      continue;
    }
    if (isset($value['#title'])) {
      $html .= '<li class="ecl-breadcrumbs__segment ecl-breadcrumbs__segment--first">';
      if (isset($value['#href'])) {
        $html .= l($value['#title'], $value['#href'], array('attributes' => array('class' => array('ecl-breadcrumbs__link ecl-link--inverted'))));
      }
      else {
        $html .= l($value['#title'], '#', $value['#href'], array('attributes' => array('class' => array('ecl-breadcrumbs__link ecl-link--inverted'))));
      }
      $html .= '</li>';
    }
  }
  if ($segments_quantity > 0) {
    for ($i = 0, $s = $segments_quantity - 1; $i < $segments_quantity; ++$i) {
      $it = $breadcrumb[$i];
      $it['class'][] = 'ecl-breadcrumbs__link ecl-link--inverted';
      $content = decode_entities($it['content']);
      if ($i == $s) {
        $breadcrumbclass = " ecl-breadcrumbs__segment--last";
      }
      $html .= '<li class="ecl-breadcrumbs__segment' . $breadcrumbclass . '">';
      if (isset($it['url'])) {
        $html .= l($content, $it['url'], array('attributes' => array('class' => $it['class'])));
      }
      else {
        $html .= $content;
      }
      $html .= '</li>';
    }
  }
  $html .= '</ol></nav>';
  return $html;
}
