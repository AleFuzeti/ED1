#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "declaracoes.h"
#include "lista.h"
#include "data.h"
#include "system.h"
#include "paths.h" 
#include "svg.h"
#include "queue.h" 


#define QUEUE_EMPTY INT_MIN

typedef struct{
    int *values;
    int head,tail,num,size;
} queue;

void* createQueue(int msize){
    queue *q;
    q->size = msize;
    q->values = malloc(sizeof(int) * q->size);
    q->num = 0;
    q->head = 0;
    q->tail = 0;
    return q;
}

bool queueVazia(void* Sq){
    queue* q = Sq;
    return (q->num == 0);
}
bool queueCheia(void* Sq){
    queue* q = Sq;
    return (q->num == q->size);
}
void deleteQueue(void* Sq){
    queue* q = Sq;
    free(q->values);
}

bool addQueue(void* Sq, int value){
    queue* q = Sq;
    if (queueCheia(q)){
        return false;
    }
    q->values[q->tail] = value;
    q->num++;
    q->tail = (q->tail + 1) % q->size;
 
    return true;
}

int removeQueue(void* Sq){
    int result;
    queue* q = Sq;
    if (queueVazia(q)){
        return QUEUE_EMPTY;
    }

    result = q->values[q->head];
    q->head = (q->head + 1) % q->size;
    q->num--;

    return result;
}


//queue q1
//startQueue(&q1, tamanho)