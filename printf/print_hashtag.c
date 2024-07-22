/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** print_hashtag
*/

#include <stdarg.h>
#include "include/my.h"

int my_putnbr_hex_hash(va_list ptr, int *count)
{
    long int nbr = va_arg(ptr, long int);

    if (nbr != 0) {
        my_putstr("0x", count);
    }
    if (nbr < 0){
        my_put_nbr_hex_neg(nbr, count);
        return 0;
    }
    my_putnbr_hex(nbr, count);
    return 0;
}

int my_putnbr_hex_hash_maj(va_list ptr, int *count)
{
    long int nbr = va_arg(ptr, long int);

    if (nbr != 0) {
        my_putstr("0X", count);
    }
    if (nbr < 0){
        my_put_nbr_hex_maj_neg(nbr, count);
        return 0;
    }
    my_putnbr_hex_maj(nbr, count);
    return 0;
}

int my_put_global_hash(va_list ptr, int *count)
{
    double nb = (double)va_arg(ptr, double);
    int X;
    int i;

    if (nb > -1 && nb < 1) {
        i = count_negative_pwr(nb);
        if (i < 6 && i >= -4) {
            my_put_float(nb, count, 6);
            return 0;
        }
        my_put_scientific_hash(nb, 'e', 5);
    } else {
        X = my_count_digit(nb);
        if (X < 7 && X >= -4) {
            my_put_float(nb, count, (6 - (X)));
            return 0;
        }
        my_put_scientific_hash(nb, 'e', (6 - 1));
    }
    return 0;
}

int print_hash(va_list ptr, int *count, char c)
{
    char flag_hash[] = "oxXeEfFgG";
    int (*tab[])(va_list ptr, int *count) = {my_putnbr_oct_hash,
    my_putnbr_hex_hash, my_putnbr_hex_hash_maj, my_put_scientific_pf,
    my_put_scientific_pf_maj, my_put_float_pf, my_put_float_pf,
    my_put_global_hash, put_global_hash};
    int i = 0;

    while (flag_hash[i] != '\0') {
        if (flag_hash[i] == c) {
            (*tab[i])(ptr, count);
            return 1;
        }
        i++;
    }
    return 0;
}
