/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** Print hexadecimal numbers
*/

#include "include/my.h"
#include <stdarg.h>

int my_putnbr_hex(long int nbr, int *count)
{
    int rest;
    long int multiple;
    char str[] = "0123456789abcdef";

    rest = nbr % 16;
    multiple = nbr / 16;
    if (multiple != 0) {
        my_putnbr_hex(multiple, count);
    }
    display_rest(rest, str, count);
    return 0;
}

int my_putnbr_hex_pf(va_list ptr, int *count)
{
    long int nbr = va_arg(ptr, long int);

    if (nbr < 0){
        my_put_nbr_hex_neg(nbr, count);
        return 0;
    }
    my_putnbr_hex(nbr, count);
    return 0;
}

int my_putnbr_hex_pfh(va_list ptr, int *count)
{
    short nbr = (short int)(va_arg(ptr, int));

    if (nbr < 0){
        my_put_nbr_hex_neg(nbr, count);
        return 0;
    }
    my_putnbr_hex(nbr, count);
    return 0;
}

int my_putnbr_hex_maj(long int nbr, int *count)
{
    int rest;
    long int multiple;
    char str[] = "0123456789ABCDEF";

    rest = nbr % 16;
    multiple = nbr / 16;
    if (multiple != 0) {
        my_putnbr_hex_maj(multiple, count);
    }
    display_rest(rest, str, count);
    return 0;
}

int my_putnbr_hex_pf_maj(va_list ptr, int *count)
{
    long int nbr = va_arg(ptr, long int);

    if (nbr < 0){
        my_put_nbr_hex_maj_neg(nbr, count);
        return 0;
    }
    my_putnbr_hex_maj(nbr, count);
    return 0;
}
