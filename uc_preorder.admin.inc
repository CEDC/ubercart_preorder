<?php

/**
 * @file
 * Pre Order form.
 */

/**
 * Create the preorder products.
 */
function uc_preorder_create_form($form, &$form_state) {
  $form = array();
  $form['nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Product'),
    '#description' => t('Enter the SKU/Title of the product to add to the promotion.'),
    '#autocomplete_path' => 'uc_product/autocomplete',
    '#default_value' => empty($form_state['values']['nid']) ? '' :
        $form_state['values']['nid'],
    '#size' => 60,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['start_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Valid From'),
    '#date_label_position' => '',
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '0:+1',
    '#date_timezone' => date_default_timezone(),
    '#default_value' => empty($form_state['values']['start_date']) ? '' : $form_state['values']['start_date'],
    '#required' => TRUE,
  );

  $form['end_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Valid Upto'),
    '#date_type' => DATE_UNIX,
    '#date_label_position' => '',
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '0:+3',
    '#date_timezone' => date_default_timezone(),
    '#default_value' => empty($form_state['values']['end_date']) ? '' : $form_state['values']['end_date'],
    '#required' => TRUE,
  );

  $form['launch_date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Expected Launch Date'),
    '#date_type' => DATE_UNIX,
    '#date_label_position' => '',
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '0:+3',
    '#date_timezone' => date_default_timezone(),
    '#default_value' => empty($form_state['values']['launch_date']) ? '' : $form_state['values']['launch_date'],
    '#required' => TRUE,
  );

  $form['narration'] = array(
    '#type' => 'textarea',
    '#title' => t('Pre Order Narrations'),
    '#description' => t('Enter the narration of proorder.'),
    '#default_value' => empty($form_state['values']['narration']) ? '' :
    $form_state['values']['narration'],
    '#size' => 60,
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create Preorder Product'),
  );
  return $form;
}