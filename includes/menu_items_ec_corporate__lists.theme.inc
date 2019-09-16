<?php

/**
 * @file
 * Redefines theme_links().
 */

/**
 * Returns HTML for a set of links.
 *
 * Same as theme_links() in /includes/themes.inc but with some changes.
 */
function theme_menu_items_ec_corporate__lists($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = (isset($variables['heading'])) ? $variables['heading'] : '';
  global $language_url;
  $output = '';
  // Conditional classes.
  if ($variables['attributes']['id'] == 'ecl-site-switcher') {
    $class_li = 'ecl-site-switcher__option';
    $classes_a = ['ecl-site-switcher__link', 'ecl-link'];
  }
  elseif ($variables['attributes']['id'] == 'ecl-footer-service-menu' || $variables['attributes']['id'] == 'ecl-footer-follow-ec-menu' || $variables['attributes']['id'] == 'ecl-footer-follow-us-menu') {
    $attributes['class'][] = 'ecl-list--inline';
    if ($variables['attributes']['id'] == 'ecl-footer-follow-us-menu') {
      $attributes['class'][] = 'ecl-footer__social-links';
    }
    $class_li = 'ecl-footer__menu-item';
    $classes_a = ['ecl-footer__link', 'ecl-link', 'ecl-link--inverted'];
  }
  else {
    $class_li = 'ecl-footer__menu-item';
    $classes_a = ['ecl-footer__link', 'ecl-link', 'ecl-link--inverted'];
  }
  if (count($links) > 0) {
    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }
    $output .= '<ul' . drupal_attributes($attributes) . '>';
    $num_links = count($links);
    $i = 1;
    foreach ($links as $key => $link) {
      $class = array($key, $class_li);
      // Add active class to site switcher.
      if ($i == $num_links && $variables['attributes']['id'] == 'ecl-site-switcher') {
        $class[] = 'ecl-site-switcher__option--is-selected';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
      && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';
      if (array_key_exists('attributes', $link) && array_key_exists('class', $link['attributes'])) {
        $link['attributes']['class'] = array_merge($link['attributes']['class'], $classes_a);
      }
      else {
        $link['attributes']['class'] = $classes_a;
      }
      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for
        // adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }
      $i++;
      $output .= "</li>\n";
    }
    $output .= '</ul>';
  }
  return $output;
}
