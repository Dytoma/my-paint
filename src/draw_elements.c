/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** draw_elements
*/

#include "my_paint.h"

void draw_btn_svg_txt(sfRenderWindow *window, button_svg_t *btn)
{
    sfRenderWindow_drawRectangleShape(window, btn->rect, NULL);
    sfRenderWindow_drawSprite(window, btn->btn_svg, NULL);
    sfRenderWindow_drawText(window, btn->btn_txt, NULL);
}

static void draw_btn_txt(sfRenderWindow *window, button_t *btn)
{
    sfRenderWindow_drawRectangleShape(window, btn->rect, NULL);
    sfRenderWindow_drawText(window, btn->btn_txt, NULL);
}

void draw_btn_svg(sfRenderWindow *window, button_png_t *btn)
{
    sfRenderWindow_drawRectangleShape(window, btn->rect, NULL);
    sfRenderWindow_drawSprite(window, btn->btn_svg, NULL);
    return;
}

void draw_left_side_bar(left_bar_t *l_bar, sfRenderWindow *window, all_t *ast)
{
    button_png_t **arr = l_bar->arr;

    for (int i = 0; arr[i] != NULL; i++) {
        draw_btn_svg(window, arr[i]);
        if ((arr[i])->omar == ast->omar) {
            sfRectangleShape_setFillColor((arr[i])->rect,
                (sfColor){54, 54, 54, 255});
            continue;
        }
        if (arr[i]->state == HOVER) {
            sfRectangleShape_setFillColor((arr[i])->rect,
                (sfColor){54, 54, 54, 255});
        } else {
            sfRectangleShape_setFillColor((arr[i])->rect, sfTransparent);
        }
    }
    sfRenderWindow_drawText(window, l_bar->txt, NULL);
    return;
}

void draw_drop_menu(sfRenderWindow *window, s_gui_drop_menu_t *menu)
{
    draw_btn_txt(window, menu->button);
    if (menu->button->state == PRESSED) {
        sfRenderWindow_drawRectangleShape(window, menu->rect, NULL);
        draw_btn_svg_txt(window, menu->options[0]);
        draw_btn_svg_txt(window, menu->options[1]);
        draw_btn_svg_txt(window, menu->options[2]);
    }
    return;
}

void draw_drop_menu_txt(sfRenderWindow *window, s_gui_drop_txt_t *menu)
{
    draw_btn_txt(window, menu->button);
    if (menu->button->state == PRESSED) {
        sfRenderWindow_drawRectangleShape(window, menu->rect, NULL);
        draw_btn_txt(window, menu->options[0]);
        draw_btn_txt(window, menu->options[1]);
    }
    return;
}
