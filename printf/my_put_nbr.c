/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** Display a num to the screen
*/

#include <stdarg.h>
#include "include/my.h"

int maximum_num(int *count)
{
    my_putchar('9', count);
    my_putchar('2', count);
    my_putchar('2', count);
    my_putchar('3', count);
    my_putchar('3', count);
    my_putchar('7', count);
    my_putchar('2', count);
    my_putchar('0', count);
    my_putchar('3', count);
    my_putchar('6', count);
    my_putchar('8', count);
    my_putchar('5', count);
    my_putchar('4', count);
    my_putchar('7', count);
    my_putchar('7', count);
    my_putchar('5', count);
    my_putchar('8', count);
    my_putchar('8', count);
    return 0;
}

int max_num(int *count)
{
    my_putchar('1', count);
    my_putchar('2', count);
    my_putchar('4', count);
    my_putchar('7', count);
    my_putchar('4', count);
    my_putchar('8', count);
    my_putchar('3', count);
    my_putchar('6', count);
    my_putchar('4', count);
    my_putchar('8', count);
    return 0;
}

int my_put_long(long int nb, int *count)
{
    int rest;

    if (nb < 0) {
        my_putchar('-', count);
        nb = (-1) * nb;
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48, count);
    }
    if (nb < -9223372036854775807) {
        maximum_num(count);
    } else if (nb > 9) {
        rest = (nb % 10) + 48;
        my_put_nbr(nb / 10, count);
        my_putchar(rest, count);
    }
    return 0;
}

int my_put_long_pf(va_list ptr, int *count)
{
    long int nbr = (long int)va_arg(ptr, long int);

    my_put_long(nbr, count);
    return 0;
}

int my_put_nbr(int nb, int *count)
{
    int rest;

    if (nb < 0) {
        my_putchar('-', count);
        nb = (-1) * nb;
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48, count);
    }
    if (nb == -2147483648) {
        max_num(count);
    } else if (nb > 9) {
        rest = (nb % 10) + 48;
        my_put_nbr(nb / 10, count);
        my_putchar(rest, count);
    }
    return 0;
}
