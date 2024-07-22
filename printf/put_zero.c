/*
** EPITECH PROJECT, 2023
** MY_PRINTF
** File description:
** Complete zeros
*/

#include "include/my.h"

int put_zeros(unsigned int nb, int zeros)
{
    double nbr = (double)nb;
    int n = my_count_digit(nbr);
    int i = 0;
    int count = 0;

    if (zeros <= n){
        my_put_nbr(nb, &count);
        return count;
    }
    while (i < (zeros - n)) {
        my_putchar('0', &count);
        i++;
    }
    my_put_nbr(nb, &count);
    return count;
}

int my_putchar_percent(va_list ptr, int *count)
{
    my_putchar('%', count);
    return 0;
}
