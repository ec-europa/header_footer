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
function _header_footer_theme_breadcrumb(&$variables) {
  return theme('breadcrumb_ec', $variables);
}
