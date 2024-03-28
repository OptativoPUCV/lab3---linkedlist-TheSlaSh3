#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
/*Programe la función List* createList(), la cual retorna el puntero del tipo de dato List con sus valores inicializados en NULL.
  Recuerda reservar memoria al puntero usando malloc o calloc.*/
List * createList() 
{
     List * new = (List *)malloc(sizeof(List));
     assert(new != NULL);
     new->head = NULL;
     new->tail = NULL;
     new->current = NULL;
     return new;
}

/*Programe las funciones void * firstList(List * list) y void * nextList(List * list).

  La primera retorna el dato del primer nodo de la lista (head) y actualiza el current para que apunte a ese nodo.
  La segunda función retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.*/
void * firstList(List * list) 
{
    if(list->head == NULL)
    {
        return NULL;
    }
    list->current = list->head;
    return list->head->data;
}

void * nextList(List * list) 
{
    if(list->current == NULL)
    {
        return NULL;
    }
    if(list->current->next == NULL)
    {
        return NULL;
    }
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}