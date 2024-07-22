/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** button_events
*/

#include "my_paint.h"

sfBool is_button_clicked(button_t *btn, sfMouseButtonEvent *msEvt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);

    if (msEvt->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&bounds, msEvt->x, msEvt->y)) {
        btn->state = PRESSED;
        return sfTrue;
    } else if (msEvt->type == sfEvtMouseButtonPressed) {
        btn->state = RELEASED;
        return sfFalse;
    }
    return sfFalse;
}

sfBool is_button_hovered(button_t *btn, sfMouseMoveEvent *msEvt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);
    sfColor bg_clr = {54, 54, 54, 100};

    if (msEvt->type == sfEvtMouseMoved &&
        sfFloatRect_contains(&bounds, msEvt->x, msEvt->y)) {
        sfRectangleShape_setFillColor(btn->rect, bg_clr);
        return sfTrue;
    } else {
        sfRectangleShape_setFillColor(btn->rect, sfTransparent);
        return sfFalse;
    }
}

sfBool is_btn_svg_clicked(button_svg_t *btn, sfMouseButtonEvent *msEvt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);

    if (msEvt->type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&bounds, msEvt->x, msEvt->y)) {
        btn->state = PRESSED;
        return sfTrue;
    } else if (msEvt->type == sfEvtMouseButtonPressed) {
        btn->state = RELEASED;
        return sfFalse;
    }
    return sfFalse;
}

sfBool is_btn_svg_hovered(button_svg_t *btn, sfMouseMoveEvent *msEvt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);
    sfColor bg_clr = {54, 54, 54, 100};

    if (msEvt->type == sfEvtMouseMoved &&
        sfFloatRect_contains(&bounds, msEvt->x, msEvt->y)) {
        sfRectangleShape_setFillColor(btn->rect, bg_clr);
        btn->state = HOVER;
        return sfTrue;
    } else {
        sfRectangleShape_setFillColor(btn->rect, sfTransparent);
        btn->state = NONE;
        return sfFalse;
    }
}

sfBool is_btn_png_hovered(button_png_t *btn, sfMouseMoveEvent *msEvt)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(btn->rect);
    sfColor bg_clr = {54, 54, 54, 100};

    if (msEvt->type == sfEvtMouseMoved &&
        sfFloatRect_contains(&bounds, msEvt->x, msEvt->y)) {
        sfRectangleShape_setFillColor(btn->rect, bg_clr);
        btn->state = HOVER;
        return sfTrue;
    } else if (msEvt->type == sfEvtMouseMoved) {
        btn->state = NONE;
        return sfFalse;
    }
    return sfFalse;
}
