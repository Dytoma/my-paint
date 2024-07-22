/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** my_put_float
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include <stdarg.h>

int decimal_point(double nb, int p, int *count)
{
    long int i;
    long int digit;
    int r;
    long int last = nb * power_10(p + 1);

    if ((last % 10) > 5) {
        return 1;
    }
    for (i = 10; i < (power_10(p) * 10); i = i * 10) {
        digit = (long int)(nb * i);
        if (digit % 10 == 0) {
            r = 0;
            continue;
        } else {
            r = 1;
            break;
        }
    }
    return r;
}

int my_put_float_pf(va_list ptr, int *count)
{
    double nb = va_arg(ptr, double);

    if (nb < 0 && nb > -1) {
        my_putchar('-', count);
    }
    my_put_float(nb, count, 6);
    return 0;
}

int my_put_float(double nb, int *count, int p)
{
    long int even_part = (long int)nb;
    long int digit;
    long int last;

    display_sign(nb, count);
    if (nb < 0) {
        nb = (-1) * nb;
    }
    my_put_long(even_part, count);
    my_putchar('.', count);
    for (long int i = 10; i < (power_10(p) * 10); i *= 10) {
        digit = (long int)(nb * i);
        last = (long int)(nb * i * 10);
        if (i == power_10(p) && (last % 10) >= 5) {
            my_putchar((digit % 10) + 49, count);
            break;
        }
        my_putchar((digit % 10) + 48, count);
    }
    return 0;
}

void decimals(double nb, int *count, int p)
{
    long int i = 10;
    long int digit;
    long int last;

    for (i = 10; i < (power_10(p) * 10); i *= 10) {
        digit = (long int)(nb * i);
        last = (long int)(nb * i * 10);
        if (i == power_10(p) && (last % 10) > 5) {
            my_putchar((digit % 10) + 49, count);
            break;
        }
        if ((digit % 10) == 0 && display_decimal(p, i, nb, count) == 1) {
            my_putchar('0', count);
            continue;
        }
        if ((digit % 10) == 0 && display_decimal(p, i, nb, count) == 0) {
            break;
        }
        my_putchar((digit % 10) + 48, count);
    }
}

int my_put_floatg(double nb, int *count, int p)
{
    long int even_part = (long int)nb;

    display_sign(nb, count);
    if (nb < 0) {
        nb = (-1) * nb;
    }
    my_put_long(even_part, count);
    if (decimal_point(nb, p, count) == 1) {
        my_putchar('.', count);
    }
    decimals(nb, count, p);
    return 0;
}
