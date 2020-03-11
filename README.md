

Gives available variables `$header_ec_corporate` and `$footer_ec_corporate`  in your custom theme's ***page.tpl.php*** file and ***maintenance-page.tpl.php***.
You just have to print them at the right place (before and after the main content) :

    <?php if (isset($header_ec_corporate)): ?>
	  <?php print $header_ec_corporate; ?>
    <?php endif; ?>
    
	<!-- Template content -->
	...
	<!-- /Template content -->
	
    <?php if (isset($footer_ec_corporate)): ?>
	  <?php print $footer_ec_corporate; ?>
    <?php endif; ?>

The module uses [ECL](https://ec.europa.eu/component-library/ec/) version 2.

## Header structure
|  |  | |
|--|--|--|
| **Site header :** | Logo | Language switcher | Search bar |
| **Page header :** | Breadcrumb | | |
|  | Page title | | |

## Footer structure
| | | | |
|--|--|--|--|
| **CUSTOM :** *(can be edited)*| Site name  | `menu-footer-follow-us` | `menu-footer-right` |
| **CORPORATE :** *(have not to be edited)* | `'menu-nexteuropa-site-links'` | `'menu-nexteuropa-social-media'` | `'menu-nexteuropa-inst-links'` | 


#  How to include the module using [Toolkit](https://github.com/ec-europa/toolkit) ?

 1. Copy it in your **resources/site.make** file :

    projects[header_footer_corporate][subdir] = custom/ec_europa
    projects[header_footer_corporate][download][type] = git
    projects[header_footer_corporate][download][url] = "https://github.com/ec-europa/header_footer_corporate.git"
    projects[header_footer_corporate][download][tag] = "2.2"
> *"2.2" is just an example
It is better to hardcode the tag to not have unwanted updates when you will rebuild your subsite.*

 2. Run the command `./toolkit/phing build-subsite-dev`

# Manageable links

## Social links
Social links of the footer are manageable in `/admin/structure/menu/manage/menu-footer-follow-us`.

## Right footer links
Links of the right footer are manageable in `/admin/structure/menu/manage/menu-footer-right`.

##  Breadcrumb
The breadcrumb menu is manageable in `/admin/structure/menu/manage/menu-breadcrumb-menu`.
Here is how the breadcrumb is built:

 1. fixed items from `menu-breadcrumb-menu`
 Each fixed item have to be in **Language neutral** and its translations by Localization not Translation: it means to not create different menu items in different languages.
 2. Homepage
 If EasyBreadcrumb setting "*Include the front page as a segment in the breadcrumb*" available in `/admin/config/user-interface/easy-breadcrumb` is not checked, the link is **programmatically built**
  3. Dynamic breadcrumb
  Provided by easy_breadcrumb.
