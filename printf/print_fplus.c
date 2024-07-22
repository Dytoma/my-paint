/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** print_fplus.c
*/

#include "include/my.h"
#include <stdarg.h>

int my_print_plus_float(va_list ptr, int *count)
{
    double nb = va_arg(ptr, double);

    if (nb > 0) {
        my_putchar('+', count);
    }
    if (nb < 0 && nb > -1) {
        my_putchar('-', count);
    }
    my_put_float(nb, count, 6);
    return 0;
}

int my_put_plus_long(va_list ptr, int *count)
{
    long nbr = (long)va_arg(ptr, long);

    if (nbr > 0) {
        my_putchar('+', count);
    }
    my_put_long(nbr, count);
    return 0;
}

int my_put_plus_scientific(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);
    double first = nb / (power_10(my_count_digit(nb) - 1));
    int i;

    if (nb > 0) {
        my_putchar('+', count);
    }
    if (nb > (-1) && nb < 1) {
        i = count_negative_power(&nb);
        my_put_float(nb, count, 6);
        my_putchar('e', count);
        my_putchar('-', count);
        put_zeros(i, 2);
        return 0;
    }
    my_put_float(first, count, 6);
    my_putchar('e', count);
    my_putchar('+', count);
    put_zeros(my_count_digit(nb) - 1, 2);
    return 0;
}

int my_put_plus_scientific_maj(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);
    double first = nb / (power_10(my_count_digit(nb) - 1));
    int i = 0;

    if (nb > 0) {
        my_putchar('+', count);
    }
    if (nb > (-1) && nb < 1) {
        i = count_negative_power(&nb);
        my_put_float(nb, count, 6);
        my_putchar('E', count);
        my_putchar('-', count);
        put_zeros(i, 2);
        return 0;
    }
    my_put_float(first, count, 6);
    my_putchar('E', count);
    my_putchar('+', count);
    put_zeros(my_count_digit(nb) - 1, 2);
    return 0;
}

int put_plus_global(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);

    if (nb > 0) {
        my_putchar('+', count);
    }
    put_global_p(nb, count);
    return 0;
}
