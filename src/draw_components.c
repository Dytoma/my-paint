/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** draw_components
*/

#include "my_paint.h"

void draw_up_bar(up_bar_t *u_bar, sfRenderWindow *window)
{
    draw_drop_menu(window, u_bar->file);
    draw_drop_menu(window, u_bar->edit);
    draw_drop_menu_txt(window, u_bar->help);
    draw_btn_svg(window, u_bar->save);
    if (u_bar->save->state == NONE)
        sfRectangleShape_setFillColor(u_bar->save->rect, sfTransparent);
    return;
}

void draw_colors(all_t *ast, sfRenderWindow *window)
{
    palette_t **pal = ast->colors;

    for (int i = 0; i < 20; i++) {
        sfRenderWindow_drawCircleShape(window, (pal[i])->circle, NULL);
        if ((pal[i])->paint == ast->board->paint) {
            sfCircleShape_setOutlineThickness((pal[i])->circle, 1.0);
            sfCircleShape_setOutlineColor((pal[i])->circle, sfWhite);
        } else {
            sfCircleShape_setOutlineThickness((pal[i])->circle, 0.0);
            sfCircleShape_setOutlineColor((pal[i])->circle, sfTransparent);
        }
    }
    return;
}

static sfBool change_clr_state(palette_t *plt, sfMouseButtonEvent *evt,
    board_t *board)
{
    sfFloatRect bounds = sfCircleShape_getGlobalBounds(plt->circle);

    if (evt->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&bounds, evt->x, evt->y)) {
        (plt)->state = ACTIVE;
        board->paint = plt->paint;
        return sfTrue;
    } else if (evt->type == sfEvtMouseButtonPressed) {
        (plt)->state = UNACTIVE;
        return sfFalse;
    }
    return sfFalse;
}

int set_drawing_clr(all_t *ast, sfMouseButtonEvent *evt)
{
    palette_t **pal = ast->colors;

    for (int i = 0; i < 20; i++) {
        change_clr_state(pal[i], evt, ast->board);
    }
    return 0;
}
