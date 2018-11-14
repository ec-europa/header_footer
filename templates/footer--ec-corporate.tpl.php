<?php

/**
 * @file
 * Templating for the footer EC corporate.
 */
?>
<footer class="ecl-footer">
  <div class="ecl-footer__site-identity">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-sm ecl-footer__column">
          <h4 class="ecl-h4">
            <a class="ecl-link ecl-footer__link" href="#"><?php print $site_name; ?></a>
          </h4>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <?php echo $ecl_footer_follow_us_menu; ?>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <?php echo $ecl_footer_improved_menu; ?>
        </div>
      </div>
    </div>
  </div>
  <div class="ecl-footer__site-corporate">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-sm ecl-footer__column">
          <?php echo $ecl_footer_ec_menu; ?>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <?php echo $ecl_footer_follow_ec_menu; ?>
        </div>
        <div class="ecl-col-sm ecl-footer__column">
          <?php echo $ecl_footer_eu_menu; ?>
        </div>
      </div>
    </div>
  </div>
  <div class="ecl-footer__ec">
    <div class="ecl-container">
      <div class="ecl-row">
        <div class="ecl-col-sm ">
          <?php print $ecl_footer_service_menu; ?>
        </div>
      </div>
    </div>
  </div>
</footer>
