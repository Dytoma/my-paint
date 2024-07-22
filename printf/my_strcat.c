/*
** EPITECH PROJECT, 2023
** MY_STRCAT
** File description:
** Concatenates two strings
*/

#include "include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0') {
        dest[j + len] = src[j];
        j++;
    }
    dest[len + j] = '\0';
    return dest;
}
