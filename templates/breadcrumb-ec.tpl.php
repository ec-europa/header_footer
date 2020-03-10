<?php

/**
 * @file
 * Templating for the breadcrumb EC.
 */

use HeaderFooterCorporate\HeaderFooterCorporateHelpers;

?>
<nav class="ecl-page-header__breadcrumb ecl-breadcrumb" aria-label="<?php print \t('You are here:'); ?>" data-ecl-breadcrumb="true">
  <ol class="ecl-breadcrumb__container">
    <?php foreach ($breadcrumb as $value): ?>
      <?php if ($i < $count - 1): ?>
        <li class="ecl-breadcrumb__segment" data-ecl-breadcrumb-item="static" aria-hidden="false">
          <?php if (!empty($value['content']) && !empty($value['url'])) : ?>
            <?php print \l($value['content'], $value['url'], $value['options']); ?>
          <?php endif; ?>
          <svg focusable="false" aria-hidden="true"
            role="presentation" class="ecl-breadcrumb__icon ecl-icon ecl-icon--xs ecl-icon--rotate-90">
            <use xlink:href="<?php print HeaderFooterCorporateHelpers::getAssetsPath(); ?>/images/icons/sprites/icons.svg#ui--corner-arrow"></use>
          </svg>
        </li>
        <?php else: ?>
          <?php // Last element is the current. ?>
          <li class="ecl-breadcrumb__segment ecl-breadcrumb__current-page" aria-current="page" data-ecl-breadcrumb-item="static" aria-hidden="false"><?php print $value['content']; ?></li>
        <?php endif; ?>
      <?php $i++; ?>
    <?php endforeach; ?>
  </ol>
</nav>
<h1 class="ecl-page-header__title" aria-current="page"><?php print $page_title; ?></h1>
