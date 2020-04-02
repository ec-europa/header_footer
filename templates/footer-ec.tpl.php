<?php

/**
 * @file
 * Templating for the footer EC.
 */
?>
<footer class="ecl-footer ecl-footer--custom">
  <?php
  // Custom footer: Non mandatory menus.
  if (!empty($ecl_footer_follow_us_menu) || !empty($ecl_footer_improved_men)): ?>
    <div class="ecl-footer__identity">
      <div class="ecl-container">
        <div class="ecl-row">
          <div class="ecl-col-12 ecl-col-md-4">
            <h1 class="ecl-footer__identity-title">
              <?php print $site_name; ?>
            </h1>
          </div>
          <div class="ecl-footer__identity-follow ecl-col-12 ecl-col-md-4">
            <?php print $ecl_footer_follow_us_menu; ?>
          </div>
          <div class="ecl-footer__identity-info ecl-col-12 ecl-col-md-4">
            <?php print $ecl_footer_identity_info; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>
  <?php /* Nexteuropa footer */ ?>
  <div class="ecl-footer__sections">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-footer__section ecl-col-12 ecl-col-md-4">
          <?php print $ecl_footer_ec_menu; ?>
        </div>
        <div class="ecl-footer__section ecl-col-12 ecl-col-md-4">
          <?php print $ecl_footer_follow_ec_menu; ?>
        </div>
        <div class="ecl-footer__section ecl-col-12 ecl-col-md-4">
          <?php print $ecl_footer_eu_menu; ?>
        </div>
      </div>
    </div>
  </div>
  <div class="ecl-footer__common">
    <div class="ecl-container ecl-footer__common-container">
      <?php print $ecl_footer_service_menu; ?>
    </div>
  </div>
</footer>
