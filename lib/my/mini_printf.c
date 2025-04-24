/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** A simple version of printf with a few flags and that does not manage text
** formating and buffering.
*/

#include "my.h"

static void display_string(va_list list, int *return_value)
{
    char *str;

    str = va_arg(list, char *);
    my_putstr(str);
    *return_value = *return_value + my_strlen(str);
}

static void display_int(va_list list, int *return_value)
{
    int i;

    i = va_arg(list, int);
    my_put_nbr(i);
    *return_value = *return_value + my_intlen(i);
}

static void display_char(char c, int *return_value)
{
    my_putchar(c);
    *return_value = *return_value + 1;
}

static void check_format(char c, va_list list, int *return_value)
{
    switch (c) {
        case 'c':
            display_char(va_arg(list, int), return_value);
            break;
        case 's':
            display_string(list, return_value);
            break;
        case 'i':
        case 'd':
            display_int(list, return_value);
            break;
        case '%':
            display_char('%', return_value);
            break;
        default:
            display_char(c, return_value);
            break;
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int len = my_strlen(format);
    int return_value = 0;

    va_start(list, format);
    for (int i = 0; i < len; i++) {
        if (format[i] == '%' && i + 1 < len) {
            check_format(format[i + 1], list, &return_value);
            i++;
        } else {
            return_value++;
            my_putchar(format[i]);
        }
    }
    va_end(list);
    return return_value;
}
