/*
** EPITECH PROJECT, 2024
** B-PSU-200-TLS-2-1-minishell1-dytoma.batogouma
** File description:
** my_strdup_arr
*/

#include "include/my.h"
#include <stdlib.h>

int count_args(char **arg)
{
    int n = 0;

    for (int i = 0; arg[i] != NULL; i++) {
        n++;
    }
    return n;
}

char **reserve_mem(char **src, int n)
{
    char **dup = malloc(sizeof(char *) * (count_args(src) + 1 + n));

    if (dup == NULL)
        return NULL;
    for (int i = 0; src[i] != NULL; i++) {
        dup[i] = malloc(sizeof(char) * (my_strlen(src[i]) + 1));
    }
    return dup;
}

char **my_arrdup(char **src)
{
    char **dup = NULL;
    int i = 0;
    int j = 0;

    if (src == NULL)
        return NULL;
    dup = malloc(sizeof(char *) * (count_args(src) + 1));
    for (i = 0; src[i] != NULL; i++) {
        dup[i] = my_strdup(src[i]);
    }
    dup[i] = NULL;
    return dup;
}
