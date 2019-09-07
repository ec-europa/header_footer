<?php
/**
 * @file
 * Contains install/update/enable custom functions.
 */

/**
 * Footer links: Copy links from custom menus (used in MARE sites) to our menus.
 */
function _footer__copy_links(){
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