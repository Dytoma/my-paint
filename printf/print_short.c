/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** print_short
*/

#include "include/my.h"
#include <stdarg.h>

int my_put_long_pfh(va_list ptr, int *count)
{
    short int nbr = (short int)va_arg(ptr, int);

    my_put_nbr(nbr, count);
    return 0;
}

int my_putnbr_hex_pfh_maj(va_list ptr, int *count)
{
    short int nbr = (short int)(va_arg(ptr, int));

    if (nbr < 0){
        my_put_nbr_hex_maj_neg(nbr, count);
        return 0;
    }
    my_putnbr_hex_maj(nbr, count);
    return 0;
}

int print_h(va_list ptr, int *count, char c)
{
    int i = 0;
    int (*tab[])(va_list ptr, int *count) = {my_put_long_pfh, my_put_long_pfh,
    my_putnbr_oct_pf, my_putnbr_hex_pfh, my_putnbr_hex_pfh_maj, my_print_n};
    char flagh[] = "dioxXn";

    while (flagh[i] != '\0') {
        if (flagh[i] == c) {
            (*tab[i])(ptr, count);
            return 1;
        }
        i++;
    }
    return 0;
}
