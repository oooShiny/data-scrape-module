<?php

/**
 * @file
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['message']: Items for the message region.
 * - $page['content']: The main content of the current page.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see bartik_process_page()
 * @see html.tpl.php
 */
?>
<header>
  <nav class="cyan darken-2 z-depth-1" role="navigation">
    <?php
      global $user;
      $home = ($user->uid == 0 ? '/' : '/dashboard');
    ?>
    <div class="nav-wrapper container"><a id="logo-container" href="<?php print $home; ?>" class="brand-logo">Commissioner Tools</a>
      <?php print render($page['header']['views_og_user_groups-block_1']); ?>
    </div>
  </nav>
</header>


<main>
  <div class="container" style="padding-top: 1em">
    <?php if($is_admin || $node->type == 'commissioner_report') { print render($tabs); } ?>
    <?php
      $args = arg();
      if ($args[0] != 'dashboard') {
        print '<h1>' . $title . '</h1>';
      }
      ?>
    <?php print render($page['content']); ?>
  </div>
</main>


<footer class="page-footer blue-grey lighten-1">
  <div class="container">
    <div class="row">
      <div class="col l6 s6">
        <p class="grey-text text-lighten-4">Like it enough to part with a couple of bucks? <br><a href="https://paypal.me/arbrown83" target="_blank" class="btn">Donate!</a></p>
      </div>
      <div class="col l6 s6">
        <p class="grey-text text-lighten-4">All product and company names are trademarks or registered trademarks of their respective holders. Use of them does not imply any affiliation with or endorsement by them. In other words, I made this by myself.</p>
      </div>
    </div>
  </div>
  <div class="footer-copyright">
    <div class="container">
      &copy; <?php print date('Y'); ?> Commissioner Tools
      <a class="grey-text text-lighten-4 right" href="mailto:support@commissionertools.com?subject=Support Request&amp;body=I found a bug, when I was on the http://commissionertools.com/<?php print arg(0); ?> page!">Found a bug? Let me know!</a>
    </div>
  </div>
</footer>
