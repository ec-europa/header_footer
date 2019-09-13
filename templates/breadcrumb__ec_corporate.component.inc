<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_corporate_preprocess_breadcrumb__ec_corporate(&$variables, $hook) {
  // We have $breadcrumb without "Breadcrumb menu" items. So we add the homepage
  // to them and update the last item to flag it as current-page.
  // Menu items [123] + Homepage [homepage] + Breadcrumbs [456].
  // [456].
  $breadcrumb = $variables['breadcrumb'];
  // Clean data.
  foreach($breadcrumb as &$b){
    $class = '';
    if(isset($b['class'])){
      $class = implode(' ', $b['class']);
      unset($b['class']);
    }
    $b['options'] = array(
      'attributes' => array(
        'class' => $class
      ),
    );
  }
  // [homepage][456].
  array_unshift($breadcrumb, array(
    'content' => variable_get('site_name'),
    'options' => array(
      'attributes' => array(
        'class' => 'ecl-breadcrumb__link ecl-link ecl-link--standalone',
      ),
    ),
    'url' => variable_get('site_frontpage', 'node'),
  ));
  // [123][homepage][456].
  foreach(menu_tree_all_data('menu-breadcrumb-menu') as $value){
    array_unshift($breadcrumb, array(
      'content' => $value['link']['title'],
      'options' => array(
        'attributes' => array(
          'class' => 'ecl-breadcrumb__link ecl-link ecl-link--standalone',
        ),
      ),
      'url' => $value['link']['href'],
    ));
  }
  // Remove last level to set page_title.
  $variables['page_title'] = array_pop($breadcrumb)['content'];
  // Used in loop templating.
  $variables['i'] = 0;
  $variables['count'] = count($breadcrumb);
  // Change ECLv2.11: Adding link adapted to website usages.
  if($variables['count'] > 1){
    $last_breadcrumb = array_pop($breadcrumb);
    $last_breadcrumb['options']['attributes']['class'] .= ' ecl-breadcrumb__current-page';
    $breadcrumb[] = $last_breadcrumb;
  }
  $variables['breadcrumb'] = $breadcrumb;
}