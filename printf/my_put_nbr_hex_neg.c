/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_put_nbr_hex_neg.c
*/

#include "include/my.h"

int my_put_nbr_hex_neg(long int nbr, int *count)
{
    long int i;

    if (nbr < 0) {
        i = 4294967296 + nbr;
        my_putnbr_hex(i, count);
    }
    return 0;
}

int my_put_nbr_hex_maj_neg(long int nbr, int *count)
{
    long int i;

    if (nbr < 0) {
        i = 4294967296 + nbr;
        my_putnbr_hex_maj(i, count);
    }
    return 0;
}
