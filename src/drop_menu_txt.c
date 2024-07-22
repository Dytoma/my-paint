/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** drop_menu_txt
*/

#include "my_paint.h"

static button_t **help_menu(all_t *ast, sfRectangleShape *rect)
{
    button_t **options = malloc(sizeof(button_t *) * 3);
    sfFloatRect bnd = sfRectangleShape_getGlobalBounds(rect);

    options[0] = init_button((sfVector2f)
        {bnd.left, bnd.top + 24}, "About", ast->poppins);
    options[1] = init_button((sfVector2f)
        {bnd.left, bnd.top + 80}, "User Guide", ast->poppins);
    options[2] = NULL;
    return options;
}

static sfRectangleShape *init_menu_rect(sfRectangleShape *btn_rect)
{
    sfRectangleShape *menu_rect = sfRectangleShape_create();
    sfVector2f size = {149, 164};
    sfColor outline = {139, 131, 131, 100};
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn_rect);
    sfVector2f pos = {bounds.left, bounds.height + bounds.top + 2};

    sfRectangleShape_setSize(menu_rect, size);
    sfRectangleShape_setPosition(menu_rect, pos);
    sfRectangleShape_setFillColor(menu_rect, sfBlack);
    sfRectangleShape_setOutlineColor(menu_rect, outline);
    sfRectangleShape_setOutlineThickness(menu_rect, 1.0);
    return menu_rect;
}

s_gui_drop_txt_t *create_drop_menu_txt(sfVector2f position, char *option,
    all_t *ast)
{
    s_gui_drop_txt_t *dropMenu = malloc(sizeof(s_gui_drop_txt_t));
    button_t *menu = init_button(position, option, ast->poppins);

    dropMenu->button = menu;
    dropMenu->rect = init_menu_rect(menu->rect);
    dropMenu->options = help_menu(ast, dropMenu->rect);
    return dropMenu;
}
