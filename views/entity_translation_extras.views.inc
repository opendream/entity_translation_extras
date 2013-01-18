<?php

/**
 * Implements hook_views_data_alter().
 */
function entity_translation_extras_views_data_alter(&$data) {
  $data['entity_translation']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'entity_id',
  );
}
