/*
** EPITECH PROJECT, 2023
** MY_STRNCMP
** File description:
** Compare n characters in strings
*/

#include "include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int result = 0;

    if (n < 0) {
        return -1;
    }
    while (i < n && (s1[i] != '\0' || s2[i] != '\0')) {
        result = s1[i] - s2[i];
        if (result == 0) {
            i++;
        } else {
            return result;
        }
    }
    if (i < n) {
        return 1;
    }
    return 0;
}
