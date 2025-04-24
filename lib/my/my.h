/*
** EPITECH PROJECT, 2024
** libmy
** File description:
** Header for libmy
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>

// Display
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_show_word_array(char *const *tab);
int mini_printf(const char *format, ...);

// Number related
int my_intlen(int i);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);

// Char & string related
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcasecmp(char const *s1, char const *s2);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int nb);
int my_char_alpha(char c);
int my_char_isnum(char c);
char *my_strchr(char *s, int c);
int my_is_in_string(char *string, char element);

// String array related
int my_array_length(char **array);
void free_my_str_array(char **array);
int my_sort_word_array(char **tab);
char **my_str_to_word_array(char const *str);
char **my_str_to_custom_array(char const *str, char split_c);

// Memory / pointers related
void my_swap(void *a, void *b);
void *my_calloc(int nmemb, int size);
void *my_memset(void *s, int c, int n);

#endif
