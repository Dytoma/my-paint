/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** my_put_e
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include <stdarg.h>

int my_put_scientific_pf(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);
    double first = nb / (power_10(my_count_digit(nb) - 1));
    int i;

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

int my_put_scientific_pf_maj(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);
    double first = nb / (power_10(my_count_digit(nb) - 1));
    int i = 0;

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

int my_put_scientific(double nb, char c)
{
    int count = 0;
    double first = nb / (double)(power_10(my_count_digit(nb) - 1));

    my_put_float(first, &count, 6);
    my_putchar(c, &count);
    my_putchar('+', &count);
    put_zeros(my_count_digit(nb) - 1, 2);
    return count;
}

int my_put_scientific_precision(double nb, char c, int pre)
{
    int count = 0;
    double first = nb / (double)(power_10(my_count_digit(nb) - 1));
    int i;

    if (nb > (-1) && nb < 1) {
        i = count_negative_power(&nb);
        my_put_floatg(nb, &count, pre);
        my_putchar(c, &count);
        my_putchar('-', &count);
        put_zeros(i, 2);
        return 0;
    }
    my_put_floatg(first, &count, pre);
    my_putchar(c, &count);
    my_putchar('+', &count);
    put_zeros(my_count_digit(nb) - 1, 2);
    return count;
}

int my_put_scientific_hash(double nb, char c, int pre)
{
    int count = 0;
    double first = nb / (double)(power_10(my_count_digit(nb) - 1));
    int i;

    if (nb > (-1) && nb < 1) {
        i = count_negative_power(&nb);
        my_put_float(nb, &count, pre);
        my_putchar(c, &count);
        my_putchar('-', &count);
        put_zeros(i, 2);
        return 0;
    }
    my_put_float(first, &count, pre);
    my_putchar(c, &count);
    my_putchar('+', &count);
    put_zeros(my_count_digit(nb) - 1, 2);
}
