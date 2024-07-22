/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Include prototypes
*/

#include <stdarg.h>
#include <stddef.h>
#include <wctype.h>
#include <stdlib.h>

#ifndef MY_H
    #define MY_H

int my_put_long(long int nb, int *count);
int my_putchar_pf(va_list ptr, int *count);
int my_putchar(char c, int *count);
int max_num(int *count);
int maximum_num(int *count);
int my_put_nbr(int nb, int *count);
int my_putstr_pf(va_list ptr, int *count);
int my_putstr(char const *str, int *count);
int my_put_float_pf(va_list ptr, int *count);
void display_rest(int rest, char *str, int *count);
int my_putnbr_hex(long int nbr, int *count);
int my_putnbr_hex_pf(va_list ptr, int *count);
int my_putnbr_oct(long int nbr, int *count);
int my_put_ptr(va_list ptr, int *count);
int my_put_float(double nb, int *count, int p);
int my_putnbr_oct_pf(va_list ptr, int *count);
int my_put_long_pf(va_list ptr, int *count);
int increase_count(long int nb, int *count);
long int power_10(int n);
int my_count_digit(double nb);
int my_put_scientific(double nb, char c);
int my_put_scientific_pf(va_list ptr, int *count);
int my_put_scientific_pf_maj(va_list ptr, int *count);
int put_zeros(unsigned int nb, int zeros);
int my_putnbr_hex_maj(long int nbr, int *count);
int my_putnbr_hex_pf_maj(va_list ptr, int *count);
int is_percent(char c);
int is_spec_char(char c);
int display_arg(char c, int *count, va_list ptr);
int my_printf(const char *format, ...);
int my_put_nbr_hex_neg(long int nbr, int *count);
int my_put_nbr_hex_maj_neg(long int nbr, int *count);
int count_negative_power(double *nb);
int my_put_global(va_list ptr, int *count);
int put_global(va_list ptr, int *count);
int count_negative_pwr(double nb);
int my_put_scientific_precision(double nb, char c, int pre);
int is_a_digit(char c);
int get_number(const char *format, int j, int *nbr);
int put_nbr_width_plus(int nb, int spaces, int *count);
int put_nbr_width_minus(int nb, int spaces, int *count);
void print_nbr_width(int nb, int width, int *count);
int display_nbr_width(const char *format, int j, va_list ptr, int *count);
void print_args(const char *format, int *i, int *count, va_list ptr);
int print_h(va_list ptr, int *count, char c);
int my_put_long_pfh(va_list ptr, int *count);
int my_putnbr_oct_pfh(va_list ptr, int *count);
int my_putnbr_hex_pfh_maj(va_list ptr, int *count);
int my_putnbr_hex_pfh(va_list ptr, int *count);
int my_put_floatg(double nb, int *count, int p);
void display_sign(double nb, int *count);
int display_decimal(int p, long int i, double nb, int *count);
void decimals(double nb, int *count, int p);
int decimal_point(double nb, int p, int *count);
int my_print_n(va_list ptr, int *count);
int my_print_nl(va_list ptr, int *count);
int my_putchar_pfl(va_list ptr, int *count);
int my_putstr_pfl(va_list ptr, int *count);
int print_long(va_list ptr, int *count, char c);
int my_putnbr_oct_hash(va_list ptr, int *count);
int my_putnbr_hex_hash_maj(va_list ptr, int *count);
int my_putnbr_hex_hash(va_list ptr, int *count);
int my_put_scientific_hash(double nb, char c, int pre);
int my_put_global_hash(va_list ptr, int *count);
int put_global_hash(va_list ptr, int *count);
int print_hash(va_list ptr, int *count, char c);
int my_putchar_percent(va_list ptr, int *count);
int my_put_plus_long(va_list ptr, int *count);
int my_print_plus_float(va_list ptr, int *count);
int my_put_plus_scientific(va_list ptr, int *count);
int my_put_plus_scientific_maj(va_list ptr, int *count);
int put_plus_global(va_list ptr, int *count);
int my_put_plus_global(va_list ptr, int *count);
int print_plus(va_list ptr, int *count, char c);
int my_put_global_p(double nb, int *count);
int put_global_p(double nb, int *count);
int print_precision(va_list ptr, int *count, int nbr, char c);
int get_precision(va_list ptr, const char *format, int j, int *count);
int my_put_float_precision(va_list ptr, int *count, int nbr);
int my_put_scientific_dot(va_list ptr, int *count, int nbr);
int my_put_scientific_precision_maj(va_list ptr, int *count, int nbr);
int my_put_global_precision(va_list ptr, int *count, int nbr);
int put_global_precision(va_list ptr, int *count, int nbr);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int convert_maj(char c);
int my_strcmp_ls(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_arrdup(char **src);
int count_args(char **arg);
char **reserve_mem(char **src, int n);
void print_content(char **tab);
void destroy_arr(char **arr);

#endif /* MY_H */
