<div id="card">

  <?php 
    print $logo;
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

</div>
