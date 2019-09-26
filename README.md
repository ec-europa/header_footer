Gives available variables `$header__ec_corporate` and `$footer__ec_corporate`  in your custom theme's *page.tpl.php* file and *maintenance-page.tpl.php*.
You just have to print them at the right place (before and after the main content).

    <?php print $header__ec_corporate; ?>
    <div>
	    ...
	    My template's content
	    ...
    </div>
    <?php print $footer__ec_corporate; ?>

The module uses [ECL](https://ec.europa.eu/component-library/ec/)

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
    projects[header_footer_corporate][download][tag] = "v1.0.10"
> *"v1.0.10" is just an example
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

[fixed items from `menu-breadcrumb-menu`] **>** [Homepage *(programmatically built)*] **>** [Dynamic breadcrumb *(provided by easy_breadcrumb)*]

> Each fixed item have to be in **Language neutral** and its translations by
> Localization not Translation: it means to not create new menu items in
> different languages.
