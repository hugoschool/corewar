/*
** EPITECH PROJECT, 2025
** llist
** File description:
** Search and replace and item in a linked list.
*/

#include "llist.h"

bool replace_in_list(linked_list_t *begin, void *input,
    bool(*compare)(void *, void *), void *new_data)
{
    linked_list_t *temp = begin;

    while (temp != NULL) {
        if ((*compare)(input, temp->data) == true) {
            temp->data = new_data;
            return true;
        }
        temp = temp->next;
    }
    return false;
}
