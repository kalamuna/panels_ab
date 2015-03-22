<?php

/**
 * @file
 * Plugin to provide access control based upon a random returned probability.
 * You could use this for very basic AB (or ABCD...Z) testing in panels pages.
 */


/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Random chance"),
  'description' => t('Roll the dice!'),
  'callback' => 'panels_ab_random_access_check',
  'default' => array('rids' => array()),
  'settings form' => 'panels_ab_random_access_settings',
  'summary' => 'panels_ab_random_access_summary',
  'all contexts' => TRUE,
);

/*
 * Helper function to return our prob options
 */
function _panels_ab_random_get_probs() {
  $probs = array (
    '2' => '50%',
    '3' => '33%',
    '4' => '25%',
    '5' => '20%',
    '10' => '10%',
    '20' => '5%',
    '100' => '1%',
  );
  return $probs;
}


/**
 * Settings form for the 'by role' access plugin.
 */
function panels_ab_random_access_settings(&$form, &$form_state, $conf) {
  $form['settings']['prob'] = array(
    '#type' => 'select',
    '#title' => t('Probability'),
    '#default_value' => $conf['prob'],
    '#options' => _panels_ab_random_get_probs(),
    '#description' => t('Select the chance that this variant will display.'),
  );

  return $form;
}

/**
 * Compress the roles allowed to the minimum.
 */
function panels_ab_random_access_settings_submit(&$form, &$form_state) {
  $form_state['values']['settings']['prob'] = $form_state['values']['settings']['prob'];
}

/**
 * Check for access.
 */
function panels_ab_random_access_check($conf, $context) {
  $access = &drupal_static(__FUNCTION__);
  if (isset($access)) {
    return true;
  }
  $access = true;
  if (isset($conf['prob'])) {
    $mod = $conf['prob'];
    $num = rand(1, 100);
    $result = $num % $conf['prob'];
    if ($result != 0) {
      $access = false;
    }
  }
  return $access;
}

/**
 * Provide a summary description based upon the checked roles.
 */
function panels_ab_random_access_summary($conf, $context) {
  return "hollla!";
}

