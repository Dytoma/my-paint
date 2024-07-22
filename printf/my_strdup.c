/*
** EPITECH PROJECT, 2023
** MY_STRDUP
** File description:
** Allocates and copies strings
*/

#include <stdlib.h>
#include "include/my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    int i = 0;
    char *new_str = malloc(sizeof(char) * (len + 1));

    while (i < len) {
        new_str[i] = src[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}
