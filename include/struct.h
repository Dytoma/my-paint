/*
** EPITECH PROJECT, 2024
** B-MUL-TLS-bsmy_paint-2
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/Graphics/Export.h>

#ifndef STRUCT_H_
    #define STRUCT_H_
    #define WIDTH 1920
    #define HEIGHT 1080
    #define BPP 32
    #define RADIUS 12
    #define BOARD_W 1348
    #define BOARD_H 708

typedef enum {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
} e_gui_state;

typedef enum {
    ACTIVE,
    UNACTIVE
} clr_slcted;

typedef enum {
    BRUSH = 0,
    CIRCLE,
    CLOSE,
    COPY,
    ERASER,
    FICHIER,
    FILL,
    FOLDER,
    LEFT_BAR,
    MINUS,
    PASTE,
    PENCIL,
    PLUS,
    RECTANGLE,
    RIGHT_BAR,
    SAVE,
    SCISSOR,
    UP_BAR
} tool;

typedef enum {
    BROWN = 0,
    DARK_RED,
    KAKI,
    DARK_BLUE_GREEN,
    BLUE,
    DARK,
    LIGHT_BLUE,
    LIGHT_RED,
    BLUE_GREEN,
    PINK,
    WHITE,
    RED,
    GREEN,
    DARK_BLUE,
    DARK_PINK,
    DARK_GREY,
    GREY,
    DARK_GREEN,
    PURPLE,
    LIGHT_GREEN,
} color_t;

typedef struct sprite_text_s {
    sfSprite *sprite;
    sfTexture *textr;
} sprite_text_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfText *btn_txt;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
    e_gui_state state;
} button_t;

typedef struct button_svg_s {
    sfRectangleShape *rect;
    sfText *btn_txt;
    sfSprite *btn_svg;
    sfBool (*is_clicked)(struct button_svg_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_svg_s *, sfMouseMoveEvent *);
    e_gui_state state;
} button_svg_t;

typedef struct button_png_s {
    sfRectangleShape *rect;
    sfSprite *btn_svg;
    sfVector2f pos;
    tool omar;
    sfBool (*is_clicked)(struct button_png_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_png_s *, sfMouseMoveEvent *);
    e_gui_state state;
} button_png_t;

typedef struct s_gui_drop_txt_s {
    button_t *button;
    sfRectangleShape *rect;
    button_t **options;
} s_gui_drop_txt_t;

typedef struct s_gui_drop_menu_s {
    button_t *button;
    sfRectangleShape *rect;
    button_svg_t **options;
} s_gui_drop_menu_t;

typedef struct sprite_s {
    sfSprite *left_bar;
    sfSprite *right_bar;
    sfSprite *up_bar;
} sprite_t;

typedef struct texture_s {
    sfTexture *left_bar_t;
    sfTexture *right_bar_t;
    sfTexture *up_bar_t;
} texture_t;

typedef struct palette_s {
    sfCircleShape *circle;
    sfVector2f pos;
    sfColor clr;
    clr_slcted state;
    color_t paint;
} palette_t;

typedef struct board_s {
    sfUint8 *pixels;
    sfImage *image;
    sfTexture *txtr;
    sfSprite *sprt;
    e_gui_state state;
    color_t paint;
    sfVector2i prev;
} board_t;

typedef struct all_s {
    sfTexture **tab_texture;
    sfFont *poppins;
    palette_t **colors;
    board_t *board;
    tool omar;
    sfRenderWindow *window;
} all_t;

typedef struct left_bar_s {
    button_png_t **arr;
    sfText *txt;
} left_bar_t;

typedef struct up_bar_s {
    s_gui_drop_txt_t *help;
    s_gui_drop_menu_t *edit;
    s_gui_drop_menu_t *file;
    button_png_t *save;
} up_bar_t;

#endif /* !STRUCT_H_ */
