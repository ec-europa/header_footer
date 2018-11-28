
# Header Footer Corporate

## Description

Gives available variables `$header__ec_corporate` and `$footer__ec_corporate availables` in your custom theme's *page.tpl.php* file.
You just have to print them at the right place (before and after the main content).

## How to include it in my website ?

Copy it in your *resources/site.make* file :

    projects[header_footer_corporate][subdir] = ec_europa
    projects[header_footer_corporate][download][type] = git
    projects[header_footer_corporate][download][url] = "https://github.com/ec-europa/header_footer_corporate.git"
    projects[header_footer_corporate][download][tag] = "v1.0.1"


## Note
Social Links of the footer are manageable by `/admin/structure/menu/manage/menu-footer-follow-us`

It is better to specify the tag to download, to know in your sources what version of the module you had downloaded.
