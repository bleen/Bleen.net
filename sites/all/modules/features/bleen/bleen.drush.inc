<?php

/**
 * Implementation of hook_drush_command().
 */
function bleen_drush_command() {
  $items['bleen-export-comments'] = array(
    'description' => 'Export existing comments to a WXR file.',
    'arguments' => array(
      'file-name' => 'The name of the WXR file (ex: comments.wxr).',
    ),
    'examples' => array(
      'drush bec comments.wxr' => 'Export all comments to a local file called comments.wxr.',
    ),
    'aliases' => array('bec'),
  );

  return $items;
}

/**
 * Run the bleen-export-comments command.
 * @param string $filename
 */
function drush_bleen_export_comments($filename = 'comments.wxr') {
  drush_print(dt('Preparing to export comments to !filename', array('!filename' => $filename)));

  // Write xml header
  $output = <<<EOT
<?xml version="1.0" encoding="UTF-8"?>
<rss version="2.0"
  xmlns:content="http://purl.org/rss/1.0/modules/content/"
  xmlns:dsq="http://www.disqus.com/"
  xmlns:dc="http://purl.org/dc/elements/1.1/"
  xmlns:wp="http://wordpress.org/export/1.0/"
>
  <channel>
EOT;

  // Get all nodes.
  $nodes = db_query("SELECT * FROM {node} AS n INNER JOIN {node_revision} AS nr ON n.vid = nr.vid WHERE n.type = 'article'")->fetchAllKeyed();
  foreach ($nodes as $nid) {
    $node = node_load($nid);

    // Get comments for the given node.
    $comments = db_query("SELECT c.*, u.name AS username, u.mail AS usermail FROM {comment} AS c INNER JOIN {users} AS u ON c.uid = u.uid WHERE c.nid=:nid", array(':nid' => $node->nid))->fetchAll();
    if (empty($comments)) {
      continue;
    }

    $alias = drupal_get_path_alias("node/" . $node->nid);
    $url = "http://bleen.net/" . $alias;
    $tid = "node-{$node->nid}";
    $date = gmdate('Y-m-d H:i:s', $node->created);
    $content = substr($node->teaser,0,100);

    $output .= <<<EOT
    <item>
      <title>{$node->title}</title>
      <link>$url</link>
      <content:encoded><![CDATA[{$content}]]></content:encoded>
      <dsq:thread_identifier>$alias</dsq:thread_identifier>
      <wp:post_date_gmt>$date</wp:post_date_gmt>
      <wp:comment_status>open</wp:comment_status>
EOT;

    foreach ($comments as $c) {
      $comment = comment_load($c->cid);
      $user_url = "http://bleen.net/" . "user/{$comment->uid}";
      $ip = $comment->hostname ? $comment->hostname : '127.0.0.1';
      $date = gmdate('Y-m-d H:i:s', $comment->created);
      $approved = 1;

      $mail = (!empty($comment->mail) ? $comment->mail : $c->usermail);
      $name = (!empty($comment->name) ? $comment->name : $c->username);

      //$mail = $name == 'bleen' ? 'disqus.119x@bleen.net' : $mail;
      $mail = !empty($mail) ? $mail : 'anon@anonymous.com';
      $name = !empty($name) ? $name : 'Anonymous';

      $output .= <<<EOT
      <wp:comment>
        <wp:comment_id>{$comment->cid}</wp:comment_id>
        <wp:comment_author>{$name}</wp:comment_author>
        <wp:comment_author_email>{$mail}</wp:comment_author_email>
        <wp:comment_author_url>{$user_url}</wp:comment_author_url>
        <wp:comment_author_IP>{$ip}</wp:comment_author_IP>
        <wp:comment_date_gmt>{$date}</wp:comment_date_gmt>
        <wp:comment_content><![CDATA[{$comment->comment_body[LANGUAGE_NONE][0]['safe_value']}]]></wp:comment_content>
        <wp:comment_approved>{$approved}</wp:comment_approved>
        <wp:comment_parent>{$comment->pid}</wp:comment_parent>
      </wp:comment>
EOT;
    }

    $output .= "    </item>\n";

  }

  $output .= "  </channel>\n";
  $output .= "</rss>\n";


  if (file_put_contents($filename, $output)) {
    drush_print(dt('Successfully exported comments to !filename', array('!filename' => $filename)));
  }
  else {
    drush_print(dt('An error occurred writing to !filename', array('!filename' => $filename)));
  }

}
