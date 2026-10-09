/*
 * output_actions.c
 *
 *  Created on: Mar 11, 2026
 *      Author: cline
 */
 
#include "output_actions.h"
#include "screens.h"
#include <lvgl.h>
#include <stdarg.h>
#include <stdio.h>
#include "mtb_disp_dsi_waveshare_4p3.h"
#include "display_i2c_config.h"
 
/**
 * Convert a raw ADC reading into a bar percentage (0..100) and update the bar.
 *
 * - adc_raw:  raw ADC counts (e.g. 0..4095 for 12-bit)
 * - adc_max:  maximum ADC count (e.g. 4095 for 12-bit, 65535 for 16-bit)
 *
 * NOTE: Change `objects.screen_bar_1` to your actual bar object name from screens.h.
 * NOTE: Call this from the same context/task that runs lv_timer_handler().
 */
int ui_set_bar_from_adc(int adc_raw, int adc_max)
{
    if(!objects.my_bar) return 100;  // bar not created yet
    if(adc_max <= 0) return 100;   //ADC Max can not be negative

    if(adc_raw < 0) adc_raw = 0;
    if(adc_raw > adc_max) adc_raw = adc_max;

    int percent = (adc_raw * 100) / adc_max;
    if(percent < 0) percent = 0;
    if(percent > 100) percent = 100;
     

    lv_bar_set_value(objects.my_bar, percent, LV_ANIM_OFF);
    return percent;
}


