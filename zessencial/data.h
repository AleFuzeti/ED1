#ifndef DATA_H
#define DATA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//aloca memoria suficiente para uma struct de dados
void* callocDataC();
void* callocDataR();
void* callocDataT();
void* callocDataL();


//bloco de get, retorna o valor de um dado expecifico da struct quando chamada
//indicado no nome da função

//circulo
char* getCircId(void* Sdata);
char* getCircCorC(void* Sdata);
char* getCircCorP(void* Sdata);
double getCircX(void* Sdata);
double getCircY(void* Sdata);
double getCircR(void* Sdata);
//retangulo
char* getRectId(void* Sdata);
char* getRectCorC(void* Sdata);
char* getRectCorP(void* Sdata);
double getRectX(void* Sdata);
double getRectY(void* Sdata);
double getRectW(void* Sdata);
double getRectH(void* Sdata);
//linha
char* getLineId(void* Sdata);
char* getLineCor(void* Sdata);
double getLineX1(void* Sdata);
double getLineY1(void* Sdata);
double getLineX2(void* Sdata);
double getLineY2(void* Sdata);
//texto
char* getTextId(void* Sdata);
char* getTextCorC(void* Sdata);
char* getTextCorP(void* Sdata);
double getTextX(void* Sdata);
double getTextY(void* Sdata);
char* getTextA(void* Sdata);
/**/

//bloco de set

//circ
void setCircId(void* Sdata, char* Sid);
void setCircCorC(void* Sdata, char* ScorC);
void setCircCorP(void* Sdata, char* ScorP);
void setCircX(void* Sdata, double Sx);
void setCircY(void* Sdata, double Sy);
void setCircY(void* Sdata, double Sr);
//line
void setLineId(void* Sdata, char* Sid);
void setLineCor(void* Sdata, char* Scor);
void setLineX1(void* Sdata, double Sx1);
void setLineY1(void* Sdata, double Sy1);
void setLineX2(void* Sdata, double Sx2);
void setLineY2(void* Sdata, double Sy2);
//rect
void setRectId(void* Sdata, char* Sid);
void setRectCorC(void* Sdata, char* ScorC);
void setRectCorP(void* Sdata, char* ScorP);
void setRectX(void* Sdata, double Sx);
void setRectY(void* Sdata, double Sy);
void setRectW(void* Sdata, double Sw);
void setRectH(void* Sdata, double Sh);
//text
void setTextId(void* Sdata, char* Sid);
void setTextCorC(void* Sdata, char* ScorC);
void setTextCorP(void* Sdata, char* ScorP);
void setTextX(void* Sdata, double Sx);
void setTextY(void* Sdata, double Sy);
void setTextA(void* Sdata, char* Sa);
#endif