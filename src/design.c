/*
** EPITECH PROJECT, 2024
** graphic
** File description:
** main
*/

#include "struct.h"
#include "my_paint.h"

static void take_sprite1(all_t *tab)
{
    tab->tab_texture[0] = sfTexture_createFromFile
        ("./Assets/brush.png", NULL);
    tab->tab_texture[1] = sfTexture_createFromFile
        ("./Assets/Circle.png", NULL);
    tab->tab_texture[2] = sfTexture_createFromFile
        ("./Assets/close.png", NULL);
    tab->tab_texture[3] = sfTexture_createFromFile
        ("./Assets/copy.png", NULL);
    tab->tab_texture[4] = sfTexture_createFromFile
        ("./Assets/eraser.png", NULL);
    tab->tab_texture[5] = sfTexture_createFromFile
        ("./Assets/file.png", NULL);
    tab->tab_texture[6] = sfTexture_createFromFile
        ("./Assets/fill.png", NULL);
    tab->tab_texture[7] = sfTexture_createFromFile
        ("./Assets/folder.png", NULL);
    tab->tab_texture[8] = sfTexture_createFromFile
        ("./Assets/left_bar.png", NULL);
}

static void take_sprite2(all_t *tab)
{
    tab->tab_texture[9] = sfTexture_createFromFile
        ("./Assets/minus.png", NULL);
    tab->tab_texture[10] = sfTexture_createFromFile
        ("./Assets/paste.png", NULL);
    tab->tab_texture[11] = sfTexture_createFromFile
        ("./Assets/pencil.png", NULL);
    tab->tab_texture[12] = sfTexture_createFromFile
        ("./Assets/plus.png", NULL);
    tab->tab_texture[13] = sfTexture_createFromFile
        ("./Assets/Rectangle.png", NULL);
    tab->tab_texture[14] = sfTexture_createFromFile
        ("./Assets/right_bar.png", NULL);
    tab->tab_texture[15] = sfTexture_createFromFile
        ("./Assets/save.png", NULL);
    tab->tab_texture[16] = sfTexture_createFromFile
        ("./Assets/scissor.png", NULL);
}

palette_t *init_circle(sfColor clr, sfVector2f pos, color_t paint)
{
    palette_t *shade = malloc(sizeof(palette_t));
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setFillColor(circle, clr);
    sfCircleShape_setRadius(circle, (float)RADIUS);
    sfCircleShape_setPosition(circle, pos);
    shade->circle = circle;
    shade->clr = clr;
    shade->pos = pos;
    shade->state = UNACTIVE;
    shade->paint = paint;
    return shade;
}

static void init_color2(all_t *cirlor)
{
    cirlor->colors[10] = init_circle
        ((sfColor){255, 255, 255, 255}, (sfVector2f){1718, 214}, WHITE);
    cirlor->colors[11] = init_circle
        ((sfColor){201, 6, 6, 255}, (sfVector2f){1754, 214}, RED);
    cirlor->colors[12] = init_circle
        ((sfColor){8, 178, 35, 255}, (sfVector2f){1790, 214}, GREEN);
    cirlor->colors[13] = init_circle
        ((sfColor){6, 12, 150, 255}, (sfVector2f){1826, 214}, DARK_BLUE);
    cirlor->colors[14] = init_circle
        ((sfColor){209, 7, 141, 255}, (sfVector2f){1862, 214}, DARK_PINK);
    cirlor->colors[15] = init_circle
        ((sfColor){34, 34, 35, 255}, (sfVector2f){1718, 254}, DARK_GREY);
    cirlor->colors[16] = init_circle
        ((sfColor){139, 131, 131, 255}, (sfVector2f){1754, 254}, GREY);
    cirlor->colors[17] = init_circle
        ((sfColor){2, 33, 38, 255}, (sfVector2f){1790, 254}, DARK_GREEN);
    cirlor->colors[18] = init_circle
        ((sfColor){116, 34, 181, 255}, (sfVector2f){1826, 254}, PURPLE);
    cirlor->colors[19] = init_circle
        ((sfColor){162, 225, 99, 255}, (sfVector2f){1862, 254}, LIGHT_GREEN);
}

static void init_color(all_t *cirlor)
{
    cirlor->colors[0] = init_circle
        ((sfColor){176, 110, 32, 255}, (sfVector2f){1718, 134}, BROWN);
    cirlor->colors[1] = init_circle
        ((sfColor){117, 29, 29, 255}, (sfVector2f){1754, 134}, DARK_RED);
    cirlor->colors[2] = init_circle
        ((sfColor){118, 125, 41, 255}, (sfVector2f){1790, 134}, KAKI);
    cirlor->colors[3] = init_circle
        ((sfColor){10, 87, 98, 255}, (sfVector2f){1826, 134}, DARK_BLUE_GREEN);
    cirlor->colors[4] = init_circle
        ((sfColor){20, 6, 178, 255}, (sfVector2f){1862, 134}, BLUE);
    cirlor->colors[5] = init_circle
        ((sfColor){0, 0, 0, 255}, (sfVector2f){1718, 174}, DARK);
    cirlor->colors[6] = init_circle
        ((sfColor){117, 208, 237, 255}, (sfVector2f){1754, 174}, LIGHT_BLUE);
    cirlor->colors[7] = init_circle
        ((sfColor){244, 53, 53, 255}, (sfVector2f){1790, 174}, LIGHT_RED);
    cirlor->colors[8] = init_circle
        ((sfColor){97, 237, 161, 255}, (sfVector2f){1826, 174}, BLUE_GREEN);
    cirlor->colors[9] = init_circle
        ((sfColor){242, 48, 199, 255}, (sfVector2f){1862, 174}, PINK);
}

all_t *set_assets(void)
{
    all_t *tab = malloc(sizeof(all_t));

    tab->tab_texture = malloc(sizeof(sfTexture *) * 18);
    tab->colors = malloc(sizeof(palette_t *) * 21);
    tab->colors[20] = NULL;
    init_color(tab);
    init_color2(tab);
    take_sprite1(tab);
    take_sprite2(tab);
    tab->tab_texture[17] = sfTexture_createFromFile
        ("./Assets/up_bar.png", NULL);
    tab->poppins = sfFont_createFromFile("./Assets/Poppins-SemiBold.ttf");
    tab->board = create_board();
    tab->window = init_window();
    tab->omar = BRUSH;
    return tab;
}

sprite_t *take_sprite(all_t *asts)
{
    sprite_t *sprites = malloc(sizeof(sprite_t));

    sprites->left_bar = sfSprite_create();
    sprites->right_bar = sfSprite_create();
    sprites->up_bar = sfSprite_create();
    sfSprite_setTexture(sprites->left_bar, asts->tab_texture[LEFT_BAR],
        sfTrue);
    sfSprite_setTexture(sprites->right_bar, asts->tab_texture[RIGHT_BAR],
        sfTrue);
    sfSprite_setTexture(sprites->up_bar, asts->tab_texture[UP_BAR], sfTrue);
    return sprites;
}

void drawsprite(sprite_t *sprite, sfRenderWindow *window, board_t *board)
{
    sfRenderWindow_drawSprite(window, sprite->right_bar, NULL);
    sfRenderWindow_drawSprite(window, sprite->left_bar, NULL);
    sfRenderWindow_drawSprite(window, sprite->up_bar, NULL);
    sfTexture_updateFromPixels(board->txtr, board->pixels, BOARD_W, BOARD_H,
        0, 0);
    sfRenderWindow_drawSprite(window, board->sprt, NULL);
}
