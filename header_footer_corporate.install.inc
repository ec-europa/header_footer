<?php

/**
 * @file
 * Contains install/update/enable custom functions.
 */

/**
 * Get links config.
 */
function _get_links_config() {
  return array(
    array(
      array(
        'link_title' => 'RSS',
        'link_path' => 'https://ec.europa.eu/YOUR_DG/rss.xml',
        'menu_name' => 'menu-footer-follow-us',
        'weight' => 0,
      ),
      array(
        'link_title' => 'Twitter',
        'link_path' => 'https://twitter.com/YOUR_DG',
        'menu_name' => 'menu-footer-follow-us',
        'weight' => 1,
      ),
      array(
        'link_title' => 'Facebook',
        'link_path' => 'https://www.facebook.com/YOUR_DG',
        'menu_name' => 'menu-footer-follow-us',
        'weight' => 2,
      ),
      array(
        'link_title' => 'YouTube',
        'link_path' => 'https://www.youtube.com/user/YOUR_DG',
        'menu_name' => 'menu-footer-follow-us',
        'weight' => 3,
      ),
    ),
    array(
      array(
        'link_title' => 'European Commission website',
        'link_path' => 'https://ec.europa.eu/info/index_[language:language-content:language]',
        'menu_name' => 'menu-nexteuropa-site-links',
        'weight' => 0,
        'menu_token_enabled' => 1,
        'customized' => 1,
        'options' => array(
          'menu_token_link_path' => 'https://ec.europa.eu/info/index_[language:language-content:language]',
          'menu_token_data' => array(),
          'menu_token_options' => array(
            'title_localize' => 0,
            'clear' => 0,
          ),
          'attributes' => array(
            'title' => '',
          ),
        ),
      ),
    ),
    array(
      array(
        'link_title' => 'Facebook',
        'link_path' => 'https://www.facebook.com/EuropeanCommission',
        'menu_name' => 'menu-nexteuropa-social-media',
        'weight' => 0,
      ),
      array(
        'link_title' => 'Twitter',
        'link_path' => 'https://twitter.com/eu_commission',
        'menu_name' => 'menu-nexteuropa-social-media',
        'weight' => 1,
      ),
      array(
        'link_title' => 'Other social networks',
        'link_path' => 'http://ec.europa.eu/dgs/communication/services/journalist/social-media_en.htm',
        'menu_name' => 'menu-nexteuropa-social-media',
        'weight' => 2,
        'customized' => 1,
      ),
    ),
    array(
      array(
        'link_title' => 'European Union',
        'link_path' => 'https://europa.eu/european-union/index',
        'menu_name' => 'menu-nexteuropa-inst-links',
        'weight' => 0,
        'customized' => 1,
      ),
      array(
        'link_title' => 'EU institutions',
        'link_path' => 'https://europa.eu/european-union/about-eu/institutions-bodies',
        'menu_name' => 'menu-nexteuropa-inst-links',
        'weight' => 1,
        'customized' => 1,
      ),
    ),
    array(
      array(
        'link_title' => 'About the Commission\'s new web presence',
        'link_path' => 'https://ec.europa.eu/info/about-commissions-new-web-presence',
        'menu_name' => 'menu-nexteuropa-service-links',
        'weight' => -100,
        'customized' => 1,
      ),
      array(
        'link_title' => 'Language policy',
        'link_path' => 'https://ec.europa.eu/info/language-policy',
        'menu_name' => 'menu-nexteuropa-service-links',
        'weight' => -90,
        'customized' => 1,
      ),
      array(
        'link_title' => 'Resources for partners',
        'link_path' => 'http://ec.europa.eu/info/resources-partners',
        'menu_name' => 'menu-nexteuropa-service-links',
        'weight' => -80,
        'customized' => 1,
      ),
      array(
        'link_title' => 'Cookies',
        'link_path' => 'https://ec.europa.eu/info/cookies',
        'menu_name' => 'menu-nexteuropa-service-links',
        'weight' => -70,
        'customized' => 1,
      ),
      array(
        'link_title' => 'Privacy policy',
        'link_path' => 'https://ec.europa.eu/info/privacy-policy',
        'menu_name' => 'menu-nexteuropa-service-links',
        'weight' => -60,
        'customized' => 1,
      ),
      array(
        'link_title' => 'Legal notice',
        'link_path' => 'https://ec.europa.eu/info/legal-notice',
        'menu_name' => 'menu-nexteuropa-service-links',
        'weight' => -50,
        'customized' => 1,
      ),
      array(
        'link_title' => 'Contact',
        'link_path' => 'https://ec.europa.eu/info/contact',
        'menu_name' => 'menu-nexteuropa-service-links',
        'weight' => -40,
        'customized' => 1,
      ),
    ),
  );
}

