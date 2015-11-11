<?php
/**
 * Adding OG ID to Power Rankings block for code export.
 */

$node = node_load(arg(1));
$content['field_power_rankings'][0]['#view_arguments'] = $node->og_group_ref['und'][0]['target_id'];
?>
[b]<?php print $content['field_power_rankings']['#title']; ?>[/b]
<br>
<?php
$table = render($content);
// Remove extra header.
$table = str_replace('<h3>Power Rankings</h3>', '', $table);
// Replace Commish Tools table classes with ESPN's.
$table = str_replace(
  '<table class="views-table cols-4" >
            <thead>
            <tr>',
  '<table width="100%" border="0" cellpadding="2" cellspacing="1" class="tableBody" bgcolor="#ffffff"><tbody><tr class="tableSubHead" bgcolor="#6dbb75">',
  $table);

$table = str_replace('<', '&lt;', $table);
$table = str_replace('>', '&gt;', $table);
print $table;
?>
<br>
