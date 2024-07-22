/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** button_png
*/

#include "my_paint.h"

sfSprite *init_svg_spr(sfTexture *textur)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, textur, sfTrue);
    return sprite;
}

static sfVector2f get_btn_rect_size(sfText *btn_txt, sfSprite *new)
{
    sfFloatRect txt_bnd = sfText_getGlobalBounds(btn_txt);
    sfFloatRect svg_bnd = sfSprite_getGlobalBounds(new);
    sfVector2f new_size;

    new_size.x = txt_bnd.width + svg_bnd.width + 48;
    new_size.y = txt_bnd.height + 16;
    return new_size;
}

static sfVector2f get_svg_pos(sfVector2f pos)
{
    float x = pos.x + 16;
    float y = pos.y + 4;
    sfVector2f svg_pos = {0};

    svg_pos.x = x;
    svg_pos.y = y;
    return svg_pos;
}

static sfVector2f get_svg_btn_txt(sfVector2f pos)
{
    float x = pos.x + 16 + 40;
    float y = pos.y + 4;
    sfVector2f svg_pos = {0};

    svg_pos.x = x;
    svg_pos.y = y;
    return svg_pos;
}

button_svg_t *init_button_svg(sfVector2f pos, char *txt, all_t *ast, tool svg)
{
    button_svg_t *btn = malloc(sizeof(button_svg_t));
    sfText *btn_txt = init_btn_text(txt, 20, ast->poppins);
    sfSprite *new = init_svg_spr(ast->tab_texture[svg]);
    sfVector2f size = get_btn_rect_size(btn_txt, new);

    btn->rect = sfRectangleShape_create();
    btn->is_clicked = is_btn_svg_clicked;
    btn->is_hover = is_btn_svg_hovered;
    btn->state = NONE;
    btn->btn_txt = btn_txt;
    btn->btn_svg = new;
    sfRectangleShape_setPosition(btn->rect, pos);
    sfRectangleShape_setSize(btn->rect, size);
    sfRectangleShape_setFillColor(btn->rect, sfTransparent);
    sfText_setPosition(btn_txt, get_svg_btn_txt(pos));
    sfSprite_setPosition(new, get_svg_pos(pos));
    return btn;
}
