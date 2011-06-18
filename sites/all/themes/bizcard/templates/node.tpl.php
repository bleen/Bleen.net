<div <?php print $node_attributes; ?>>

  <?php 
    print $title;
    print $date;
  ?>

  <div <?php print $content_attributes; ?>>
    <?php
      // We hide the comments so that we can render them later.
      hide($content['comments']);
      print render($content);
    ?>
  </div>

  <?php print render($content['comments']); ?>

</div>
