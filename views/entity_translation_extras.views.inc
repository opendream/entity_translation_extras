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
function entity_translation_extras_views_query_alter(&$view, &$query) {
  global $user;
  if ($user->uid == 1) {

    $join = new views_join;
    $join->construct('entity_translation', 'node', 'nid', 'entity_id');

    $query->table_queue['entity_translation'] = array(
      'table' => 'entity_translation',
      'num' => 1,
      'alias' => 'entity_translation',
      'relationship' => 'node',
      'join' => $join
    );

    $query->tables['node']['entity_translation'] = array(
      'count' => 1,
      'alias' => 'entity_translation'
    );

    $query->where[] = array(
      'conditions' => array(
        array(
          'field' => 'entity_translation.language',
          'value' => array('***CURRENT_LANGUAGE***'),
          'operator' => 'in'
        )
      ),
      'args' => array(),
      'type' => 'AND'
    );
  }
}