/**
 * Get links config by menu name.
 */
function _get_links_config_of_menu($menu_name) {
  foreach (_get_links_config() as $config_menu) {
    foreach ($config_menu as $config_item) {
      if ($config_item['menu_name'] != $menu_name) {
        continue;
      }
      else {
        return $config_menu;
      }
    }
  }
}

/**
 * Get translation used in the module.
 */
function _get_translations($params = array()) {
  $data = array(
    'menu_item' => array(
      'European Commission' => array(
        'bg' => 'Европейска комисия',
        'cs' => 'Evropská komise',
        'da' => 'Europa-Kommissionen',
        'de' => 'Europäische Kommission',
        'et' => 'Euroopa Komisjon',
        'el' => 'Ευρωπαϊκή Επιτροπή',
        'en' => 'European Commission',
        'es' => 'Comisión Europea',
        'fr' => 'Commission européenne',
        'it' => 'Commissione europea',
        'lv' => 'Eiropas Komisija',
        'lt' => 'Europos Komisija',
        'hu' => 'Európai Bizottság',
        'mt' => 'Il-Kummissjoni Ewropea',
        'nl' => 'Europese Commissie',
        'pl' => 'Komisja Europejska',
        'pt' => 'Comissão Europeia',
        'ro' => 'Comisia Europeană',
        'fi' => 'Euroopan komissio',
        'sk' => 'Európska komisia',
        'sl' => 'Evropska komisija',
        'sv' => 'Europeiska kommissionen',
      ),
      'Other social networks' => array(
        'en' => 'Other social networks',
        'fr' => 'Autres réseaux sociaux',
      ),
    ),
    'default' => array(
      'Follow us:' => array(
        'en' => 'Follow us:',
        'fr' => 'Nous suivre:',
      ),
      'European Commission' => array(
        'en' => 'European Commission',
        'fr' => 'Commission Européenne',
      ),
      'Follow the European Commission' => array(
        'en' => 'Follow the European Commission',
        'fr' => 'Suivre la Commission Européenne',
      ),
      'European Union' => array(
        'en' => 'European Union',
        'fr' => 'Union Européenne',
      ),
    ),
  );
  if (empty($params)) {
    return $data;
  }
  elseif (isset($params['context'])) {
    if (empty($params['text_original'])) {
      return $data[$params['context']];
    }
    else {
      return $data[$params['context']][$params['text_original']];
    }
  }
}

/**
 * Set translations of menu_item.
 */
function _set_translations($data = array()) {
  $translations = _get_translations($data);
  if (empty($translations)) {
    return FALSE;
  }
  // Set all translations of one context with recursive call.
  if (!isset($data['text_original']) && isset($data['context'])) {
    foreach (array_keys($translations) as $text_original) {
      _set_translations(array(
        'text_original' => $text_original,
        'context' => $data['context'],
      ));
    }
    return TRUE;
  }

  // Set one translation .
  $languages = language_list('enabled')[1];
  foreach ($languages as $lang_code => $language_object) {
    if ($lang_code == language_default('language')) {
      continue;
    }
    if (!empty($translations[$lang_code])) {
      // Built-in interface.
      $context = 'default';
      if ($data['context'] == 'menu_item') {
        if (!empty($data['mlid'])) {
          $context = 'menu:item:' . $data['mlid'] . ':title';
          i18n_string_translation_update($context, $translations[$lang_code], $lang_code, $data['text_original']);
        }
      }
      else {
        // Without context, have to use Local and not i18n.
        // Translate strings.
        $report = array(
          'skips' => 0,
          'updates' => 0,
          'deletes' => 0,
          'additions' => 0,
        );
        _locale_import_one_string_db($report, $lang_code, '', $data['text_original'], $translations[$lang_code], 'default', '', LOCALE_IMPORT_OVERWRITE);
      }
    }
  }
}

