/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** draw_on_board
*/

#include "my_paint.h"

static sfBool check_mouse_on_brd(all_t *ast, sfFloatRect bounds)
{
    sfVector2i pos = sfMouse_getPosition((sfWindow *)ast->window);

    if (pos.x >= bounds.left && pos.x <= (bounds.left + bounds.width)) {
        if (pos.y >= bounds.top && pos.y <= (bounds.top + bounds.height))
            return sfTrue;
    }
    ast->board->prev = (sfVector2i){0, 0};
    return sfFalse;
}

static void change_board_clr(all_t *ast, sfVector2i m_pos, int size)
{
    board_t *board = ast->board;
    sfVector2f pos = sfSprite_getPosition(board->sprt);
    int index = ((m_pos.x - pos.x - 5) + (m_pos.y - pos.y - 5) * BOARD_W) * 4;

    if (!check_mouse_on_brd(ast, sfSprite_getGlobalBounds(board->sprt)))
            return;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board->pixels[index + (i * BOARD_W + j) * 4] =
                (ast->colors[ast->board->paint])->clr.r;
            board->pixels[index + (i * BOARD_W + j) * 4 + 1] =
                (ast->colors[ast->board->paint])->clr.g;
            board->pixels[index + (i * BOARD_W + j) * 4 + 2] =
                (ast->colors[ast->board->paint])->clr.b;
            board->pixels[index + (i * BOARD_W + j) * 4 + 3] =
                (ast->colors[ast->board->paint])->clr.a;
        }
    }
    return;
}

static void erase_board_clr(all_t *ast, sfVector2i m_pos)
{
    board_t *board = ast->board;
    sfVector2f pos = sfSprite_getPosition(board->sprt);
    int index = ((m_pos.x - pos.x - 5) + (m_pos.y - pos.y - 5) * BOARD_W) * 4;

    if (!check_mouse_on_brd(ast, sfSprite_getGlobalBounds(board->sprt)))
            return;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board->pixels[index + (i * BOARD_W + j) * 4] = 255;
            board->pixels[index + (i * BOARD_W + j) * 4 + 1] = 255;
            board->pixels[index + (i * BOARD_W + j) * 4 + 2] = 255;
            board->pixels[index + (i * BOARD_W + j) * 4 + 3] = 255;
        }
    }
    return;
}

static void plot_line(all_t *ast, sfVector2i prev, sfVector2i act, int size)
{
    int dx = abs(prev.x - act.x);
    int sx = act.x < prev.x ? 1 : -1;
    int dy = -abs(prev.y - act.y);
    int sy = act.y < prev.y ? 1 : -1;
    int err = dx + dy, e2;

    if (prev.x == 0 && prev.y == 0)
        return;
    while (act.x != prev.x && act.y != prev.y) {
        change_board_clr(ast, act, size);
        e2 = 4 * err;
        if (e2 >= dy) {
            err += dy;
            act.x += sx;
        }
        if (e2 <= dx) {
            err += dx;
            act.y += sy;
        }
    }
}

void draw_on_tool(all_t *ast, sfVector2i mouse_pos)
{
    board_t *board = ast->board;

    if (ast->omar == ERASER)
        erase_board_clr(ast, mouse_pos);
    if (ast->omar == BRUSH) {
        plot_line(ast, board->prev, mouse_pos, 10);
        change_board_clr(ast, mouse_pos, 10);
    }
    if (ast->omar == PENCIL) {
        plot_line(ast, board->prev, mouse_pos, 2);
        change_board_clr(ast, mouse_pos, 2);
    }
    if (ast->omar == FILL) {
        change_board_bg(ast);
    }
}

sfBool draw_on_board(all_t *ast, sfMouseButtonEvent *msEvt)
{
    board_t *board = ast->board;
    sfFloatRect bounds = sfSprite_getGlobalBounds(board->sprt);
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)ast->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        draw_on_tool(ast, mouse_pos);
        board->prev = mouse_pos;
        return sfTrue;
    } else {
        board->prev = (sfVector2i){0, 0};
        board->state = RELEASED;
        return sfFalse;
    }
    return sfFalse;
}
