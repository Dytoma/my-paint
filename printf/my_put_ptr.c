/*
** EPITECH PROJECT, 2023
** MY_PUT_PTR
** File description:
** Display pointer
*/

#include <stdarg.h>
#include "include/my.h"

void display_rest(int rest, char *str, int *count)
{
    int i = 0;

    while (str[i] != '\0') {
        if (rest == i) {
            my_putchar(str[i], count);
            return;
        }
        i++;
    }
}

int my_put_ptr(va_list ptr, int *count)
{
    long int point = (long int)va_arg(ptr, void *);

    my_putchar('0', count);
    my_putchar('x', count);
    my_putnbr_hex(point, count);
    return 0;
}
