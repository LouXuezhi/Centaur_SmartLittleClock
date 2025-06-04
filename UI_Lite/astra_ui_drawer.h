//
// Created by forpaindream on 25-1-20.
//

#ifndef ASTRA_UI_DRAWER_H
#define ASTRA_UI_DRAWER_H

#include "astra_ui_item.h"

extern uint8_t astra_exit_animation_status;
extern void astra_draw_exit_animation(void); //退场动画

extern void astra_draw_info_bar(void);  //前景

extern void astra_draw_pop_up(void);    //前景

extern void astra_draw_list_appearance(void);   //前景

extern void astra_draw_list_item(void);   //背景

extern void astra_draw_selector(void);    //背景

extern void astra_draw_widget(void);    //总的控件 前景

extern void astra_draw_list(void);    //总的列表 背景

#endif //ASTRA_UI_DRAWER_H
