/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-mypaint-dytoma.batogouma
** File description:
** my_str_capitalize
*/

#include "my_paint.h"

char *my_strcapitalize(char *str)
{
    char *capitalize = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            capitalize[i] = str[i] - 32;
            continue;
        }
        capitalize[i] = str[i];
    }
    capitalize[i] = '\0';
    return capitalize;
}
