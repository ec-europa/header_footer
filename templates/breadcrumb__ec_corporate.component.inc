<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_corporate_preprocess_breadcrumb__ec_corporate(&$variables, $hook) {
  global $language;
  // Used in loop templating.	
  $variables['i'] = $i = -1;	
  
  // We have $breadcrumb without static items from "Breadcrumb menu".
  // We add this static items and programatically add the homepage link.
  // Menu items [123] + Homepage [homepage] + Breadcrumbs [456].
  // [456].
  $breadcrumb = $variables['breadcrumb'];
  $variables['count'] = $count = count($variables['breadcrumb']);
  // Clean data.
  foreach ($breadcrumb as $key => &$b) {
    $i++;
    // Unset item when no 'url' and not the last item.
    if(empty($b['url']) && ($i < $count - 1) || empty($b['content'])){
      unset($breadcrumb[$key]);
      continue;
    }
    $class = array('ecl-breadcrumb__link', 'ecl-link ecl-link--standalone');
    if (isset($b['class'])) {
      $class = $class + $b['class'];
      unset($b['class']);
    }
    $b['options'] = array(
      'attributes' => array(
        'class' => $class,
      ),
    );
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
      'options' => array(
        'attributes' => array(
          'class' => array('ecl-breadcrumb__link', 'ecl-link ecl-link--standalone'),
        ),
      ),
      'url' => $value['#original_link']['href'],
    );
  }
  foreach (array_reverse($static_breadcrumb) as $static_b) {
    array_unshift($breadcrumb, $static_b);
  }

  // Copy last level to set page_title.
  $copy_last = array_slice($breadcrumb, -1);
  $variables['page_title'] = array_pop($copy_last)['content'];

  // Classify current element.
  $last_breadcrumb = array_pop($breadcrumb);
  $last_breadcrumb['options']['attributes']['class'][] = '';
  $breadcrumb[] = $last_breadcrumb;

  $variables['breadcrumb'] = $breadcrumb;
  $variables['count'] = count($breadcrumb);
}
