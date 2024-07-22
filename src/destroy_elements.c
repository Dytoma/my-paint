/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** destroy_elements
*/

#include "my_paint.h"

void destroy_btn_svg_txt(button_svg_t *btn)
{
    sfRectangleShape_destroy(btn->rect);
    sfSprite_destroy(btn->btn_svg);
    sfText_destroy(btn->btn_txt);
    free(btn);
}

void destroy_btn_svg(button_png_t *btn)
{
    sfRectangleShape_destroy(btn->rect);
    sfSprite_destroy(btn->btn_svg);
    free(btn);
}

static void destroy_btn_txt(button_t *btn)
{
    sfRectangleShape_destroy(btn->rect);
    sfText_destroy(btn->btn_txt);
    free(btn);
}

void destroy_left_side_bar(left_bar_t *l_bar)
{
    for (int i = 0; l_bar->arr[i] != NULL; i++) {
        destroy_btn_svg(l_bar->arr[i]);
    }
    sfText_destroy(l_bar->txt);
    free(l_bar);
    return;
}

void destroy_menu(s_gui_drop_menu_t *menu)
{
    destroy_btn_txt(menu->button);
    sfRectangleShape_destroy(menu->rect);
    for (int i = 0; menu->options[i] != NULL; i++) {
        destroy_btn_svg_txt(menu->options[i]);
    }
    free(menu);
    return;
}

void destroy_menu_txt(s_gui_drop_txt_t *menu)
{
    destroy_btn_txt(menu->button);
    sfRectangleShape_destroy(menu->rect);
    for (int i = 0; menu->options[i] != NULL; i++) {
        destroy_btn_txt(menu->options[i]);
    }
    free(menu);
    return;
}
