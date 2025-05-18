/*
** EPITECH PROJECT, 2024
** llist
** File description:
** Get length of a linked list.
*/

#include "llist.h"

int length_llist(linked_list_t *begin)
{
    int length = 0;
    linked_list_t *current = begin;

    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}
