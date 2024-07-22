/*
** EPITECH PROJECT, 2024
** B-CPE-200-TLS-2-1-robotfactory-dytoma.batogouma
** File description:
** print_content
*/

#include "include/my.h"

void print_content(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i] == NULL)
            return;
        my_printf("%s\n", tab[i]);
    }
    return;
}

void destroy_arr(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
    return;
}
