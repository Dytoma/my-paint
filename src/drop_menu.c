/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** drop_menu
*/

#include "my_paint.h"

static button_svg_t **file_menu(all_t *ast, sfRectangleShape *rect)
{
    button_svg_t **options = malloc(sizeof(button_svg_t *) * 4);
    sfFloatRect bnd = sfRectangleShape_getGlobalBounds(rect);

    options[0] = init_button_svg
        ((sfVector2f){bnd.left, bnd.top + 24}, "Open", ast, FOLDER);
    options[1] = init_button_svg
        ((sfVector2f){bnd.left, bnd.top + 80}, "New", ast, FICHIER);
    options[2] = init_button_svg
        ((sfVector2f){bnd.left, bnd.top + 136}, "Save", ast, SAVE);
    options[3] = NULL;
    return options;
}

static button_svg_t **edit_menu(all_t *ast, sfRectangleShape *rect)
{
    button_svg_t **options = malloc(sizeof(button_svg_t *) * 4);
    sfFloatRect bnd = sfRectangleShape_getGlobalBounds(rect);

    options[0] = init_button_svg
        ((sfVector2f){bnd.left, bnd.top + 24}, "Cut", ast, SCISSOR);
    options[1] = init_button_svg
        ((sfVector2f){bnd.left, bnd.top + 80}, "Copy", ast, COPY);
    options[2] = init_button_svg
        ((sfVector2f){bnd.left, bnd.top + 136}, "Paste", ast, PASTE);
    options[3] = NULL;
    return options;
}

static sfRectangleShape *init_menu_rect(sfRectangleShape *btn_rect)
{
    sfRectangleShape *menu_rect = sfRectangleShape_create();
    sfVector2f size = {124, 200};
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

s_gui_drop_menu_t *create_drop_menu(sfVector2f position, char *option,
    all_t *ast)
{
    s_gui_drop_menu_t *dropMenu = malloc(sizeof(s_gui_drop_menu_t));
    button_t *menu = init_button(position, option, ast->poppins);

    dropMenu->button = menu;
    dropMenu->rect = init_menu_rect(menu->rect);
    if (my_strcmp(option, "File") == 0)
        dropMenu->options = file_menu(ast, dropMenu->rect);
    else
        dropMenu->options = edit_menu(ast, dropMenu->rect);
    return dropMenu;
}
