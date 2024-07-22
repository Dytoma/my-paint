/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** destroy_components
*/

#include "my_paint.h"

void destroy_up_bar(up_bar_t *u_bar)
{
    destroy_menu(u_bar->file);
    destroy_menu(u_bar->edit);
    destroy_menu_txt(u_bar->help);
    destroy_btn_svg(u_bar->save);
    free(u_bar);
}

void destroy_colors(palette_t **pal)
{
    for (int i = 0; i < 20; i++) {
        sfCircleShape_destroy((pal[i])->circle);
        free(pal[i]);
    }
    free(pal);
    return;
}
