#ifndef DLIST_H
#define DLIST_H

#include "declaracoes.h"

List newList();
Node getNode(List list);
Node getFirst(List list);
Node getNext(List list, Node node);
Node getLast(List list);
Node getPrevious(List list, Node node);
Node insertAfter(List list, Data data);
Data getData(Node node);
void geoToList(List list, char* source);
void delNode(List list, Node node);
void freeList(List list);
void freeNode(Node node);

void* callocDataSele();
int getSeleSl(void* Sdata);
void setSeleSl(void* Sdata, int Ssl);

#endif