/**
 * Footer links: Copy links from custom menus (used in MARE sites) to our menus.
 */
function _footer__custom_right_copy_links() {
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
  foreach ($migration_menus as $migration_menu) {
    $old_menu = menu_load($migration_menu['old']);
    if (isset($old_menu)) {
      $old_mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $migration_menu['old']))->fetchAll();
      if (!empty($old_mlids)) {
        // Clean existing items in new menu.
        $new_mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $migration_menu['new']))->fetchAll();
        if (!empty($new_mlids)) {
          foreach ($new_mlids as $record) {
            menu_link_delete($record->mlid);
          }
        }
        // Copy old to new menu.
        foreach ($old_mlids as $record) {
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
          foreach ($languages as $lang_code => $language_object) {
            if ($lang_code == language_default('language')) {
              continue;
            }

            $translation_value = i18n_string_translate('menu:item:' . $old_menu_item['mlid'] . ':title', $old_menu_item['link_title'], array('langcode' => $lang_code));
            if ($translation_value != $old_menu_item['link_title']) {
              i18n_string_translation_update('menu:item:' . $new_menu_item['mlid'] . ':title', $translation_value, $lang_code, $old_menu_item['link_title']);
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
 * Reset menu according actual config.
 */
function _reset_menu_to_config($menu_name) {
  // Delete existing menu items.
  $mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $menu_name))->fetchAll();
  if (!empty($mlids)) {
    foreach ($mlids as $record) {
      menu_link_delete($record->mlid);
    }
  }
  // Adding new menu items according config.
  $items = _get_links_config_of_menu($menu_name);
  foreach ($items as $link) {
    menu_link_save($link);
  }
}

/**
 * Clean custom attributes of each item.
 */
function _delete_menu_items_attributes($menu_name) {
  // Delete existing attributes of each menu items.
  $mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $menu_name))->fetchAll();
  if (!empty($mlids)) {
    foreach ($mlids as $record) {
      $menu_item = menu_link_load($record->mlid);
      $menu_item['options'] = array();
      menu_link_save($menu_item);
    }
  }
}

/**
 * Breadcrumb: Create/Update breadcrumb root and its translations.
 */
function _breadcrumb__main_link() {
  // The European Commission website is always the root of our breadcrumb.
  // Update case:
  $path = 'https://ec.europa.eu/info/index_[language:language-content:language]';
  $root_title = 'European Commission';
  $menu_name = 'menu-breadcrumb-menu';
  $mlids = db_query("SELECT mlid from {menu_links} WHERE menu_name=:menu_name", array(':menu_name' => $menu_name))->fetchAll();
  if (!empty($mlids)) {
    foreach ($mlids as $record) {
      $menu_item = menu_link_load($record->mlid);
      if ($menu_item['link_title'] == $root_title) {
        if ($menu_item['language'] == 'und'  && $menu_item['hidden'] == 0) {
          // Update the link.
          $menu_item['link_path'] = $path;
          $menu_item['menu_token_enabled'] = 1;
          $menu_item['options']['menu_token_link_path'] = $path;
          $root_mlid = menu_link_save($menu_item);
        }
      }
    }
  }
  else {
    // Needs to create item.
    $root_menu_item_default_data = array(
      'link_title' => $root_title,
      'link_path' => $path,
      'menu_name' => $menu_name,
      'weight' => 0,
      'expanded' => 0,
      'menu_token_enabled' => 1,
      'customized' => 1,
      'language' => 'und',
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
    $root_mlid = menu_link_save($root_menu_item_default_data);
  }
  _set_translations(array(
    'text_original' => $root_title,
    'context' => 'menu_item',
    'mlid' => $root_mlid,
  ));
}
