<?php
/**
 * @file
 * Contains install/update/enable custom functions.
 */

/**
 * Footer left links: Delete existing and set according config.
 */
function _footer__left_links__clean_set(){
  // The item to add.
  $link = array(
    'link_title' => 'European Commission website',
    'link_path' => 'https://ec.europa.eu/info/index',
    'menu_name' => 'menu-nexteuropa-site-links',
    'weight' => 0,
    'expanded' => 0,
    'options' => array(),
  );
  
  // Delete existing menu items.
  $mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $link['menu_name']))->fetchAll();
  if(!empty($mlids)){
    foreach($mlids as $record){
      menu_link_delete($record->mlid);
    }
  }
  // Adding new menu item.
  $languages = language_list('enabled')[1];
  if(!empty($languages)){
    $original_link = $link;
    foreach($languages as $language){
      $link = $original_link;
      $link['language'] = $language->language;
      $link['link_path'] .= '_'.$language->language;
      menu_link_save($link);
    }
  }
  else{
    menu_link_save($link);
  }
}

/**
 * Footer links: Copy links from custom menus (used in MARE sites) to our menus.
 */
function _footer__center_right_copy_links(){
  $migration_menus = array(
    array(
      'old' => 'menu-improved-follow-us',
      'new' => 'menu-footer-follow-us',
    ),
    array(
      'old' => 'menu-improved',
      'new' => 'menu-footer-right',
    ),
  );
  
  foreach($migration_menus as $migration_menu){
    $old_menu = menu_load($migration_menu['old']);
    if(isset($old_menu)){
      $old_mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $migration_menu['old']))->fetchAll();
      if(!empty($old_mlids)){
        // Clean existing items in new menu.
        $new_mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $migration_menu['new']))->fetchAll();
        if(!empty($new_mlids)){
          foreach($new_mlids as $record){
            menu_link_delete($record->mlid);
          }
        }
        // Copy old to new menu.
        foreach($old_mlids as $record){
          $old_menu_item = menu_link_load($record->mlid);
          $new_menu_item = array(
            'link_title' => $old_menu_item['link_title'],
            'link_path' => $old_menu_item['link_path'],
            'menu_name' => $migration_menu['new'],
            'weight' => $old_menu_item['weight'],
            'expanded' => $old_menu_item['expanded'],
            'options' => $old_menu_item['options'],
          );
          menu_link_save($new_menu_item);
        }
      }
      // Delete old menu.
      menu_delete(array('menu_name' => $migration_menu['old']));
    }
  }
}