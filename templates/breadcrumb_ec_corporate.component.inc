<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_easy_breadcrumb_breadcrumb_alter().
 */
function header_footer_corporate_easy_breadcrumb_breadcrumb_alter(array &$breadcrumb) {
  // Remove the last breadcrumb element for node pages.
  // ddl($breadcrumb, '$breadcrumb');
    global $language;
  // We have $breadcrumb without static items from "Breadcrumb menu".
  // We add this static items and programatically add the homepage link.
  // Menu items [123] + Homepage [homepage] + Breadcrumbs [456].
  // [456].

  // Clean data.
  foreach ($breadcrumb as $key => &$b) {
    // Unset item when no 'url' and not the last item.

    if(!isset($b['url']) && next($breadcrumb) !== FALSE){
      unset($breadcrumb[$key]);
      continue;
    }
    $class = array('ecl-breadcrumb__link', 'ecl-link ecl-link--standalone');
    if (isset($b['class'])) {

      $class = $class + $b['class'];
      // unset($b['class']);
    }
    $b['class'] = $class;
  }
  // [homepage][456].
  // Add programatically the homepage if there is no EasyBreadcrumb setting.
  if(!variable_get('easy_breadcrumb-include_home_segment', FALSE)){
    array_unshift($breadcrumb, array(
      'content' => variable_get('site_name'),
      'options' => array(
        'attributes' => array(
          'class' => array('ecl-breadcrumb__link', 'ecl-link ecl-link--standalone'),
        ),
      ),
      'url' => variable_get('site_frontpage', 'node'),
    ));
  }

  // [123][homepage][456].
  $static_breadcrumb = array();
  foreach (menu_tree('menu-breadcrumb-menu') as $mlid => $value) {
    if (!is_int($mlid)) {
      continue;
    }
    // Filter enabled items.
    if (!empty($value['#original_link']['hidden'])) {
      continue;
    }
    if (!in_array($value['#original_link']['language'], array(
      LANGUAGE_NONE,
      $language->language, language_default('language'),
    ))) {
      continue;
    }

    $static_breadcrumb[] = array(
      'content' => $value['#original_link']['title'],
      'class' => array('ecl-breadcrumb__link', 'ecl-link ecl-link--standalone'),
      'url' => $value['#original_link']['href'],
    );
  }
  foreach (array_reverse($static_breadcrumb) as $static_b) {
    array_unshift($breadcrumb, $static_b);
  }

  $variables['site_name'] = variable_get('site_name', 'Drupal');

  // Used in loop templating.
  $variables['i'] = 0;
  $variables['count'] = count($breadcrumb);

  // Classify current element.
  $last_breadcrumb = array_pop($breadcrumb);
   if(is_array($last_breadcrumb)) {
    $last_breadcrumb['options']['attributes']['class'][] = '';
  }
  $breadcrumb[] = $last_breadcrumb;
}
