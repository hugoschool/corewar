/*
** EPITECH PROJECT, 2024
** llist
** File description:
** Display linked list
*/

#include "llist.h"

void display_list(linked_list_t *begin, void(*disp_fct)())
{
    linked_list_t *current = begin;

    while (current != NULL) {
        (*disp_fct)(current->data);
        current = current->next;
    }
}
