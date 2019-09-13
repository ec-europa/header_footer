<?php

/**
 * @file
 * Templating for the breadcrumb EC corporate.
 */
?>
<div class="ecl-page-header">
  <div class="ecl-container">
    <nav class="ecl-page-header__breadcrumb ecl-breadcrumb" aria-label="<?php print t('You are here:'); ?>" data-ecl-breadcrumb="true">
      <ol class="ecl-breadcrumb__container">
        <?php foreach($breadcrumb as $value): ?>
          <li class="ecl-breadcrumb__segment" data-ecl-breadcrumb-item="static" aria-hidden="false">
            <?php if($i < $count - 1): ?>
              <?php print l($value['content'], $value['url'], $value['options']); ?>
              <svg focusable="false" aria-hidden="true"
                role="presentation" class="ecl-breadcrumb__icon ecl-icon ecl-icon--xs ecl-icon--rotate-90">
                <use xlink:href="/component-library/dist/media/icons.a11fa655.svg#ui--corner-arrow"></use>
              </svg>
            <?php else: ?>
              <?php // Change ECLv2.11: Adding link adapted to website usages. ?>
              <li class="ecl-breadcrumb__segment" data-ecl-breadcrumb-item="static" aria-hidden="false"><?php print l($value['content'], $value['url'], $value['options']); ?></li>
            <?php endif; ?>
          </li>
          <?php $i++; ?>
        <?php endforeach; ?>
      </ol>
    </nav>
    <h1 class="ecl-page-header__title" aria-current="page"><?php print $page_title; ?></h1>
  </div>
</div>