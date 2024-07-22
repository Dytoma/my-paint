/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** print_plus.c
*/

#include "include/my.h"
#include <stdio.h>

int put_global_p(double nb, int *count)
{
    int X;
    int i;

    if (nb > -1 && nb < 1) {
        i = count_negative_pwr(nb);
        if (i < 6 && i >= -4) {
            my_put_floatg(nb, count, 6);
            return 0;
        }
        my_put_scientific_precision(nb, 'E', 5);
    } else {
        X = my_count_digit(nb);
        if (X < 7 && X >= -4) {
            my_put_floatg(nb, count, (6 - (X)));
            return 0;
        }
        my_put_scientific_precision(nb, 'E', (6 - 1));
    }
    return 0;
}

int my_put_global_p(double nb, int *count)
{
    int X;
    int i;

    if (nb > -1 && nb < 1) {
        i = count_negative_pwr(nb);
        if (i < 6 && i >= -4) {
            my_put_floatg(nb, count, 6);
            return 0;
        }
        my_put_scientific_precision(nb, 'e', 5);
    } else {
        X = my_count_digit(nb);
        if (X < 7 && X >= -4) {
            my_put_floatg(nb, count, (6 - (X)));
            return 0;
        }
        my_put_scientific_precision(nb, 'e', (6 - 1));
    }
    return 0;
}

int my_put_plus_global(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);

    if (nb > 0) {
        my_putchar('+', count);
    }
    my_put_global_p(nb, count);
    return 0;
}

int print_plus(va_list ptr, int *count, char c)
{
    int i = 0;
    int (*tab[])(va_list ptr, int *count) = {my_put_plus_long,
    my_put_plus_long, my_print_plus_float, my_print_plus_float,
    my_put_plus_scientific, my_put_plus_scientific_maj, my_put_plus_global,
    put_plus_global};
    char flag_plus[] = "difFeEgG";

    while (flag_plus[i] != '\0') {
        if (flag_plus[i] == c) {
            (*tab[i])(ptr, count);
            return 1;
        }
        i++;
    }
    return 0;
}
