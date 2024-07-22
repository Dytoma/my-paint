/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** init_pixels
*/

#include "my_paint.h"

sfUint8 *init_pixels(void)
{
    int pixel_count = BOARD_W * BOARD_H;
    sfUint8 *pixels = malloc(sizeof(sfUint8) * pixel_count * 4);

    for (int i = 0; i < pixel_count; i++) {
        pixels[i * 4] = 255;
        pixels[i * 4 + 1] = 255;
        pixels[i * 4 + 2] = 255;
        pixels[i * 4 + 3] = 255;
    }
    return pixels;
}

void *change_board_bg(all_t *ast)
{
    int pixel_count = BOARD_W * BOARD_H;
    sfUint8 *pixels = ast->board->pixels;

    for (int i = 0; i < pixel_count; i++) {
        if (pixels[i * 4] == 255 && pixels[i * 4] == 255
        && pixels[i * 4 + 1] == 255 && pixels[i * 4 + 3] == 255) {
            pixels[i * 4] = (ast->colors[ast->board->paint])->clr.r;
            pixels[i * 4 + 1] = (ast->colors[ast->board->paint])->clr.g;
            pixels[i * 4 + 2] = (ast->colors[ast->board->paint])->clr.b;
            pixels[i * 4 + 3] = (ast->colors[ast->board->paint])->clr.a;
        }
    }
    return pixels;
}

board_t *create_board(void)
{
    board_t *board = malloc(sizeof(board_t));
    sfUint8 *pixels = init_pixels();
    sfImage *image = sfImage_createFromPixels(BOARD_W, BOARD_H, pixels);
    sfIntRect rect = {229, 180, BOARD_W, BOARD_H};
    sfTexture *b_txtr = sfTexture_create(BOARD_W, BOARD_H);
    sfSprite *b_sprite = sfSprite_create();

    sfSprite_setTexture(b_sprite, b_txtr, sfTrue);
    sfSprite_setPosition(b_sprite, (sfVector2f){229, 280});
    board->pixels = pixels;
    board->image = image;
    board->txtr = b_txtr;
    board->sprt = b_sprite;
    board->prev = (sfVector2i){0, 0};
    board->state = NONE;
    board->paint = DARK;
    return board;
}
