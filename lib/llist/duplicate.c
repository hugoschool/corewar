/*
** EPITECH PROJECT, 2025
** llist
** File description:
** Duplicate linked list.
*/

#include "llist.h"

linked_list_t *duplicate_llist(linked_list_t *begin,
    void *(*duplicate_data)(void *))
{
    linked_list_t *dupe = NULL;
    linked_list_t *current = begin;

    while (current != NULL) {
        push_to_end_list(&dupe, (*duplicate_data)(current->data));
        current = current->next;
    }
    return dupe;
}
