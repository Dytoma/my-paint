/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** top_menu
*/

#include "my_paint.h"

up_bar_t *init_up_bar(all_t *ast)
{
    up_bar_t *new = malloc(sizeof(up_bar_t));
    s_gui_drop_menu_t *file = create_drop_menu
        ((sfVector2f){102, 20}, "File", ast);
    s_gui_drop_menu_t *edit = create_drop_menu
        ((sfVector2f){226, 20}, "Edit", ast);
    s_gui_drop_txt_t *help = create_drop_menu_txt
        ((sfVector2f){352, 20}, "Help", ast);
    button_png_t *save = init_button_png
        ((sfVector2f){481, 32}, ast, SAVE);

    new->edit = edit;
    new->file = file;
    new->help = help;
    new->save = save;
    return new;
}
