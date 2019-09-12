<?php

/**
 * @file
 * Templating for the header EC corporate.
 */

global $language;
?>
<header data-ecl-auto-init="SiteHeader" class="ecl-site-header" data-ecl-site-header="true">
  <div class="ecl-site-header__container ecl-container">
    <div class="ecl-site-header__banner">
      <a class="ecl-link ecl-link--standalone" href="https://ec.europa.eu/info/index_<?php print $language->language; ?>" aria-label="<?php print t('European Commission'); ?>">
        <img alt="<?php print t('European Commission logo'); ?>" title="<?php print t('European Commission'); ?>" class="ecl-site-header__logo-image" src="https://cdn1.fpfis.tech.ec.europa.eu/ecl/v2.11.0/ec-preset-legacy-website/images/logo/logo--<?php print $language->language; ?>.svg"/>
      </a>
      <div class="ecl-site-header__selector">
        <a class="ecl-link ecl-link--standalone ecl-site-header__selector-link" href="<?php print $language_switcher_url; ?>" data-ecl-language-selector="true"><?php print $language_switcher_label; ?><span class="ecl-site-header__language-icon"><svg focusable="false" aria-hidden="true" class="ecl-icon ecl-icon--m"><use xlink:href="https://cdn1.fpfis.tech.ec.europa.eu/ecl/v2.11.0/ec-preset-legacy-website/images/icons/sprites/icons.svg#general--language"></use></svg><span class="ecl-site-header__language-code"><?php print $language_switcher_code; ?></span></span></a>
      </div>
    </div>
    <?php print $ecl_search_block; ?>
  </div>
</header>
<div class="ecl-page-header">
  <div class="ecl-container">
    <?php print $easy_breadcrumb_block; ?>
    <div class="ecl-page-header__body">
      <div class="ecl-page-header__identity">
        <?php print $site_name; ?>
      </div>
    </div>
  </div>
</div>