#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "data.h"
#include "declaracoes.h"

typedef struct Line PrivateLine;

struct Line {
    int id;
    char cor[20];
    double x1;
    double y1;
    double x2;
    double y2;
    int sl;
};
//aloca memoria suficiente para uma struct de dados
void* callocDataL(){
    PrivateLine* Line = calloc(1, sizeof(PrivateLine));
    return Line;
}
//bloco de get, retorna o valor de um dado expecifico da struct quando chamada indicado no nome da função
int getLineId(void* Sdata) {
    PrivateLine* Line = (PrivateLine*)Sdata;
    return Line->id;
} 
int getLineSl(void* Sdata) {
    PrivateLine* Line = (PrivateLine*)Sdata;
    return Line->sl;
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
void setLineId(void* Sdata, int Sid) {
    PrivateLine* Line = Sdata;
    Line->id = Sid;
}

void setLineCor(void* Sdata, char Scor[]) {
    PrivateLine* Line = Sdata;
    strcpy(Line->cor, Scor);
    //Line->cor = Scor;
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

void setLineSl(void* Sdata, int Ssl){
    PrivateLine* Line = Sdata;
    Line->sl = Ssl;
}