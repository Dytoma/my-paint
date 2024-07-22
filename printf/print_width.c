/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** print_width
*/

#include <unistd.h>
#include "include/my.h"

int is_a_digit(char c)
{
    int n = c;

    if (n > 47 && n < 58) {
        return 1;
    }
    return 0;
}

int get_number(const char *format, int j, int *nbr)
{
    int n = format[j];

    if (is_a_digit(format[j]) == 1) {
        *nbr = *nbr * 10 + (n - 48);
    }
    if (is_a_digit(format[j + 1]) == 1) {
        get_number(format, j + 1, nbr);
    } else {
        return 0;
    }
    return 1;
}

int put_nbr_width_plus(int nb, int spaces, int *count)
{
    int i = 0;

    while (i < spaces) {
        my_putchar(' ', count);
        i++;
    }
    my_put_nbr(nb, count);
    return 0;
}

int put_nbr_width_minus(int nb, int spaces, int *count)
{
    int i = 0;

    my_put_nbr(nb, count);
    while (i < spaces) {
        my_putchar(' ', count);
        i++;
    }
    return 0;
}

void print_nbr_width(int nb, int width, int *count)
{
    int n = 0;
    int w = 0;
    int i = 0;

    increase_count(nb, &n);
    if (width < 0) {
        w = width * (-1);
    } else {
        w = width;
    }
    if (w < n) {
        my_put_nbr(nb, count);
        return;
    }
    if (width > 0) {
        put_nbr_width_plus(nb, (w - n), count);
        return;
    } else {
        put_nbr_width_minus(nb, (w - n), count);
    }
}
