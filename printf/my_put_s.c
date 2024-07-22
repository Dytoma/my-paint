/*
** EPITECH PROJECT, 2023
** DISPLAY
** File description:
** Display characters to the screen
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <stdarg.h>
#include <wctype.h>

int my_putchar_pf(va_list ptr, int *count)
{
    char c = va_arg(ptr, int);

    write(1, &c, 1);
    if (c == '\n') {
        return 0;
    }
    *count = *count + 1;
    return 0;
}

int my_putchar_pfl(va_list ptr, int *count)
{
    wint_t c = va_arg(ptr, wint_t);

    write(1, &c, 1);
    if (c == '\n') {
        return 0;
    }
    *count = *count + 1;
    return 0;
}

int my_putchar(char c, int *count)
{
    write(1, &c, 1);
    if (c == '\n') {
        return 0;
    }
    *count = *count + 1;
    return 0;
}

int my_putstr_pf(va_list ptr, int *count)
{
    int i = 0;
    char const *str = va_arg(ptr, char const *);

    while (str[i] != '\0') {
        my_putchar(str[i], count);
        i++;
    }
    return 0;
}

int my_putstr(char const *str, int *count)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i], count);
        i++;
    }
    return 0;
}
