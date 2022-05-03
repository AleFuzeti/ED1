#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "data.h"
#include "declaracoes.h"

typedef struct Text PrivateText;

typedef struct Text {
    int id;
    char* corC;
    char* corP;
    double x;
    double y;
    char* a;
    char* text;
}Text;
//aloca memoria suficiente para uma struct de dados
void* callocDataT() {
    PrivateText* Text = calloc(1, sizeof(PrivateText));
    return Text;
}
//bloco de get, retorna o valor de um dado expecifico da struct quando chamada indicado no nome da função
int getTextId(void* Sdata) {
    PrivateText* Text = Sdata;
    return Text->id;
}

char* getTextCorC(void* Sdata) {
    PrivateText* Text = Sdata;
    return Text->corC;
}

char* getTextCorP(void* Sdata) {
    PrivateText* Text = Sdata;
    return Text->corP;
}

double getTextX(void* Sdata) {
    PrivateText* Text = Sdata;
    return Text->x;
}

double getTextY(void* Sdata) {
    PrivateText* Text = Sdata;
    return Text->y;
}

char* getTextA(void* Sdata) {
    PrivateText* Text = Sdata;
    return Text->a;
}

char* getTextText(void* Sdata) {
    PrivateText* Text = Sdata;
    return Text->text;
}

//bloco de set, quando chamada a função. um dado expecifico da struct recebe o valor passado no argumento
void setTextId(void* Sdata, int Sid) {
    PrivateText* Text = Sdata;
    Text->id, Sid;
}

void setTextCorC(void* Sdata, char* ScorC) {
    PrivateText* Text = Sdata;
    strcpy(Text->corC, ScorC);
}

void setTextCorP(void* Sdata, char* ScorP) {
    PrivateText* Text = Sdata;
    strcpy(Text->corP, ScorP);
}

void setTextX(void* Sdata, double Sx) {
    PrivateText* Text = Sdata;
    Text->x = Sx;
}

void setTextY(void* Sdata, double Sy) {
    PrivateText* Text = Sdata;
    Text->y = Sy;
}

void setTextA(void* Sdata, char* Sa) {
    PrivateText* Text = Sdata;
    Text->a = Sa;
}

void setTextText(void* Sdata, char* Stext) {
    PrivateText* Text = Sdata;
    Text->text = Stext;
}