<?php

  $vars['logo']       = bizcard_build_page_logo($vars['logo']);
  $vars['hands']      = bizcard_build_hands();
  $vars['message']    = bizcard_markup_tag('div', $vars['messages'], array('id' => 'messages', 'class' => 'clearfix'));
  $vars['title']      = bizcard_markup_tag('h1', $vars['title'], array('id' => 'page-title'));
  $vars['main_menu']  = bizcard_build_page_main_menu($vars['main_menu']);
  $vars['tabs']       = bizcard_markup_tag('div', render($vars['tabs']), array('id' => 'tabs'));
  $vars['help']       = render($vars['page']['help']);
  $vars['content']    = render($vars['page']['content']);