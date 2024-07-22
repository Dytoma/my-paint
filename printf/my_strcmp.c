/*
** EPITECH PROJECT, 2023
** MY_STRCMP
** File description:
** Compare two strings
*/

#include "include/my.h"
#include "stdlib.h"

int value_return(int n)
{
    if (n > 0) {
        return 1;
    } else {
        return -1;
    }
}

int convert_maj(char c)
{
    int ascii = c;

    if (ascii >= 65 && ascii <= 90) {
        ascii = ascii + 32;
    }
    return ascii;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int result;

    while (s1[i] != '\0' && s2[i] != '\0') {
        result = convert_maj(s1[i]) - convert_maj(s2[i]);
        if (result == 0) {
            i++;
        } else {
            return value_return(result);
        }
    }
    if (my_strlen(s1) > my_strlen(s2)) {
        return 1;
    } else if (my_strlen(s1) < my_strlen(s2)) {
        return -1;
    }
    return 0;
}

int my_strcmp_ls(char const *s1, char const *s2)
{
    int i = 0;
    int result;

    while (s1[i] != '\0' && s2[i] != '\0') {
        result = s1[i] - s2[i];
        if (result == 0) {
            i++;
        } else {
            return result;
        }
    }
    if (my_strlen(s1) > my_strlen(s2)) {
        return 1;
    } else if (my_strlen(s1) < my_strlen(s2)) {
        return -1;
    }
    return 0;
}
