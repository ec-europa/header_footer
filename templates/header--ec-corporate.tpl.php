<?php

/**
 * @file
 * Templating for the header EC corporate.
 */
?>
<header class="ecl-site-header" role="banner">
  <div class="ecl-container ecl-site-header__banner">
    <a href="https://ec.europa.eu" class="ecl-logo ecl-logo--logotype ecl-site-header__logo" title="<?php print t('Home - European Commission'); ?>">
      <span class="ecl-u-sr-only"><?php print t('Home - European Commission'); ?></span>
    </a>
    <div class="ecl-language-list ecl-language-list--overlay ecl-site-header__language-list">
      <div id="ecl-overlay-language-list" class="ecl-dialog__overlay ecl-dialog__overlay--blue" aria-hidden="true"></div>
      <div class="ecl-lang-select-sites ecl-link" data-ecl-dialog="ecl-dialog" id="ecl-lang-select-sites__overlay">
        <a href="<?php print $language_switcher_url; ?>" class="ecl-lang-select-sites__link"><span class="ecl-lang-select-sites__label"><?php print $language_switcher_label; ?></span><span class="ecl-lang-select-sites__code"><span class="ecl-icon ecl-icon--language ecl-lang-select-sites__icon"></span><span class="ecl-lang-select-sites__code-text"><?php print $language_switcher_code; ?></span></span></a>
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
