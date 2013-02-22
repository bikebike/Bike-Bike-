<?php
/**
 * @file keypic.admin.inc
 *
 * Function for keypic admin pages.
 */

/**
 * Get widget types.
 */
function keypic_widget_types() {
  return array(
    'image' => t('Image'),
    'iframe' => t('Iframe'),
  );
}

/**
 * Get widget sizes.
 */
function keypic_widget_sizes() {
  return array(
    '' => t('Default'),
    '300x250' => '300x250',
    '250x250' => '250x250',
    '240x400' => '240x400',
    '180x150' => '180x150',
    '300x100' => '300x100',
    '720x300' => '720x300',
    '392x72'  => '392x72',
    '468x60'  => '468x60',
    '234x60'  => '234x60',
    '80x15'  => '80x15',
    '88x31'  => '88x31',
    '120x90'  => '120x90',
    '120x60'  => '120x60',
    '120x240'  => '120x240',
    '125x125'  => '125x125',
    '728x90'  => '728x90',
    '120x600'  => '120x600',
    '160x600'  => '160x600',
    '300x600'  => '300x600',
  );
}

/**
 * Settings form for KeyPic web service.
 */
function keypic_admin_settings_form($form, &$form_state) {
  $form['#theme'] = 'system_settings_form';

  $form['keypic_example'] = array(
    '#type' => 'fieldset',
    '#title' => t('Example'),
    '#description' => t('Presolved KeyPic CAPTCHA example, generated with the current settings.'),
  );

  $form['keypic_example']['keypic'] = array(
    '#type' => 'captcha',
    '#captcha_type' => 'keypic/KeyPic',
    '#captcha_admin_mode' => TRUE,
  );

  $form['keypic_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Keypic Form ID'),
    '#default_value' => variable_get('keypic_form_id', ''),
  );

  $form['keypic_spam_point'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum spam point'),
    '#default_value' => variable_get('keypic_spam_point', 70),
    '#element_validate' => array('keypic_validate_spam_point_element'),
    '#description' => t(
        'Keypic response point which great this value will be considered as spam.'
          . ' Valid value is from 0 to 100.'
          . ' 0…39: Not spam. 40…69: Maybe spam. 70…100: Is spam.'
      ),
  );

  $widget_settings = variable_get('keypic_widget', array());

  $form['widget'] = array(
    '#type' => 'vertical_tabs',
    '#tree' => TRUE,
  );

  $form['forms']['#tree'] = TRUE;

  $form['forms']['default'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default'),
    '#tree' => TRUE,
    '#group' => 'widget',
  );

  $form['forms']['default']['format'] = array(
    '#type' => 'radios',
    '#title' => t('Widget format'),
    '#options' => keypic_widget_types(),
    '#default_value' => isset($widget_settings['default']['format']) ? $widget_settings['default']['format'] : 'image',
  );

  $form['forms']['default']['size'] = array(
    '#type' => 'select',
    '#title' => t('Widget size'),
    '#options' => keypic_widget_sizes(),
    '#default_value' => isset($widget_settings['default']['size']) ? $widget_settings['default']['size'] : '',
  );

  $result = db_select('captcha_points', 'cp')->fields('cp')->orderBy('form_id')->execute();
  foreach ($result as $challenge) {
    if ($challenge->module === 'keypic') {
      $form['forms'][$challenge->form_id] = array(
        '#type' => 'fieldset',
        '#title' => $challenge->form_id,
        '#group' => 'widget',
      );

      $form['forms'][$challenge->form_id]['format'] = array(
        '#type' => 'radios',
        '#title' => t('Widget format'),
        '#options' => keypic_widget_types(),
        '#default_value' => isset($widget_settings[$challenge->form_id]['format']) ? $widget_settings[$challenge->form_id]['format'] : 'image',
      );

      $form['forms'][$challenge->form_id]['size'] = array(
        '#type' => 'select',
        '#title' => t('Widget size'),
        '#options' => keypic_widget_sizes(),
        '#default_value' => isset($widget_settings[$challenge->form_id]['size']) ? $widget_settings[$challenge->form_id]['size'] : '',
      );
    }
  }

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Submit handler for Keypic settings form.
 */
function keypic_admin_settings_form_submit($form, &$form_state) {
  variable_set('keypic_widget', $form_state['values']['forms']);
}

function keypic_validate_spam_point_element($element, $form_state, $form) {
  $value = $element['#value'];
  if (is_numeric($value)) {
    if ($value <= 0 || $value >= 100) {
      form_error($element, t('Value is range from 0…100'));
    }
  }
  else {
    form_error($element, t('Value must be number.'));
  }
}
