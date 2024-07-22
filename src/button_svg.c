/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** button_svg
*/

#include "my_paint.h"

static sfVector2f get_btn_rect_size(sfSprite *new)
{
    sfFloatRect svg_bnd = sfSprite_getGlobalBounds(new);
    sfVector2f new_size;

    new_size.x = svg_bnd.width + 40;
    new_size.y = svg_bnd.height + 16;
    return new_size;
}

static sfVector2f get_svg_pos(sfVector2f pos)
{
    float x = pos.x + 20;
    float y = pos.y + 8;
    sfVector2f svg_pos = {0};

    svg_pos.x = x;
    svg_pos.y = y;
    return svg_pos;
}

button_png_t *init_button_png(sfVector2f pos, all_t *ast, tool svg)
{
    button_png_t *btn = malloc(sizeof(button_png_t));
    sfSprite *new = init_svg_spr(ast->tab_texture[svg]);
    sfVector2f size = get_btn_rect_size(new);

    btn->rect = sfRectangleShape_create();
    btn->is_clicked = is_btn_png_clicked;
    btn->is_hover = is_btn_png_hovered;
    btn->state = NONE;
    btn->btn_svg = new;
    btn->pos = pos;
    btn->omar = svg;
    sfRectangleShape_setPosition(btn->rect, pos);
    sfRectangleShape_setSize(btn->rect, size);
    sfRectangleShape_setFillColor(btn->rect, sfTransparent);
    sfSprite_setPosition(new, get_svg_pos(pos));
    return btn;
}
