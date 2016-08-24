#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

list_t list_create()
{
    list_t list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void list_delete(list_t list)
{

}

void list_insert(list_t list, int index, int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;

    if (list->length == 0) {
        list->head = newnode;
        list->tail = newnode;
        list->length++;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    // else if (index == list->length) {
    //     newnode->next = NULL;
    //     newnode->prev = list->tail;
    //     list->tail = newnode;
    // }
    else {
        struct node* currentnode = list->head;
        for (int i = 0; i < index; i++) {
            currentnode = currentnode->next;
        }
        newnode->next = currentnode;
        newnode->prev = currentnode->prev;
        currentnode->prev = newnode;
    }

    list->length++;
}

void list_append(list_t list, int data)
{
    struct node* newnode = malloc(sizeof(struct node));
    if (list->length == 0)
        list->head = newnode;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = list->tail;
    list->tail = newnode;
    (list->length)++;
}

void list_print(list_t list)
{
    puts("hei");
    struct node* current = list->head;
    printf("%i", current->data);
    for (int i = 0; i < list->length; i++) {
        printf("%i ", current->data);
        current = current->next;
    }
    printf('\n');
    exit(0);
}

long list_sum(list_t list)
{
    long res;
    struct node* current = list->head;
    while (current != NULL) {
        res += current->data;
    }
    return res;
}

int list_get(list_t list, int index)
{

}

int list_extract(list_t list, int index)
{

}
