<?php

/**
 * @file
 * Templating for the menu items EC corporate displayed as links.
 */
?>

<?php print render($heading_markup); ?>

<?php foreach($links as $link): ?>
  <a href="<?php print $link['href'];?>" class="ecl-footer__identity-link ecl-link ecl-link--standalone ecl-link--icon ecl-link--icon-before">
    <?php print $link['icon']; ?>
    <span class="ecl-link__label"><?php print $link['title']; ?></span>
  </a>
<?php endforeach; ?>