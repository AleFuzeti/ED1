#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "data.h"
#include "declaracoes.h"

typedef struct Rect PrivateRect; 

struct Rect{

    int id;
    char corC[20];
    char corP[20];
    double x;
    double y;
    double w;
    double h;
    int sl;
};

//aloca memoria suficiente para uma struct de dados
void* callocDataR() {
    PrivateRect* Rect = calloc(2, sizeof(PrivateRect));
    return Rect;
}
//bloco de get, retorna o valor de um dado expecifico da struct quando chamada indicado no nome da função
int getRectId(void* Sdata) {
    PrivateRect* Rect = Sdata;
    return Rect->id;
}
int getRectSl(void* Sdata) {
    PrivateRect* Rect = Sdata;
    return Rect->sl;
}
char* getRectCorC(void* Sdata) {
    PrivateRect* Rect = Sdata;
    return Rect->corC;
}

char* getRectCorP(void* Sdata) {
    PrivateRect* Rect = Sdata;
    return Rect->corP;
}

double getRectX(void* Sdata) {

    PrivateRect* Rect = Sdata;
    return Rect->x;
}

double getRectY(void* Sdata) {
    PrivateRect* Rect = Sdata;
    return Rect->y;
}

double getRectW(void* Sdata) {
    PrivateRect* Rect = Sdata;
    return Rect->w;
}

double getRectH(void* Sdata) {
    PrivateRect* Rect = Sdata;
    return Rect->h;
}

//bloco de set, quando chamada a função. um dado expecifico da struct recebe o valor passado no argumento
void setRectId(void* Sdata, int Sid) {
    PrivateRect* Rect = Sdata;
    Rect->id= Sid;
}

void setRectCorC(void* Sdata, char ScorC[]) {
    PrivateRect* Rect = Sdata;
    //Rect->corC= ScorC;
    strcpy(Rect->corC, ScorC);
}

void setRectCorP(void* Sdata, char ScorP[]) {
    PrivateRect* Rect = Sdata;
    //Rect->corP= ScorP;
    strcpy(Rect->corP, ScorP);

}

void setRectX(void* Sdata, double Sx) {
    PrivateRect* Rect = Sdata;
    Rect->x = Sx;

}

void setRectY(void* Sdata, double Sy) {
    PrivateRect* Rect = Sdata;
    Rect->y = Sy;
}

void setRectW(void* Sdata, double Sw) {
    PrivateRect* Rect = Sdata;
    Rect->w = Sw;
}

void setRectH(void* Sdata, double Sh) {
    PrivateRect* Rect = Sdata;
    Rect->h = Sh;
}

void setRectSl(void* Sdata, int Ssl){
    PrivateRect* Rect = Sdata;
    Rect->sl = Ssl;
}