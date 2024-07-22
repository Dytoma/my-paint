/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** precision.c
*/

#include "include/my.h"
#include <stdarg.h>

int my_put_float_precision(va_list ptr, int *count, int nbr)
{
    double nb = va_arg(ptr, double);

    if (nb < 0 && nb > -1) {
        my_putchar('-', count);
    }
    my_put_float(nb, count, nbr);
    return 0;
}

int my_put_scientific_dot(va_list ptr, int *count, int nbr)
{
    double nb = (double)va_arg(ptr, double);
    double first = nb / (power_10(my_count_digit(nb) - 1));
    int i;

    if (nb > (-1) && nb < 1) {
        i = count_negative_power(&nb);
        my_put_float(nb, count, nbr);
        my_putchar('e', count);
        my_putchar('-', count);
        put_zeros(i, 2);
        return 0;
    }
    my_put_float(first, count, nbr);
    my_putchar('e', count);
    my_putchar('+', count);
    put_zeros(my_count_digit(nb) - 1, 2);
    return 0;
}

int my_put_scientific_precision_maj(va_list ptr, int *count, int nbr)
{
    double nb = (double)va_arg(ptr, double);
    double first = nb / (power_10(my_count_digit(nb) - 1));
    int i = 0;

    if (nb > (-1) && nb < 1) {
        i = count_negative_power(&nb);
        my_put_float(nb, count, nbr);
        my_putchar('E', count);
        my_putchar('-', count);
        put_zeros(i, 2);
        return 0;
    }
    my_put_float(first, count, nbr);
    my_putchar('E', count);
    my_putchar('+', count);
    put_zeros(my_count_digit(nb) - 1, 2);
    return 0;
}

int my_put_global_precision(va_list ptr, int *count, int nbr)
{
    double nb = (double)va_arg(ptr, double);
    int X;
    int i;

    if (nb > -1 && nb < 1) {
        i = count_negative_pwr(nb);
        if (i < nbr && i >= -4) {
            my_put_floatg(nb, count, nbr);
            return 0;
        }
        my_put_scientific_precision(nb, 'e', nbr - 1);
    } else {
        X = my_count_digit(nb);
        if (X < (nbr + 1) && X >= -4) {
            my_put_floatg(nb, count, (nbr - (X)));
            return 0;
        }
        my_put_scientific_precision(nb, 'e', (nbr - 1));
    }
    return 0;
}

int put_global_precision(va_list ptr, int *count, int nbr)
{
    double nb = (double)va_arg(ptr, double);
    int X;
    int i;

    if (nb > -1 && nb < 1) {
        i = count_negative_pwr(nb);
        if (i < nbr && i >= -4) {
            my_put_floatg(nb, count, nbr);
            return 0;
        }
        my_put_scientific_precision(nb, 'E', nbr - 1);
    } else {
        X = my_count_digit(nb);
        if (X < (nbr + 1) && X >= -4) {
            my_put_floatg(nb, count, (nbr - (X)));
            return 0;
        }
        my_put_scientific_precision(nb, 'E', (nbr - 1));
    }
    return 0;
}
