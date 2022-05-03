#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "data.h"
#include "lista.h"
#include "svg.h"
#include "declaracoes.h"
#include "getword.h"

void printOnSvg(void*listc, void* listr, void* listl, void* listt, char* file){
    //void* listc = getListCirc(lists);
    //void* listr = getListRect(lists);
    //void* listl = getListLine(lists);
    //void* listt = getListText(lists);

    int id;
    double x, x2, y, y2, r, w, h;
    char* corb;
    char* corp;
    char* cor;
    char* a;
    char* txto;

    void* form;
    void* node;

    FILE* svg = fopen(file, "w");

    if(svg == NULL){
        printf("erro ao abrir o .svg\n");
        exit(EXIT_FAILURE);
    }
    fprintf(svg, "<svg version=\"1.1\" xmlns\"http://www.w3.org/2000/svg\">\n");

    //circ
    for (node = getFirst(listc); node; node = getNext(listc, node)){
        form = getData(node);
        id = getCircId(form);
        x = getCircX(form);
        y = getCircY(form);
        r = getCircR(form);
        corb = getCircCorC(form);
        corp = getCircCorP(form);

        fprintf(svg, "<circle id=\"%d\" cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />\n", id, x, y, r, corb, corp);
    }

    //rect
    for (node = getFirst(listr); node; node = getNext(listr, node)){
        form = getData(node);
        id = getRectId(form);
        x = getRectX(form);
        y = getRectY(form);
        w = getRectW(form);
        h = getRectH(form);
        corb = getRectCorC(form);
        corp = getRectCorP(form);

        fprintf(svg, "<rectangle id=\"%d\" x=\"%lf\" y=\"%lf\" w=\"%lf\" h=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />\n", id, x, y, w, h, corb, corp);
    }

    for (node = getFirst(listt); node; node = getNext(listt, node)){
        form = getData(node);
        id = getTextId(form);
        x = getTextX(form);
        y = getTextY(form);
        corb = getTextCorC(form);
        corp = getTextCorP(form);
        txto = getTextText(form);
        char* a = getTextA(form);
        char* aux;
        if (a[0] == 'i'){
            strcpy(aux,"start");
        }
        else if (a[0] == 'm'){
            strcpy(aux,"middle");
        }
        else if (a[0] == 'f'){
            strcpy(aux,"end");
        }

        fprintf(svg, "<text id=\"%d\" x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" text-anchor=\"%s\">%s</text>\n", id, x, y, corb, corp, aux, txto);
    }

    for (node = getFirst(listl); node; node = getNext(listc, node)){
        form = getData(node);
        id = getLineId(form);
        x = getLineX1(form);
        y = getLineY1(form);
        x2 = getLineX2(form);
        y2 = getLineY2(form);
        cor = getLineCor(form);

        fprintf(svg, "<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"1\" />\n", id, x, y, x2, y2, cor);
    }
    fprintf(svg, "</svg>\n");
    fclose(svg);
}

void printOnOpen(void*listc, void*listr, void*listl, void*listt, FILE* qrysvg){
    return;
};