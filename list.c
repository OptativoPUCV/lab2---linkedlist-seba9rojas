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
//=============================================================
List* createList(){
  List* lista = (struct List*)malloc(sizeof(struct List));
  if (lista == NULL){
        exit(EXIT_FAILURE);
  }
  lista->head = NULL;
  return lista;
}
//=============================================================
void* firstList(List * list){
    if(list->head!=NULL){
      return list->head->data;
    }
    else{
      return NULL;
    }
}
//=============================================================
void* nextList(List * list){
    if(list->current!=NULL && list->current->next!=NULL){
      list->current=list->current->next;
      return list->current->data;
    }
    return NULL;     
}
//=============================================================
void* lastList(List * list) {
    if(list->tail!=NULL){
      list->current=list->tail;
      return list->current->data;
    }
    return NULL;
}
//=============================================================
void* prevList(List * list) {
    if(list->current!=NULL && list->current->prev!=NULL){
      list->current=list->current->prev;
      return list->current->data;
    }
    return NULL;
}
//=============================================================
void pushFront(List * list, void * data){
  Node* newNode=createNode(data);
  newNode->next=list->head;

  list->head=newNode;
  list->tail=newNode;
  
}
//=============================================================
void pushBack(List * list, void * data){
    list->current=list->tail;
    pushCurrent(list,data);
}
//=============================================================
void pushCurrent(List * list, void * data){
  if(list->current==NULL){
    return;
  }
  Node* newNode=createNode(data);

  newNode->next=list->current->next;
  newNode->prev=list->current;

  if(list->current->next!=NULL){
    list->current->next=newNode;
    list->current->prev=newNode;
  }
  else{
    list->tail=newNode;
  }
  list->current->next=newNode;

  
}
//=============================================================
void* popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}
//=============================================================
void* popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}
//=============================================================
void* popCurrent(List* list){
  if(list->current ==NULL){
      return NULL;
    }
    Node* currentNode =list->current;
    void* data =currentNode->data;

    if(currentNode->prev !=NULL){
      currentNode->prev->next = currentNode->next;
    } 
    else{
      list->head =currentNode->next;
    }
  
    if(currentNode->next !=NULL){
      currentNode->next->prev = currentNode->prev;
    } 
    else{
      list->tail =currentNode->prev;
    }
  
    if(currentNode->prev ==NULL && currentNode->next ==NULL){
      list->head =NULL;
      list->tail =NULL;
    }
  
    list->current =currentNode->next;
    return data;
}

//=============================================================
void cleanList(List* list){
    while (list->head != NULL){
      popFront(list);
    }
}