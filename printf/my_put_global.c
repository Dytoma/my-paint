/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** my_put_global
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/my.h"

int display_decimal(int p, long int i, double nb, int *count)
{
    long int digit;
    long int last = (long int)(nb * power_10(p + 1));
    long int j;

    for (j = i * 10; j < (power_10(p) * 10); j = j * 10) {
        digit = (long int)(nb * j);
        if ((digit % 10) != 0) {
            return 1;
        }
        if ((digit % 10) == 0 && (last % 10) > 5) {
            return 1;
        }
    }
    return 0;
}

int my_put_global(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);
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

void display_sign(double nb, int *count)
{
    if (nb < 0 && nb > -1) {
        my_putchar('-', count);
    }
}

int put_global(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);
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

int put_global_hash(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);
    int X;
    int i;

    if (nb > -1 && nb < 1) {
        i = count_negative_pwr(nb);
        if (i < 6 && i >= -4) {
            my_put_float(nb, count, 6);
            return 0;
        }
        my_put_scientific_hash(nb, 'E', 5);
    } else {
        X = my_count_digit(nb);
        if (X < 7 && X >= -4) {
            my_put_float(nb, count, (6 - (X)));
            return 0;
        }
        my_put_scientific_hash(nb, 'E', (6 - 1));
    }
    return 0;
}
