# Changelog
## master-2.6 v3.3 (2021-26-03)
#### Addons
- Add European Commission segment.

## master-2.6 v3.0 (2020-12-03)
#### Bug fix
- Fix breadcrumb_ec_corporate.component.inc after update easy_breadcrumb.

## v2.3 (2020-23-04)
#### Addons
- Update public static function getAssetsPath value

## v2.2 (2020-11-03)
#### Addons
+ Adding i18n_menu as required module in .info file.
+ Adding 'templates' in the templates uri in function hook_theme().

## v2.0 (2019-11-05)
#### Addons
+ Adding version in .info file.
+ Hiding useless EasyBreadcrumb settings in admin form.

#### Bug fix
- Atomium compatibility
	- for v1.x users, needs to rename
		- templates
			- menu_items_ec_corporate__lists :arrow_right: menu_items_ec_corporate_lists
			- menu_items_ec_corporate__links :arrow_right: menu_items_ec_corporate_links
			- breadcrumb__ec_corporate :arrow_right: breadcrumb_ec_corporate
			- header__ec_corporate :arrow_right: header_ec_corporate
			- footer__ec_corporate :arrow_right: footer_ec_corporate
		- variables
			- `$header__ec_corporate` :arrow_right: `$header_ec_corporate`
			- `$footer__ec_corporate` :arrow_right: `$footer_ec_corporate`

## v1.0.10 (2019-09-26)
#### Addons
+ Adding version in .info file.

#### Bug fix
- PHP notices when empty menu items.

## v1.0.9 (2019-09-24)
#### Addons
+ Translations are setted in `header_footer_corporate.install.inc`. Do not hesitate to add/update if you know some missing translations.

## v1.0.8 (2019-09-18)
#### Bug Fix
- [#2](https://github.com/ec-europa/header_footer_corporate/issues/2) ECL compliance
Needs to update your Drupal database to update Corporate menus.
`drush updb` or go into `/update.php`
