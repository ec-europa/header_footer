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
  $path = 'https://ec.europa.eu/info/index_[language:language-content:language]';
  $link = array(
    'link_title' => 'European Commission website',
    'link_path' => $path,
    'menu_name' => 'menu-nexteuropa-site-links',
    'weight' => 0,
    'expanded' => 0,
    'menu_token_enabled' => 1,
    'customized' => 1,
    'options' => array(
      'menu_token_link_path' => $path,
      'menu_token_data' => array(),
      'menu_token_options' => array(
        'title_localize' => 0,
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
    ),
  );
  
  // Delete existing menu items.
  $mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $link['menu_name']))->fetchAll();
  if(!empty($mlids)){
    foreach($mlids as $record){
      menu_link_delete($record->mlid);
    }
  }
  // Adding new menu item.
  menu_link_save($link);
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
          $new_menu_item_config = array(
            'link_title' => $old_menu_item['link_title'],
            'link_path' => $old_menu_item['link_path'],
            'menu_name' => $migration_menu['new'],
            'customized' => 1,
            'weight' => $old_menu_item['weight'],
            'expanded' => $old_menu_item['expanded'],
            'options' => $old_menu_item['options'],
          );
          $new_menu_item = $new_menu_item_config;
          menu_link_save($new_menu_item);
          
          // Migrate translations.
          $languages = language_list('enabled')[1];
          foreach($languages as $lang_code => $language_object){
            if ($lang_code == language_default('language')) {
              continue;
            }
            
            $translation_value = i18n_string_translate('menu:item:'.$old_menu_item['mlid'].':title', $old_menu_item['link_title'], array('langcode' => $lang_code));
            if($translation_value != $old_menu_item['link_title']){
              i18n_string_translation_update('menu:item:'.$new_menu_item['mlid'].':title', $translation_value, $lang_code, $old_menu_item['link_title']);
            }
          }
        }
      }
      // Delete old menu.
      menu_delete(array('menu_name' => $migration_menu['old']));
    }
  }
}

/**
 * Breadcrumb: Update path of the Info website (using token).
 */
function _breadcrumb__main_link(){
  $mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name AND weight=0", array(':menu_name' => 'menu-breadcrumb-menu'))->fetchAll();
  if(!empty($mlids)){
    $path = 'https://ec.europa.eu/info/index_[language:language-content:language]';
    foreach($mlids as $record){
      $menu_item = menu_link_load($record->mlid);
      $menu_item['link_path'] = $path;
      $menu_item['menu_token_enabled'] = 1;
      $menu_item['options']['menu_token_link_path'] = $path;
      menu_link_save($menu_item);
    }
  }
}