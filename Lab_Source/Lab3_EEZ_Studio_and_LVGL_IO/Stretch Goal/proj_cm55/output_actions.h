/*
 * output_action.h
 *
 *  Created on: Mar 11, 2026
 *      Author: cline
 */

#ifndef UI_OUTPUT_ACTIONS_H_
#define UI_OUTPUT_ACTIONS_H_

/**
 * Convert a raw ADC reading into a bar percentage (0..100) and update the bar.
 *
 * - adc_raw: raw ADC counts (e.g. 0..4095 for 12-bit)
 * - adc_max: maximum ADC count (e.g. 4095 for 12-bit, 65535 for 16-bit)
 */
int ui_set_bar_from_adc(int adc_raw, int adc_max);
void ui_textarea_printf(const char *fmt, ...);



#endif /* UI_OUTPUT_ACTIONS_H_ */
