/*
** EPITECH PROJECT, 2024
** B-MUL-TLS-bsmy_paint-2
** File description:
** main
*/

#include "my_paint.h"

sfText *init_btn_text(char *name, unsigned int size, sfFont *poppins)
{
    sfText *new_txt = sfText_create();

    if (poppins == NULL || !new_txt)
        return NULL;
    sfText_setString(new_txt, name);
    sfText_setFont(new_txt, poppins);
    sfText_setColor(new_txt, sfWhite);
    sfText_setCharacterSize(new_txt, size);
    return new_txt;
}

static sfVector2f txt_pos(sfVector2f pos)
{
    float x = pos.x + 20;
    float y = pos.y + 16;
    sfVector2f text_pos = {0};

    text_pos.x = x;
    text_pos.y = y;
    return text_pos;
}

button_t *init_button(sfVector2f pos, char *txt, sfFont *poppins)
{
    button_t *btn = malloc(sizeof(button_t));
    sfText *btn_txt = init_btn_text(txt, 20, poppins);
    sfFloatRect bounds;
    sfVector2f size;

    if (btn_txt == NULL)
        return NULL;
    bounds = sfText_getGlobalBounds(btn_txt);
    size = (sfVector2f){bounds.width + 40, bounds.height + 40};
    btn->rect = sfRectangleShape_create();
    btn->is_clicked = is_button_clicked;
    btn->is_hover = is_button_hovered;
    btn->state = NONE;
    btn->btn_txt = btn_txt;
    sfRectangleShape_setPosition(btn->rect, pos);
    sfRectangleShape_setSize(btn->rect, size);
    sfRectangleShape_setFillColor(btn->rect, sfTransparent);
    sfText_setPosition(btn_txt, txt_pos(pos));
    return btn;
}

sfRenderWindow *init_window(void)
{
    char name[] = "Software Paint";
    sfVideoMode mode = {WIDTH, HEIGHT, BPP};
    sfRenderWindow *window = sfRenderWindow_create(mode, name,
        sfResize | sfClose, NULL);

    return window;
}

static void destroy_board(board_t *board)
{
    sfSprite_destroy(board->sprt);
    free(board->pixels);
    sfTexture_destroy(board->txtr);
    sfImage_destroy(board->image);
    free(board);
}

static void destroy_data(all_t *assets, sfRenderWindow *window,
    sprite_t *sprite)
{
    destroy_colors(assets->colors);
    sfFont_destroy(assets->poppins);
    sfRenderWindow_destroy(window);
    destroy_board(assets->board);
    for (int i = 0; i < 18; i++) {
        sfTexture_destroy(assets->tab_texture[i]);
    }
    sfSprite_destroy(sprite->left_bar);
    sfSprite_destroy(sprite->right_bar);
    sfSprite_destroy(sprite->up_bar);
    free(sprite);
    free(assets->tab_texture);
    free(assets);
}

left_bar_t *init_tools(all_t *ast)
{
    left_bar_t *left_bar = malloc(sizeof(left_bar_t));
    button_png_t **arr = malloc(sizeof(button_png_t *) * 7);
    sfText *shapes = init_btn_text("Shapes", 14, ast->poppins);

    arr[0] = init_button_png((sfVector2f){14, 126}, ast, BRUSH);
    arr[1] = init_button_png((sfVector2f){14, 210}, ast, ERASER);
    arr[2] = init_button_png((sfVector2f){14, 294}, ast, FILL);
    arr[3] = init_button_png((sfVector2f){14, 378}, ast, PENCIL);
    arr[4] = init_button_png((sfVector2f){14, 527}, ast, CIRCLE);
    arr[5] = init_button_png((sfVector2f){14, 603}, ast, RECTANGLE);
    arr[6] = NULL;
    sfText_setPosition(shapes, (sfVector2f){24, 470});
    left_bar->arr = arr;
    left_bar->txt = shapes;
    return left_bar;
}

int main(void)
{
    all_t *assets = set_assets();
    sfRenderWindow *window = assets->window;
    sfEvent event;
    sprite_t *sprite = take_sprite(assets);
    left_bar_t *l_bar = init_tools(assets);
    up_bar_t *u_bar = init_up_bar(assets);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, (sfColor){12, 12, 14, 255});
        drawsprite(sprite, window, assets->board);
        draw_up_bar(u_bar, window);
        draw_colors(assets, window);
        draw_left_side_bar(l_bar, window, assets);
        analyze_events(assets, &event, l_bar->arr, u_bar);
        sfRenderWindow_display(window);
    }
    destroy_left_side_bar(l_bar);
    destroy_up_bar(u_bar);
    destroy_data(assets, window, sprite);
    return 0;
}
