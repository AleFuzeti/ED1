#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "data.h"
#include "lista.h"
#include "getword.h"
#include "declaracoes.h"

typedef struct Node PrivateNode;
typedef struct List PrivateList;
//typedef struct Data PrivateData;


struct Node{

    Data data;
    PrivateNode* next;
    PrivateNode* prev;

};

struct List{

    PrivateNode* head;
    PrivateNode* tail;


};

List newList(){

    PrivateList* list = (PrivateList*) malloc(sizeof(PrivateList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

Node getNode(List list){

    PrivateList* privateList = (PrivateList*) list;

    PrivateNode* node = privateList->head;

    while(node != NULL){
     
        node = node->next;
    }

    return node;
}

Node getFirst(List list){

    PrivateList* privateList = (PrivateList*) list;

    return privateList->head;
}

Node getNext(List list, Node node){

    PrivateList* privateList = (PrivateList*) list;
    PrivateNode* privateNode = (PrivateNode*) node;
    if (privateNode->next == NULL) {
        return NULL;
    }

    return privateNode->next;
}

Node getLast(List list){

    PrivateList* privateList = (PrivateList*) list;

    return privateList->tail;
}

Node getPrevious(List list, Node node){

    PrivateList* privateList = (PrivateList*) list;
    PrivateNode* privateNode = (PrivateNode*) node;
    if(privateNode == privateList->head){
        return NULL;
    }
    return privateNode->prev;
}

Node insertAfter(List list, Data data){

    PrivateList* privateList = (PrivateList*) list;

    PrivateNode* newNode = calloc(1,sizeof(PrivateNode));

    newNode->data = data;

    newNode->next = NULL;
    newNode->prev = NULL;

    if(privateList->head == NULL){ //Lista vazia

        privateList->head = newNode;
        privateList->tail = newNode;

    } else{
        newNode->prev = privateList->tail;
        newNode->prev->next = newNode;
        privateList->tail = newNode;
    }

}

Data getData(Node node){

    PrivateNode* privateNode = (PrivateNode*) node;

    if(node == NULL) return NULL;

    return &privateNode->data;
}

void delNode(List list, Node node){

    PrivateList* privateList = (PrivateList*) list;

    PrivateNode* toFree = (PrivateNode*) node;
    PrivateNode* temp = privateList->head;

    if(toFree == privateList->head){

        privateList->head = privateList->head->next;

        freeNode(toFree);

        return;
    }

    while(temp->next != toFree){

        temp = (PrivateNode*) getNext(list, temp);
    }

    temp->next = toFree->next;

    if(temp->next != NULL) temp->next->prev = temp;

    freeNode(toFree);
}

void freeList(List list){

    PrivateList* privateList = (PrivateList*) list;

    PrivateNode* temp;

    while(privateList->head != NULL){

        temp = privateList->head;

        privateList->head = privateList->head->next;
        freeNode(temp);
    }

    free(privateList);
    privateList = NULL;
}

void freeNode(Node node){

    if(node == NULL) return;

    PrivateNode* toFree = (PrivateNode*) node;

    free(toFree->data);
    toFree->data = NULL;

    free(toFree);
    toFree = NULL;
}