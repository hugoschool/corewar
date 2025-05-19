/*
** EPITECH PROJECT, 2024
** llist
** File description:
** Search for an element in a linked list.
*/

#include "llist.h"

void *search_in_list(linked_list_t *begin, void *input,
    bool(*compare)(void *, void *))
{
    linked_list_t *temp = begin;

    if (temp == NULL)
        return NULL;
    while (temp != NULL) {
        if ((*compare)(input, temp->data) == true)
            return temp->data;
        temp = temp->next;
    }
    return NULL;
}
