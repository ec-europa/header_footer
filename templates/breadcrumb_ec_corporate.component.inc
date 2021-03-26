<?php

/**
 * @file
 * Contains component file.
 */

/**
* Implements hook_preprocess_HOOK().
*/
function header_footer_corporate_preprocess_breadcrumb_ec_corporate(&$variables, $hook) {

  // Used in loop templating.
  $variables['i'] = 0;
  $variables['count'] = count($variables['breadcrumb']);
  $variables['site_name'] = variable_get('site_name', 'Drupal');
}

/**
 * Implements hook_easy_breadcrumb_breadcrumb_alter().
 */
function header_footer_corporate_easy_breadcrumb_breadcrumb_alter(array &$breadcrumb) {
  // Remove the last breadcrumb element for node pages.
  global $language;
  // We have $breadcrumb without static items from "Breadcrumb menu".
  // We add this static items and programatically add the homepage link.
  // Menu items [123] + Homepage [homepage] + Breadcrumbs [456].
  // [456].

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

  //Add European Commission segment.
  if(theme_get_setting('enable_interinstitutional_theme')) {
        array_unshift($breadcrumb, array(
        'content' =>  l(t('European Commission'),
          url('https://ec.europa.eu/info/index',array('absolute'=>TRUE)),
          array('attributes'=>array('class'=> 'ecl-breadcrumb__link ecl-link ecl-link--standalone'))),
      ));
    }

  // Clean data.
  foreach ($breadcrumb as $key => &$b) {

    $class = array('ecl-breadcrumb__link', 'ecl-link ecl-link--standalone');
    if (isset($b['class'])) {
      $class = $class + $b['class'];
    }
    $b['class'] = $class;
  }

  // Classify current element.
  $last_breadcrumb = array_pop($breadcrumb);
  if(is_array($last_breadcrumb)) {
    // https://github.com/ec-europa/header_footer/issues/28
    // There is an issue here as easy_breacrumd retrieve the title
    // from the url with language suffix so $last_breadcrumb['content']
    // can't be used.
    $last_breadcrumb = array(
      'content' => drupal_get_title(),
      'class' => array('ecl-breadcrumb__current-page'),
    );
  }
  $breadcrumb[] = $last_breadcrumb;
}
