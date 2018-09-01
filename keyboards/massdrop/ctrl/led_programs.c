/*
Copyright 2018 Massdrop Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ctrl.h"
#include "led_matrix.h"

//Teal <-> Salmon
led_setup_t leds_teal_salmon[] = {
    { .hs = 0,  .he = 33,  .rs = 24,  .re = 24,  .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_NONE },
    { .hs = 33, .he = 66,  .rs = 24,  .re = 255, .gs = 215, .ge = 114, .bs = 204, .be = 118, .ef = EF_NONE },
    { .hs = 66, .he = 100, .rs = 255, .re = 255, .gs = 114, .ge = 114, .bs = 118, .be = 118, .ef = EF_NONE },
    { .end = 1 },
};

led_setup_t leds_press_teal_salmon[] = {
    { .hs = 0, .he = 100, .rs = 24, .re = 24, .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_NONE },
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_PRESS },
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 101, .ge = 101, .bs = 86, .be = 86, .ef = EF_PRESS | EF_SUBTRACT },
    { .end = 1 },
};

//Yellow
led_setup_t leds_yellow[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

led_setup_t leds_teal[] = {
  { .hs = 0,  .he = 100,  .rs = 24,  .re = 24,  .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_NONE },
  { .end = 1 },
};

led_setup_t leds_purple[] = {
  { .hs = 0,  .he = 100,  .rs = 150,   .re = 150, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_NONE },
  { .end = 1 },
};

led_setup_t leds_pink[] = {
  { .hs = 0,  .he = 100,  .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 150, .be = 150, .ef = EF_NONE },
  { .end = 1 },
};

//Off
led_setup_t leds_off[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

led_setup_t leds_press_yellow_red[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_PRESS | EF_SUBTRACT },
    { .end = 1 },
};

led_setup_t leds_press_red[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_PRESS },
    { .end = 1 },
};

led_setup_t leds_press_invert_red[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_PRESS | EF_SUBTRACT },
    { .end = 1 },
};

//Red
led_setup_t leds_red[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Green
led_setup_t leds_green[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Blue
led_setup_t leds_blue[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 255, .be = 255, .ef = EF_NONE },
    { .end = 1 },
};

//MURICA
led_setup_t leds_america_scroll[] = {
  { .hs = 0, .he = 16.67,     .rs = 0, .re = 255, .gs = 0,   .ge = 0,   .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
  { .hs = 16.67, .he = 33.33, .rs = 255, .re = 0, .gs = 255, .ge = 0, .bs = 255, .be = 0, .ef = EF_OVER | EF_SCR_R },
  { .hs = 33.33, .he = 50,    .rs = 0,   .re = 0,   .gs = 0,   .ge = 0,   .bs = 0, .be = 255, .ef = EF_OVER | EF_SCR_R },
  { .hs = 50,    .he = 66.67, .rs = 255, .re = 0, .gs = 0,   .ge = 0,   .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
  { .hs = 66.67, .he = 83.33, .rs = 0, .re = 255, .gs = 0, .ge = 255, .bs = 0, .be = 255, .ef = EF_OVER | EF_SCR_R },
  { .hs = 83.33, .he = 100,   .rs = 0,   .re = 0,   .gs = 0,   .ge = 0,   .bs = 255, .be = 0, .ef = EF_OVER | EF_SCR_R },
  { .end = 1 },
};

//MURICA
led_setup_t leds_america_scroll_keypress[] = {
  { .hs = 0,     .he = 16.67, .rs = 255, .re = 255,   .gs = 255, .ge = 255,   .bs = 255 , .be = 255,   .ef = EF_SCR_R },
  { .hs = 16.67, .he = 33.33, .rs = 0,   .re = 0,   .gs = 0,   .ge = 0,   .bs = 255,   .be = 255, .ef = EF_SCR_R },
  { .hs = 33.33, .he = 50,    .rs = 255, .re = 255,   .gs = 255, .ge = 255,   .bs = 255, .be = 255,   .ef = EF_SCR_R },
  { .hs = 50,    .he = 66.67, .rs = 0,   .re = 0,   .gs = 0,   .ge = 0,   .bs = 255,   .be = 255, .ef = EF_SCR_R },
  { .hs = 66.67, .he = 83.33, .rs = 255, .re = 255,   .gs = 255, .ge = 255,   .bs = 255, .be = 255,   .ef = EF_SCR_R },
  { .hs = 83.33, .he = 100,   .rs = 0,   .re = 0,   .gs = 0,   .ge = 0,   .bs = 255, .be = 255,   .ef = EF_SCR_R },
  { .hs = 0,     .he = 100,   .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 0, .be = 0,   .ef = EF_PRESS | EF_OVER},
  { .end = 1 },
};

led_setup_t leds_america[] = {
  { .hs = 0, .he = 16.67,     .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 0,   .be = 0,   .ef = EF_OVER  },
  { .hs = 16.67, .he = 33.33, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER  },
  { .hs = 33.33, .he = 50,    .rs = 0,   .re = 0,   .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER  },
  { .hs = 50,    .he = 66.67, .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 0,   .be = 0,   .ef = EF_OVER  },
  { .hs = 66.67, .he = 83.33, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_OVER  },
  { .hs = 83.33, .he = 100,   .rs = 0,   .re = 0,   .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER  },
  { .end = 1 },
};

//White
led_setup_t leds_white[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE },
    { .end = 1 },
};

//White with moving red stripe
led_setup_t leds_white_with_red_stripe[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE },
    { .hs = 0, .he = 15, .rs = 0, .re = 0, .gs = 0, .ge = 255, .bs = 0, .be = 255, .ef = EF_SCR_R | EF_SUBTRACT },
    { .hs = 15, .he = 30, .rs = 0, .re = 0, .gs = 255, .ge = 0, .bs = 255, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT },
    { .end = 1 },
};

//Black with moving red stripe
led_setup_t leds_black_with_red_stripe[] = {
    { .hs = 0, .he = 15, .rs = 0, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_OVER | EF_SCR_R },
    { .hs = 15, .he = 30, .rs = 255, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

led_setup_t leds_black_with_teal_stripe[] = {
    { .hs = 0, .he = 15, .rs = 0, .re = 24, .gs = 0, .ge = 215, .bs = 0, .be = 204, .ef = EF_OVER | EF_SCR_R },
    { .hs = 15,  .he = 30,  .rs = 24,  .re = 0,  .gs = 215, .ge = 0, .bs = 204, .be = 0, .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

//Rainbow no scrolling
led_setup_t leds_rainbow_ns[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER },
    { .end = 1 },
};

//Rainbow scrolling
led_setup_t leds_rainbow_s[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

led_setup_t leds_rainbow_s_touch[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 0,      .he = 100,    .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_SUBTRACT | EF_PRESS },
    { .end = 1 },
};

//Add new LED animations here using one from above as example
//The last entry must be { .end = 1 }
//Add the new animation name to the list below following its format
void *led_setups[] = {
    leds_rainbow_s_touch,
    leds_america_scroll_keypress,
    leds_press_invert_red,
    leds_press_red,
    leds_press_teal_salmon,
    leds_black_with_teal_stripe,
    leds_rainbow_s,
    leds_rainbow_ns,
    leds_yellow,
    leds_press_yellow_red,
    leds_red,
    leds_green,
    leds_blue,
    leds_teal,
    leds_purple,
    leds_pink,
    leds_white,
    leds_white_with_red_stripe,
    leds_black_with_red_stripe,
    leds_america,
    leds_america_scroll,
    leds_off
};

const uint8_t led_setups_count = sizeof(led_setups) / sizeof(led_setups[0]);
