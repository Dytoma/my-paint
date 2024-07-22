/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** Print in base octal numbers
*/

#include <stdarg.h>
#include "include/my.h"

int my_putnbr_oct(long int nbr, int *count)
{
    int rest;
    long int multiple;
    char str[] = "01234567";

    rest = nbr % 8;
    multiple = nbr / 8;
    if (multiple != 0) {
        my_putnbr_oct(multiple, count);
    }
    display_rest(rest, str, count);
    return 0;
}

int my_putnbr_oct_pf(va_list ptr, int *count)
{
    long int nbr = va_arg(ptr, long int);

    my_putnbr_oct(nbr, count);
    return 0;
}

int my_putnbr_oct_hash(va_list ptr, int *count)
{
    long int nbr = va_arg(ptr, long int);

    if (nbr != 0) {
        my_putchar('0', count);
    }
    my_putnbr_oct(nbr, count);
    return 0;
}

int my_putnbr_oct_pfh(va_list ptr, int *count)
{
    short int nbr = (short int)(va_arg(ptr, int));

    my_putnbr_oct(nbr, count);
    return 0;
}
