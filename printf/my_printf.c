/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_printf.c
*/

#include "include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int display_arg(char c, int *count, va_list ptr)
{
    int i = 0;
    int (*tab[])(va_list ptr, int *count) = {my_putchar_pf, my_putstr_pf,
        my_put_float_pf, my_putnbr_hex_pf, my_putnbr_hex_pf_maj, my_put_ptr,
        my_putnbr_oct_pf, my_put_scientific_pf, my_put_scientific_pf_maj,
        my_put_long_pf, my_put_long_pf, my_putchar_percent, my_put_long_pf,
        my_put_global, put_global, my_put_float_pf, my_print_n};
    char flags[18] = {'c', 's', 'f', 'x', 'X', 'p', 'o', 'e', 'E', 'u',
        'i', '%', 'd', 'g', 'G', 'F', 'n', '\0'};

    while (flags[i] != '\0') {
        if (flags[i] == c) {
            (*tab[i])(ptr, count);
            return 1;
        }
        i++;
    }
    return 0;
}

int display_nbr_width(const char *format, int j, va_list ptr, int *count)
{
    int nbr = 0;
    int sign = format[j];
    int n = 1;
    int x = 0;

    if (sign == 45 && (is_a_digit(format[j + 1]) == 1)) {
        n = -1;
        x++;
    }
    get_number(format, j, &nbr);
    increase_count(nbr, &x);
    if (format[j + x] == 'd') {
        print_nbr_width(va_arg(ptr, int), (nbr * n), count);
        return x;
    }
    return 0;
}

void print_args_h(const char *format, int *i, int *count, va_list ptr)
{
    if (format[*i + 1] == '#') {
        print_hash(ptr, count, format[*i + 2]);
        *i = *i + 1;
        return;
    }
    if (format[*i + 1] == '+') {
        print_plus(ptr, count, format[*i + 2]);
        *i = *i + 1;
        return;
    }
    if (format[*i + 1] == '.') {
        *i = *i + get_precision(ptr, format, *i + 1, count);
        *i = *i + 1;
        return;
    }
}

void print_args(const char *format, int *i, int *count, va_list ptr)
{
    if (format[*i + 1] == 'h') {
        print_h(ptr, count, format[*i + 2]);
        *i = *i + 3;
        return;
    }
    if (format[*i + 1] == 'l') {
        print_long(ptr, count, format[*i + 2]);
        *i = *i + 3;
        return;
    }
    if (is_percent(format[*i]) == 0 && is_a_digit(format[*i + 1]) == 0
        && format[*i + 1] != '-') {
        display_arg(format[*i + 1], count, ptr);
        *i = *i + 2;
        return;
    } else {
        *i = *i + display_nbr_width(format, (*i + 1), ptr, count);
        *i = *i + 2;
        return;
    }
}

int my_printf(const char *format, ...)
{
    va_list ptr;
    int count = 0;
    int i = 0;

    va_start(ptr, format);
    while (format[i] != '\0') {
        if (is_percent(format[i]) == 1) {
            my_putchar(format[i], &count);
            i++;
            continue;
        }
        print_args_h(format, &i, &count, ptr);
        print_args(format, &i, &count, ptr);
    }
    va_end(ptr);
    return count;
}
