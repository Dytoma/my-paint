/*
** EPITECH PROJECT, 2023
** MY_STRCPY
** File description:
** Copy string into another
*/

#include "include/my.h"

int my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int n = my_strlen(src);

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[n] = '\0';
    return 0;
}
