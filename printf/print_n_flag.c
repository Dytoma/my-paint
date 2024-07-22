/*
** EPITECH PROJECT, 2023
** B-CPE-101-TLS-1-1-myprintf-sofiane.majdoul
** File description:
** print_n_flag
*/

#include <stdarg.h>
#include "include/my.h"

int my_print_n(va_list ptr, int *count)
{
    int *adr = va_arg(ptr, int *);

    *adr = *count;
    return 0;
}

int my_print_nl(va_list ptr, int *count)
{
    long *adr = va_arg(ptr, long *);

    *adr = *count;
    return 0;
}
