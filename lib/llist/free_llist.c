/*
** EPITECH PROJECT, 2024
** llist
** File description:
** Frees the whole linked list.
*/

#include "llist.h"

void free_llist(linked_list_t *begin, void(*destroy_data)(void *))
{
    linked_list_t *current = begin;
    linked_list_t *temp = NULL;

    while (current != NULL) {
        if (destroy_data != NULL)
            (*destroy_data)(current->data);
        temp = current->next;
        free(current);
        current = temp;
    }
}
