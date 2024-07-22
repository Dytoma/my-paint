/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** save_file
*/

#include "my_paint.h"

static char *check_file_name(char *buf)
{
    int d = -1;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '.')
            d = i;
    }
    if ((buf[d + 1] == 'p' && buf[d + 2] == 'n' && buf[d + 3] == 'g') ||
        (buf[d + 1] == 't' && buf[d + 2] == 'g' && buf[d + 3] == 'a') ||
        (buf[d + 1] == 'b' && buf[d + 2] == 'm' && buf[d + 3] == 'p') ||
        (buf[d + 1] == 'j' && buf[d + 2] == 'p' && buf[d + 3] == 'g')) {
        return buf;
    }
    buf = my_strcat(buf, ".jpg");
    return buf;
}

void save_to_file(all_t *ast)
{
    char *buf = NULL;
    int nb = 0;
    size_t sz = 0;
    sfImage *img = sfImage_createFromPixels(BOARD_W, BOARD_H,
        ast->board->pixels);

    my_printf("Input the file name:\n");
    nb = getline(&buf, &sz, stdin);
    buf[nb - 1] = '\0';
    buf = check_file_name(buf);
    if (sfImage_saveToFile(img, buf))
        my_printf("Image saved successfully!\n");
    sfImage_destroy(img);
}

static void change_pixels(all_t *ast, const sfUint8 *img_pxl, sfImage *img)
{
    sfVector2u size = sfImage_getSize(img);
    int pixel_count = size.x * size.y;

    for (int i = 0; i < pixel_count; i++) {
        ast->board->pixels[i * 4] = img_pxl[i * 4];
        ast->board->pixels[i * 4 + 1] = img_pxl[i * 4 + 1];
        ast->board->pixels[i * 4 + 2] = img_pxl[i * 4 + 2];
        ast->board->pixels[i * 4 + 3] = img_pxl[i * 4 + 3];
    }
    return;
}

void open_file(all_t *ast)
{
    char *buf = NULL;
    int nb = 0;
    size_t sz = 0;
    sfImage *img = NULL;
    const sfUint8 *pixels = NULL;

    my_printf("Input the file name to import:\n");
    nb = getline(&buf, &sz, stdin);
    buf[nb - 1] = '\0';
    img = sfImage_createFromFile(buf);
    if (img == NULL) {
        my_printf("Image upload failed!\n");
        return;
    }
    pixels = sfImage_getPixelsPtr(img);
    change_pixels(ast, pixels, img);
    sfImage_destroy(img);
}
