/*
 * microsim360 - Front panel control definitions.
 *
 * Copyright 2021, Richard Cornwell
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef _PANEL_H_
#define _PANEL_H_
#include <SDL.h>
#include <stdint.h>

/* Declare an error to be of a give color */
extern struct _area {
    SDL_Rect     rect;            /* Area to color */
    SDL_Color    *c;              /* Color to show */
} areas[100];

/* Draw line */
extern struct _mark {
    int          x1;
    int          y1;
    int          x2;
    int          y2;
    SDL_Color    *c;
} marks[1000];

/* Model 2030 ROS bits. */
extern struct _ros_bits {
      SDL_Rect     rect;          /* Area where to show */
      SDL_Texture *digit_on;      /* Digit on and off */
      SDL_Texture *digit_off;
      int          shift;         /* Amount to shift to bit */
      int          row;           /* ROS Row values is stored at */
} ros_bits[1000];

/* Generic lamps */
extern struct _lamp {
    SDL_Rect      rect;           /* Area to show rectangle */
    int           col;            /* Color */
    int           shift;          /* Amount to shift to bit */
    uint8_t      *value;          /* Pointer to value */
} lamp[8];

/* Two level indicators */
extern struct _led_bits {
      SDL_Rect     recth;
      SDL_Rect     rectl;
      SDL_Texture *digith_on;
      SDL_Texture *digitl_on;
      SDL_Texture *digith_off;
      SDL_Texture *digitl_off;
      int          shift;
      uint16_t    *value;
      int          row;
} led_bits[1000];

/* Text label */
extern struct _ctl_label {
    SDL_Rect     rect;
    SDL_Texture  *text;
} ctl_label[1000];


#define SW    0
#define IND   1
#define ONOFF 2

/* Push button switch */
extern struct _switch {
    SDL_Rect     rect;           /* Outline of switch */
    SDL_Texture *top;            /* First line of label */
    SDL_Texture *bot;            /* Second line of label */
    SDL_Color   *c[2];           /* On/Off Color */
    SDL_Color   *ct;             /* Color of text */
    char        *lab;            /* Pointer to text label, not freed */
    int         *value;          /* Value to modify from switch */
    int          top_len;        /* Length of first line */
    int          bot_len;        /* Length of second line */
    int          active;         /* Currently active */
    int          type;           /* Type of switch */
} sws[100];

/* Indicator button */
extern struct _ind {
    SDL_Rect     rect;           /* Outline of label */
    SDL_Texture *top;            /* First line of label */
    SDL_Texture *bot;            /* Second line of label */
    SDL_Color   *c[2];           /* Off/On color */
    SDL_Color   *ct;             /* Color of text */
    char        *lab;            /* Pointer to text label, not freed */
    int         *value;          /* Value to watch */
    int          shift;          /* Shift value */
    int          top_len;        /* Length of first line */
    int          bot_len;        /* Length of second line */
} ind[100];

/* Rotory dail */
extern struct _dial {
    SDL_Rect     boxd;           /* Hit box to move left */
    SDL_Rect     boxu;           /* Hit box to move right */
    int          center_x;       /* Center point */
    int          center_y;
    int          pos_x[10];      /* Position of each detent */
    int          pos_y[10];
    int          init;           /* Initial value of switch */
    int          max;            /* Maximum value of switch */
    int          wrap;           /* Does switch have stop */
    uint8_t     *value;          /* Value to modify */
} dial[4];

/* Hex digit dial */
extern struct _hex {
     SDL_Rect    boxd;
     SDL_Rect    boxu;
     SDL_Rect    rect;
     uint8_t    *digit;
} hex_dial[10];

/* Storage selector for model 2030 */
extern struct _store {
     SDL_Rect    boxd;
     SDL_Rect    boxu;
     SDL_Rect    rect;
     uint8_t     sel;
     uint8_t    *digit;
} store_dial[2];

/* Text input selection */
struct _text {
     SDL_Rect    rect;
     char        text[256];
     SDL_Rect    srect;
     int         cpos;
     int         spos;
     int         epos;
     int         sel;
     int         selecting;
     int         pos;
     int         enable;
     int         len;
};

/* Multiple selection */
struct _combo {
     SDL_Rect     rect;
     SDL_Rect     urect;
     SDL_Rect     drect;
     SDL_Texture *label[8];
     int          lw[8];
     int          lh[8];
     int         *value;
     int          num;
     int          max;
};

/* Display number at location */
struct _number {
     SDL_Rect     rect;
     SDL_Color   *c;
     int         *value;
};

/* Structure defining roller display */
extern struct _roller {
    int           sel;                /* Current roller selection */
    SDL_Rect      rect[36];           /* Rectangles to display lights */
    int           col[36];            /* Color */
    SDL_Rect      blabel[36];         /* Display location for selector */
    struct _disp {
        SDL_Texture *label[36];       /* Label to display */
        uint32_t    *value[36];       /* Pointer to value */
        int         shift[36];        /* Shift amount */
        int         a_start;          /* Area start index */
        int         a_end;            /* Area start index */
        int         m_start;          /* Mark start index */
        int         m_end;            /* Mark start index */
        int         t_start;          /* Text start index */
        int         t_end;            /* Text start index */
    } disp[8];
    struct _parity {
        uint32_t   *value;            /* Pointer to value to compute */
        int        shift;             /* Amount to shift */
        uint32_t   mask;              /* Mask for parity */
    } parity[32];                     /* Parity pointers */
    int            num_par;           /* Number of parities to compute */
    struct _area   areas[100];        /* List of color areas */
    struct _mark   marks[100];        /* List of marks */
    struct _ctl_label label[1000];    /* Text labels */
} roller[6];

struct _panel {
      struct _lamp lamp[20];
      struct _led_bits led_bits[1000];
      struct _area areas[100];
      struct _mark marks[1000];
      struct _ros_bits ros_bits[1000];
      struct _ctl_label ctl_label[1000];
      struct _switch sws[100];
      struct _ind ind[100];
      struct _dial dial[4];
      struct _hex hex_dial[10];
      struct _store  store_dial[2];
      struct _text text[10];
      struct _combo combo[10];
      struct _number number[10];

      int        ros_ptr;
      int        lamp_ptr;
      int        led_ptr;
      int        area_ptr;
      int        mrk_ptr;
      int        ctl_ptr;
      int        sws_ptr;
      int        ind_ptr;
      int        txt_ptr;
      int        cmb_ptr;
      int        num_ptr;
      int        hex_ptr;
      int        store_ptr;
};

/* Structure of device control popup */
struct _popup {
      struct _lamp lamp[20];
      struct _led_bits led_bits[100];
      struct _area areas[100];
      struct _mark marks[100];
      struct _ctl_label ctl_label[100];
      struct _switch sws[100];
      struct _ind ind[100];
      struct _text text[10];
      struct _combo combo[10];
      struct _number number[10];

      int        unit_num;
      int        lamp_ptr;
      int        led_ptr;
      int        area_ptr;
      int        mrk_ptr;
      int        ctl_ptr;
      int        sws_ptr;
      int        ind_ptr;
      int        txt_ptr;
      int        cmb_ptr;
      int        num_ptr;
      int        temp[10];
      SDL_Window *screen;
      SDL_Renderer *render;
      void       *device;
      void       (*update)(struct _popup *pop, void *device, int index);
};
#endif
