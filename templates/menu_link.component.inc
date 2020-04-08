<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function header_footer_preprocess_menu_link(&$variables) {
  /* Check if the url in the menu is present in the current page alias
  in order to add active class on LI items. */
  $current_node_alias = drupal_get_path_alias();
  $menu_item_state = 'active';
  $href_node_alias = drupal_get_path_alias($variables['element']['#href']);
  if (preg_match("!\b$href_node_alias\b!", $current_node_alias)) {
    /* This if block is a workaround
    for the level 0 menu items that are repeated on the level 1.*/
    if (
      $href_node_alias != $current_node_alias &&
      // If the current menu item url is not the current page url.
      $variables['element']['#original_link']['depth'] == 0 &&
      // If we're not on level 0.
      menu_link_get_preferred(current_path(), 'main-menu') != NULL
      // If the current page is not on the main menu.
    ) {
      $menu_item_state = '';
      // Cancel the active class.
    } // end of workaround
    $variables['element']['#attributes']['class'][] = $menu_item_state;
  }
}
