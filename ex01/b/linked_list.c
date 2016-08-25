#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

list_t list_create()
{
    list_t list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

void list_delete(list_t list)
{
    free(list);
}

struct node* list_find(list_t list, int index)
{
    struct node* iter = list->head;
    for (int i = 0; i < index; i++)
        iter = iter->next;
    return iter;
}

void list_insert(list_t list, int index, int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    struct node* iter = list_find(list, index);
    newnode->prev = iter->prev;
    newnode->next = iter;
    newnode->data = data;
    iter->prev->next = newnode;
    iter->prev = newnode;
    list->length++;
}

void list_append(list_t list, int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    if (list->length == 0) {
        list->head = newnode;
        list->tail = newnode;
        newnode->prev = NULL;
    }
    else {
        list->tail->next = newnode;
        newnode->prev = list->tail;
        list->tail = newnode;
    }
    newnode->next = NULL;
    newnode->data = data;
    (list->length)++;
}

void list_print(list_t list)
{
    struct node* iter = list->head;
    while (iter != NULL) {
        printf("%i ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}

long list_sum(list_t list)
{
    long res = 0;
    struct node* iter = list->head;
    while (iter != NULL) {
        res += iter->data;
        iter = iter->next;
    }
    return res;
}

int list_get(list_t list, int index)
{
    return (list_find(list, index))->data;
}

int list_extract(list_t list, int index)
{
    struct node* iter = list_find(list, index);
    int data = iter->data;

    if (list->length > 1) {
        iter->next->prev = iter->prev;

        if (index == 0)
            list->head = iter->next;
        else
            iter->prev->next = iter->next;

        if (list->length == 2)
            list->tail = list->head;
    }
    else {
        list->head = NULL;
        list->tail = NULL;
    }

    free(iter);
    list->length--;
    return data;
}
