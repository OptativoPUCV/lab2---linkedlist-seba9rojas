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
//=================================================================================
List* createList(){
  List* lista = (struct List*)malloc(sizeof(struct List));
  if (lista == NULL){
        exit(EXIT_FAILURE);
  }
  lista->head = NULL;
  return lista;
}
//=================================================================================
void* firstList(List * list){
    if(list->head!=NULL){
      return list->head->data;
    }
    else{
      return NULL;
    }
}
//=================================================================================
void* nextList(List * list){
    if(list->current!=NULL && list->current->next!=NULL){
      list->current=list->current->next;
      return list->current->data;
    }
    return NULL;     
}
//=================================================================================
void* lastList(List * list) {
    if(list->tail!=NULL){
      list->current=list->tail;
      return list->current->data;
    }
    return NULL;
}
//=================================================================================
void* prevList(List * list) {
    if(list->current!=NULL && list->current->prev!=NULL){
      list->current=list->current->prev;
      return list->current->data;
    }
    return NULL;
}
//=================================================================================
void pushFront(List * list, void * data){
  Node* newNode=createNode(data);
  newNode->next=list->head;

  list->head=newNode;
  list->tail=newNode;
  
}
//=================================================================================
void pushBack(List * list, void * data) {
    Node* newNode=createNode(data);
    newNode->next=list->tail;

    if(list->tail!=NULL){
      list->tail->next=newNode;
    }
    else{
      list->head=newNode;
    }
    list->head=newNode;
  

      
    list->current = list->tail;
    pushCurrent(list,data);
}
//=================================================================================
void pushCurrent(List * list, void * data){
  Node* newNode=createNode(data);
  newNode->next=list->current;
  if(list->current!=NULL && list->current->next!=NULL){
    list->current=newNode->current;
  }
  list->head=newNode;
  list->tail=newNode;
  
}
//=================================================================================
void* popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}
//=================================================================================
void* popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}
//=================================================================================
void* popCurrent(List* list){
    return NULL;
}

//=================================================================================
void cleanList(List* list){
    while (list->head != NULL){
      popFront(list);
    }
}