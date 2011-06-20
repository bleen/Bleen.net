<div id="card" class="clearfix">

  <?php 
    print $logo;
    print $main_menu;
    print $messages;
  ?>

  <?php if ($content): ?>
    <div id="content" class="clearfix">
    <?php 
      print $title;
      print $tabs;
      print $help;
      print $content;
      print $feed_icons;
    ?>
    </div>
  <?php endif; ?>

  <?php
    print $hands;
  ?>
</div>

<div class="copyright">&copy; <?php print date('Y'); ?> Alex Ross</div>