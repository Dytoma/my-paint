/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** print_long
*/

#include <stdarg.h>
#include <stddef.h>
#include "include/my.h"

int my_putstr_pfl(va_list ptr, int *count)
{
    int i = 0;
    const wchar_t *str = va_arg(ptr, const wchar_t *);

    while (str[i] != '\0') {
        my_putchar(str[i], count);
        i++;
    }
    return 0;
}

int print_long(va_list ptr, int *count, char c)
{
    char flagl[] = "dioxXncs";
    int (*tab[])(va_list ptr, int *count) = {my_put_long_pf, my_put_long_pf,
    my_putnbr_oct_pf, my_putnbr_hex_pf, my_putnbr_hex_pf_maj, my_print_nl,
    my_putchar_pfl, my_putstr_pfl};
    int i = 0;

    while (flagl[i] != '\0') {
        if (flagl[i] == c) {
            (*tab[i])(ptr, count);
            return 1;
        }
        i++;
    }
    return 0;
}
