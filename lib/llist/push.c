/*
** EPITECH PROJECT, 2024
** llist
** File description:
** Push to linked list
*/

#include "llist.h"

void push_to_end_list(linked_list_t **begin, void *data)
{
    linked_list_t *current = *begin;
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->data = data;
    new->next = NULL;
    if (current == NULL)
        *begin = new;
    else {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
}

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *current = malloc(sizeof(linked_list_t));

    current->data = data;
    current->next = *begin;
    *begin = current;
}
