/*
** EPITECH PROJECT, 2023
** MY_STRLEN
** File description:
** Displays the number of char
*/

#include "include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (*(str + i) != '\0') {
        i++;
    }
    return i;
}
