
Gives available variables `$header__ec_corporate` and `$footer__ec_corporate`  in your custom theme's *page.tpl.php* file and *maintenance-page.tpl.php*.
You just have to print them at the right place (before and after the main content).

    <?php print $header__ec_corporate; ?>
    <div>
	    ...
	    My template's content
	    ...
    </div>
    <?php print $footer__ec_corporate; ?>

## Header structure
|  |  | |
|--|--|--|
| **Site header** | Logo | Language switcher | Search bar |
| **Page header** | Breadcrumb | | |
|  | Page title | | |

## Footer structure
| | | | |
|--|--|--|--|
| **CUSTOM** | Site name  | `menu-footer-follow-us` | `menu-footer-right` |
| **CORPORATE** | `'menu-nexteuropa-site-links'` | `'menu-nexteuropa-social-media'` | `'menu-nexteuropa-inst-links'` | 


# How to include it in my website ?

Copy it in your **resources/site.make** file :

    projects[header_footer_corporate][subdir] = custom/ec_europa
    projects[header_footer_corporate][download][type] = git
    projects[header_footer_corporate][download][url] = "https://github.com/ec-europa/header_footer_corporate.git"
    projects[header_footer_corporate][download][tag] = "v1.0.10"
and run the command `./toolkit/phing build-subsite-dev`

> *"v1.0.10" is just an example
It is better to specify the tag to download, to know in your sources what version of the module you had downloaded.*

# Manageable links
## Social links
Social links of the footer are manageable in `/admin/structure/menu/manage/menu-footer-follow-us`.
## Right footer links
Links of the right footer are manageable in `/admin/structure/menu/manage/menu-footer-right`.
