/*
** EPITECH PROJECT, 2023
** MY_STRNCAT
** File description:
** Concatenates n characters
*/

#include "include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int n = my_strlen(dest);
    int i = 0;

    if (nb < 0) {
        return dest;
    }
    while (i < nb) {
        dest[n + i] = src[i];
        i++;
    }
    dest[n + nb] = '\0';
    return dest;
}
