//
// Created by forpaindream on 25-1-20.
//

#ifndef ASTRA_UI_CORE_H
#define ASTRA_UI_CORE_H
#include <stdbool.h>

#define ALLOW_EXIT_ASTRA_UI_BY_USER 1 //允许用户在最浅层级退出astra ui lite
extern bool in_astra;

extern void ad_astra(void);

extern void astra_refresh_info_bar(void);

extern void astra_refresh_pop_up(void);

extern void astra_refresh_camera_position(void);

extern void astra_refresh_widget_core_position(void);

extern void astra_init_list(void);

extern void astra_init_core(void);

extern void astra_refresh_list_item_position(void);

extern void astra_refresh_selector_position(void);

extern void astra_refresh_main_core_position(void);

extern void astra_ui_widget_core(void);

extern void astra_ui_main_core(void);



#endif //ASTRA_UI_CORE_H
