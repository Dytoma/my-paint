/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** display.c
*/

#include "include/my.h"

int is_percent(char c)
{
    if (c == '%')
        return 0;
    return 1;
}

int is_spec_char(char c)
{
    switch (c) {
    case 'd':
        return 1;
    case 'i':
        return 2;
    case 's':
        return 3;
    case 'c':
        return 4;
    case '%':
        return 5;
    }
    return -1;
}
