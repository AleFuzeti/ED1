#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "data.h"
#include "declaracoes.h"

typedef struct Line PrivateLine;

typedef struct Line {
    char* id;
    char* cor;
    double x1;
    double y1;
    double x2;
    double y2;

};


//aloca memoria suficiente para uma struct de dados
void* callocDataL() {
    PrivateLine* Line = calloc(1, sizeof(PrivateLine));
    return Line;
}
//bloco de get, retorna o valor de um dado expecifico da struct quando chamada indicado no nome da função
char* getLineId(void* Sdata) {
    PrivateLine* Line = Sdata;
    return Line->id;
}

char* getLineCor(void* Sdata) {
    PrivateLine* Line = Sdata;
    return Line->cor;
}

double getLineX1(void* Sdata) {
    PrivateLine* Line = Sdata;
    return Line->x1;
}

double getLineY1(void* Sdata) {
    PrivateLine* Line = Sdata;
    return Line->y1;
}

double getLineX2(void* Sdata) {
    PrivateLine* Line = Sdata;
    return Line->x2;
}

double getLineY2(void* Sdata) {
    PrivateLine* Line = Sdata;
    return Line->y2;
}

//bloco de set, quando chamada a função. um dado expecifico da struct recebe o valor passado no argumento
void setLineId(void* Sdata, char* Sid) {
    PrivateLine* Line = Sdata;
    strcpy(Line->id, Sid);
}

void setLineCor(void* Sdata, char* Scor) {
    PrivateLine* Line = Sdata;
    strcpy(Line->cor, Scor);
}

void setLineX1(void* Sdata, double Sx1) {
    PrivateLine* Line = Sdata;
    Line->x1 = Sx1;
}

void setLineY1(void* Sdata, double Sy1) {
    PrivateLine* Line = Sdata;
    Line->y1 = Sy1;
}

void setLineX2(void* Sdata, double Sx2) {
    PrivateLine* Line = Sdata;
    Line->x2 = Sx2;
}

void setLineY2(void* Sdata, double Sy2) {
    PrivateLine* Line = Sdata;
    Line->y2 = Sy2;
}
