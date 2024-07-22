/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** events
*/

#include "my_paint.h"

static int handle_btn_png_evt(button_png_t **arr, sfEvent *event, all_t *ast)
{
    sfMouseMoveEvent msMvEvt = event->mouseMove;
    sfMouseButtonEvent msBtnEvt = event->mouseButton;

    for (int i = 0; arr[i] != NULL; i++) {
        if ((arr[i])->is_clicked(arr[i], &msBtnEvt)) {
            ast->omar = (arr[i])->omar;
            return 0;
        }
        if ((arr[i])->is_hover(arr[i], &msMvEvt))
            return 0;
    }
    return 1;
}

static int handle_mnu_option(button_svg_t **options, sfEvent *event,
    all_t *ast)
{
    sfMouseMoveEvent msMvEvt = event->mouseMove;
    sfMouseButtonEvent msBtnEvt = event->mouseButton;

    for (int i = 0; options[i] != NULL; i++) {
        if ((options[i])->is_clicked(options[i], &msBtnEvt))
            return 0;
        if ((options[i])->is_hover(options[i], &msMvEvt))
            return 0;
    }
    return 1;
}

static int handle_mnu_option_file(button_svg_t **options, sfEvent *event,
    all_t *ast)
{
    sfMouseMoveEvent msMvEvt = event->mouseMove;
    sfMouseButtonEvent msBtnEvt = event->mouseButton;

    if ((options[2])->is_clicked(options[2], &msBtnEvt)) {
        save_to_file(ast);
    }
    if ((options[0])->is_clicked(options[0], &msBtnEvt)) {
        open_file(ast);
    }
    for (int i = 0; options[i] != NULL; i++) {
        if ((options[i])->is_clicked(options[i], &msBtnEvt))
            return 0;
        if ((options[i])->is_hover(options[i], &msMvEvt))
            return 0;
    }
    return 1;
}

int handle_txt_mnu_opt(button_t **options, sfEvent *event)
{
    sfMouseMoveEvent msMvEvt = event->mouseMove;
    sfMouseButtonEvent msBtnEvt = event->mouseButton;

    for (int i = 0; options[i] != NULL; i++) {
        if ((options[i])->is_clicked(options[i], &msBtnEvt))
            return 0;
        if ((options[i])->is_hover(options[i], &msMvEvt))
            return 0;
    }
    return 1;
}

static int handle_mnu_evt(s_gui_drop_menu_t *menu, sfEvent *event)
{
    sfMouseMoveEvent msMvEvt = event->mouseMove;
    sfMouseButtonEvent msBtnEvt = event->mouseButton;

    if (menu->button->is_clicked(menu->button, &msBtnEvt))
        return 0;
    menu->button->is_hover(menu->button, &msMvEvt);
    return 1;
}

static int handle_mnu_txt(s_gui_drop_txt_t *menu, sfEvent *event)
{
    sfMouseMoveEvent msMvEvt = event->mouseMove;
    sfMouseButtonEvent msBtnEvt = event->mouseButton;

    if (menu->button->is_clicked(menu->button, &msBtnEvt))
        return 0;
    menu->button->is_hover(menu->button, &msMvEvt);
    return 1;
}

int handle_save_btn(all_t *ast, button_png_t *btn, sfEvent *event)
{
    sfMouseMoveEvent msMvEvt = event->mouseMove;
    sfMouseButtonEvent msBtnEvt = event->mouseButton;
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);

    if (msBtnEvt.type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&bounds, msBtnEvt.x, msBtnEvt.y)) {
        save_to_file(ast);
        btn->state = PRESSED;
        return sfTrue;
    }
    if (btn->is_hover(btn, &msMvEvt))
        return 0;
    return 1;
}

int analyze_events(all_t *ast,
    sfEvent *event, button_png_t **arr, up_bar_t *u_bar)
{
    sfMouseMoveEvent msMvEvt = event->mouseMove;
    sfMouseButtonEvent msBtnEvt = event->mouseButton;

    while (sfRenderWindow_pollEvent(ast->window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(ast->window);
        handle_btn_png_evt(arr, event, ast);
        handle_mnu_evt(u_bar->file, event);
        handle_mnu_evt(u_bar->edit, event);
        handle_mnu_option(u_bar->edit->options, event, ast);
        handle_mnu_option_file(u_bar->file->options, event, ast);
        handle_mnu_txt(u_bar->help, event);
        handle_txt_mnu_opt(u_bar->help->options, event);
        handle_save_btn(ast, u_bar->save, event);
        set_drawing_clr(ast, &msBtnEvt);
        draw_on_board(ast, &msBtnEvt);
    }
    return 0;
}

sfBool is_btn_png_clicked(button_png_t *btn, sfMouseButtonEvent *msEvt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);

    if (msEvt->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&bounds, msEvt->x, msEvt->y)) {
        my_printf("Button pressed\n");
        btn->state = PRESSED;
        return sfTrue;
    }
    btn->state = RELEASED;
    return sfFalse;
}
