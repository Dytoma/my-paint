/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** print_precision.c
*/

#include "include/my.h"
#include <stdarg.h>

int print_precision(va_list ptr, int *count, int nbr, char c)
{
    int i = 0;
    int (*tab[])(va_list ptr, int *count, int nbr) = {my_put_float_precision,
    my_put_float_precision, my_put_scientific_dot,
    my_put_scientific_precision_maj, my_put_global_precision,
    put_global_precision};
    char flag_plus[] = "fFeEgG";

    while (flag_plus[i] != '\0') {
        if (flag_plus[i] == c) {
            (*tab[i])(ptr, count, nbr);
            return 1;
        }
        i++;
    }
    return 0;
}

int get_precision(va_list ptr, const char *format, int j, int *count)
{
    int nbre = 0;
    int y = 0;

    get_number(format, (j + 1), &nbre);
    increase_count(nbre, &y);
    print_precision(ptr, count, nbre, format[j + y + 1]);
    return y;
}
