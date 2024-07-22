/*
** EPITECH PROJECT, 2024
** B-MUL-TLS-bsmy_paint-2
** File description:
** my_paint
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "../printf/include/my.h"

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_
    #define IS_HOVER(button) ((button == HOVER) ? sfTrue : sfFalse)
    #define IS_PRESSED(button) ((button == PRESSED) ? sfTrue : sfFalse)
    #define IS_RELEASED(button) ((button == PRESSED) ? sfTrue : sfFalse)

sfRenderWindow *init_window(void);
char *my_strcapitalize(char *str);
button_t *init_button(sfVector2f position, char *txt, sfFont *font);
button_svg_t *init_button_svg(sfVector2f pos, char *txt, all_t *ast, tool svg);
up_bar_t *init_up_bar(all_t *ast);
button_png_t *init_button_png(sfVector2f pos, all_t *ast, tool svg);
sfBool is_button_clicked(button_t *btn, sfMouseButtonEvent *mseEvt);
sfBool is_button_hovered(button_t *btn, sfMouseMoveEvent *mseEvt);
sfBool is_btn_svg_hovered(button_svg_t *btn, sfMouseMoveEvent *msEvt);
sfBool is_btn_svg_clicked(button_svg_t *btn, sfMouseButtonEvent *msEvt);
sfBool is_btn_png_hovered(button_png_t *btn, sfMouseMoveEvent *msEvt);
sfBool is_btn_png_clicked(button_png_t *btn, sfMouseButtonEvent *msEvt);
int analyze_events(all_t *assets,
    sfEvent *event, button_png_t **arr, up_bar_t *u_bar);
s_gui_drop_menu_t *create_drop_menu(sfVector2f position, char *option,
    all_t *ast);
s_gui_drop_txt_t *create_drop_menu_txt(sfVector2f position, char *option,
    all_t *ast);
void drawsprite(sprite_t *sprite, sfRenderWindow *window, board_t *board);
void draw_left_side_bar(left_bar_t *l_bar, sfRenderWindow *window, all_t *ast);
void draw_drop_menu(sfRenderWindow *window, s_gui_drop_menu_t *menu);
sprite_t *take_sprite(all_t *asts);
void draw_drop_menu_txt(sfRenderWindow *window, s_gui_drop_txt_t *menu);
void draw_colors(all_t *ast, sfRenderWindow *window);
all_t *set_assets(void);
void draw_btn_svg(sfRenderWindow *window, button_png_t *btn);
void draw_btn_svg_txt(sfRenderWindow *window, button_svg_t *btn);
void draw_up_bar(up_bar_t *u_bar, sfRenderWindow *window);
void destroy_btn_svg_txt(button_svg_t *btn);
void destroy_btn_svg(button_png_t *btn);
void destroy_left_side_bar(left_bar_t *l_bar);
void destroy_up_bar(up_bar_t *u_bar);
void destroy_menu(s_gui_drop_menu_t *menu);
void destroy_menu_txt(s_gui_drop_txt_t *menu);
void destroy_colors(palette_t **pal);
sfText *init_btn_text(char *name, unsigned int size, sfFont *poppins);
sfSprite *init_svg_spr(sfTexture *textur);
board_t *create_board(void);
sfBool draw_on_board(all_t *ast, sfMouseButtonEvent *msEvt);
int set_drawing_clr(all_t *ast, sfMouseButtonEvent *evt);
void save_to_file(all_t *ast);
void open_file(all_t *ast);
void *change_board_bg(all_t *ast);

#endif /* !MY_PAINT_H_ */
