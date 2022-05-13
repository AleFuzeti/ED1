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
int getCircId(void* Sdata);
char* getCircCorC(void* Sdata);
char* getCircCorP(void* Sdata);
double getCircX(void* Sdata);
double getCircY(void* Sdata);
double getCircR(void* Sdata);
int getCircSl(void* Sdata);

//retangulo
int getRectId(void* Sdata);
char* getRectCorC(void* Sdata);
char* getRectCorP(void* Sdata);
double getRectX(void* Sdata);
double getRectY(void* Sdata);
double getRectW(void* Sdata);
double getRectH(void* Sdata);
int getRectSl(void* Sdata);

//linha
int getLineId(void* Sdata);
char* getLineCor(void* Sdata);
double getLineX1(void* Sdata);
double getLineY1(void* Sdata);
double getLineX2(void* Sdata);
double getLineY2(void* Sdata);
int getLineSl(void* Sdata);

//texto
int getTextId(void* Sdata);
char* getTextCorC(void* Sdata);
char* getTextCorP(void* Sdata);
double getTextX(void* Sdata);
double getTextY(void* Sdata);
char getTextA(void* Sdata);
char* getTextText(void* Sdata);
int getTextSl(void* Sdata);

/**/

//bloco de set

//circ
void setCircId(void* Sdata, int Sid);
void setCircCorC(void* Sdata, char ScorC[]);
void setCircCorP(void* Sdata, char ScorP[]);
void setCircX(void* Sdata, double Sx);
void setCircY(void* Sdata, double Sy);
void setCircR(void* Sdata, double Sr);
void setCircSl(void* Sdata, int Ssl);

//line
void setLineId(void* Sdata, int Sid);
void setLineCor(void* Sdata, char Scor[]);
void setLineX1(void* Sdata, double Sx1);
void setLineY1(void* Sdata, double Sy1);
void setLineX2(void* Sdata, double Sx2);
void setLineY2(void* Sdata, double Sy2);
void setLineSl(void* Sdata, int Ssl);

//rect
void setRectId(void* Sdata, int Sid);
void setRectCorC(void* Sdata, char ScorC[]);
void setRectCorP(void* Sdata, char ScorP[]);
void setRectX(void* Sdata, double Sx);
void setRectY(void* Sdata, double Sy);
void setRectW(void* Sdata, double Sw);
void setRectH(void* Sdata, double Sh);
void setRectSl(void* Sdata, int Ssl);
//text
void setTextId(void* Sdata, int Sid);
void setTextCorC(void* Sdata, char ScorC[]);
void setTextCorP(void* Sdata, char ScorP[]);
void setTextX(void* Sdata, double Sx);
void setTextY(void* Sdata, double Sy);
void setTextA(void* Sdata, char Sa);
void setTextText(void* Sdata, char Stext[]);
void setTextSl(void* Sdata, int Ssl);


#endif