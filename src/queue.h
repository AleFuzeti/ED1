#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void* createQueue(int msize);
bool queueVazia(void* Sq);
bool queueCheia(void* Sq);
void deleteQueue(void* Sq);
bool addQueue(void* Sq, int value);
int removeQueue(void* Sq);
