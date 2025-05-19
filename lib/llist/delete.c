/*
** EPITECH PROJECT, 2024
** llist
** File description:
** Delete in linked list
*/

#include "llist.h"

void delete_in_list(linked_list_t **begin, void const *ref,
    int(*cmp_fct)(void *, void const *))
{
    linked_list_t *previous = malloc(sizeof(linked_list_t));
    linked_list_t *current = NULL;
    linked_list_t *temp = NULL;

    previous->next = *begin;
    current = previous;
    while (current->next != NULL) {
        temp = current->next;
        if ((*cmp_fct)(current->next->data, ref) == 0) {
            current->next = current->next->next;
            free(temp);
        } else
            current = current->next;
    }
    *begin = previous->next;
    free(previous);
}
