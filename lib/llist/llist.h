/*
** EPITECH PROJECT, 2024
** llist
** File description:
** Header file for linked list functions.
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_
    #include <stdbool.h>
    #include <stdlib.h>

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

void push_to_list(linked_list_t **begin, void *data);
void push_to_end_list(linked_list_t **begin, void *data);
void display_list(linked_list_t *begin, void(*disp_fct)());
bool replace_in_list(linked_list_t *begin, void *input,
    bool(*compare)(), void *new_data);
void *search_in_list(linked_list_t *begin, void *input, bool(*compare)());
void delete_in_list(linked_list_t **begin, void const *ref, int(*cmp_fct)());
linked_list_t *duplicate_llist(linked_list_t *begin,
    void *(*duplicate_data)());
void free_llist(linked_list_t *begin, void(*destroy_data)());
int length_llist(linked_list_t *begin);

#endif
