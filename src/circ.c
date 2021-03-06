#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "data.h"
#include "declaracoes.h"

typedef struct Circ PrivateCirc;

struct Circ{
    int id;
    char corC[20];
    char corP[20];
    double x;
    double y;
    double r;
    int sl;
};


//aloca memoria suficiente para uma struct de Dados
void* callocDataC() {
    PrivateCirc* Circ = calloc(2, sizeof(PrivateCirc));
    return Circ;
}
//bloco de get, retorna o valor de um dado expecifico da struct quando chamada indicado no nome da função
int getCircId(void* Sdata) {
    PrivateCirc* Circ = Sdata;
    return Circ->id;
}
int getCircSl(void* Sdata) {
    PrivateCirc* Circ = Sdata;
    return Circ->sl;
}

char* getCircCorC(void* Sdata) {
    PrivateCirc* Circ = Sdata;
    return Circ->corC;
}

char* getCircCorP(void* Sdata) {
    PrivateCirc* Circ = Sdata;
    return Circ->corP;
}


double getCircX(void* Sdata) {
    PrivateCirc* Circ = Sdata;
    return Circ->x;
}

double getCircY(void* Sdata) {
    PrivateCirc* Circ = Sdata;
    return Circ->y;
}

double getCircR(void* Sdata) {
    PrivateCirc* Circ = Sdata;
    return Circ->r;
} 

//bloco de set, quando chamada a função. um dado expecifico da struct recebe o valor passado no argumento
void setCircId(void* Sdata, int Sid) {
    PrivateCirc* Circ = Sdata;
    Circ->id= Sid;
}

void setCircCorC(void* Sdata, char ScorC[]) {
    PrivateCirc* Circ = Sdata;
    //Circ->corC= ScorC;
    strcpy(Circ->corC, ScorC);

}

void setCircCorP(void* Sdata, char ScorP[]) {
    PrivateCirc* Circ = Sdata;
    //Circ->corP= ScorP;
    strcpy(Circ->corP, ScorP);

}


void setCircX(void* Sdata, double Sx) {
    PrivateCirc* Circ = Sdata;
    Circ->x = Sx;
}

void setCircY(void* Sdata, double Sy) {
    PrivateCirc* Circ = Sdata;
    Circ->y = Sy;
}

void setCircR(void* Sdata, double Sr) {
    PrivateCirc* Circ = Sdata;
    Circ->r = Sr;
}

void setCircSl(void* Sdata, int Ssl) {
    PrivateCirc* Circ = Sdata;
    Circ->sl = Ssl;
}