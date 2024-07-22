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

int increase_count(long int nb, int *count)
{
    int rest;

    if (nb < 0) {
        nb = (-1) * nb;
    }
    if (nb >= 0 && nb <= 9) {
        *count = *count + 1;
    }
    if (nb == -2147483648) {
        *count = 10;
    } else if (nb > 9) {
        rest = (nb % 10) + 48;
        increase_count(nb / 10, count);
        *count = *count + 1;
    }
    return 0;
}

long int power_10(int n)
{
    int i = 0;
    long int count = 1;

    while (i < n) {
        count = count * 10;
        i++;
    }
    return count;
}

int my_count_digit(double nb)
{
    int count = 0;
    long int nbr = (long int)nb;

    increase_count(nbr, &count);
    return count;
}

int count_negative_power(double *nb)
{
    int i = 1;
    double n = *nb * 10;

    while (n < 1 && n > (-1)) {
        i = i + 1;
        n = n * 10;
    }
    *nb = n;
    return i;
}

int count_negative_pwr(double nb)
{
    int i = 1;
    double n = nb * 10;

    while (n < 1 && n > (-1)) {
        i = i + 1;
        n = n * 10;
    }
    return - 1 * i;
}
