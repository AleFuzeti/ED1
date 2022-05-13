#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "declaracoes.h"
#include "lista.h"
#include "data.h"
#include "system.h"
#include "paths.h" 
#include "svg.h"
#include "qry.h"

struct Sel {
    int id;
    double x1;
    double y1;
    double x2;
    double y2;
    char* tipo;
};

int inp(void* listc, void* listr, void* listl, void* listt, void* queue, FILE* qry, FILE* qrysvg, FILE* qrytxt){}
int rmp(void* queue, FILE* qry, FILE* qrysvg, FILE* qrytxt){}
int pol(void* queue, FILE* qry, FILE* qrysvg, FILE* qrytxt){}
int clp(void* queue, FILE* qry, FILE* qrysvg, FILE* qrytxt){}

int sel(void* listsele, void* listc, void* listr, void* listl, void* listt, FILE* qry,FILE* qrysvg,FILE* qrytxt){
    int id, auxsele;
    int auxSl = 1;
    double x, x2, y, y2, r, w, h, selx, sely, selw, selh, auxX, auxY;

    void* form;
    void* node;
    //desselecionar
    for (node = getFirst(listr); node; node = getNext(listr, node)){
        form = getData(node);        
        setRectSl(form,0);}
    for (node = getFirst(listc); node; node = getNext(listc, node)){
        form = getData(node);
        setCircSl(form,0);}
    for (node = getFirst(listl); node; node = getNext(listl, node)){
        form = getData(node);        
        setLineSl(form,0);}
    for (node = getFirst(listt); node; node = getNext(listt, node)){
        form = getData(node);
        setTextSl(form,0);}
    //desselecionado

    form = getFirst(listsele);
    setSeleSl(form, 1);
        


    fscanf(qry, "%lf %lf %lf %lf", &selx, &sely, &selw, &selh);

    for (node = getFirst(listr); node; node = getNext(listr, node)){
        form = getData(node);        
        id = getRectId(form);
        x = getRectX(form);
        y = getRectY(form);
        w = getRectW(form);
        h = getRectH(form);

    if  (x >= selx && x + w <= selx + selw && y >= sely && y + h <= sely + selh){
        setRectSl(form,auxSl);

        form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl > auxsele){
            setSeleSl(form, auxSl);
        }
        auxSl = auxSl+1;
        fprintf(qrysvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"1.75\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" />\n", x, y);
        fprintf(qrytxt, "sel rect id=%d\n", id);
    }
    }
    
    for (node = getFirst(listc); node; node = getNext(listc, node)){
        form = getData(node);
        id = getCircId(form);
        x = getCircX(form);
        y = getCircY(form);
        r = getCircR(form);
    if  (x - r >= selx && x + r <= selx + selw && y + r >= sely && y - r <= sely + selh){
        setCircSl(form,auxSl);

        form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl > auxsele){
            setSeleSl(form, auxSl);
        }
        auxSl = auxSl+1; 
        fprintf(qrysvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"1,75\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" />\n", x, y);
        fprintf(qrytxt, "sel circ id=%d\n", id);
    }
    }
    

    for (node = getFirst(listl); node; node = getNext(listl, node)){
        form = getData(node);
        id = getLineId(form);
        x = getLineX1(form);
        y = getLineY1(form);
        x2 = getLineX2(form);
        y2 = getLineY2(form);

    if  (x >= selx && x <= selx + selw && x2 >= selx && x2 <= selx + selw && y >= sely && y <= sely + selh && y2 >= sely && y2 <= sely + selh){
        if (x<x2){
            auxX = x;
            auxY = y;
        } else if(x2<x){
            auxX = x2;
            auxY = y2;
        } else if(y<y2){
            auxX = x;
            auxY = y;
        } else{
            auxX = x2;
            auxY = y2;
        }
        setLineSl(form,auxSl);

        form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl > auxsele){
            setSeleSl(form, auxSl);
        }
        auxSl = auxSl+1; 
        fprintf(qrysvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"1,75\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" />\n", auxX, auxY);
        fprintf(qrytxt, "sel line id=%d\n", id);
        fflush(qrysvg);    
    } 
    }

    for (node = getFirst(listt); node; node = getNext(listt, node)){
        form = getData(node);
        id = getTextId(form);
        x = getTextX(form);
        y = getTextY(form);

    if ( x>= selx && y >= sely){

        setTextSl(form,auxSl);

        form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl > auxsele){
            setSeleSl(form, auxSl);
        }
        auxSl = auxSl+1; 
        fprintf(qrysvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"1,75\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" />\n", x, y);
        fprintf(qrytxt, "sel text id=%d", id);
        fflush(qrysvg);            
    }    
    }

    fprintf(qrysvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"red\" stroke-width=\"1\" fill-opacity=\"0.0\" fill=\"null\" />\n", selx, sely, selw, selh);
}

int selPlus(void* listsele, void* listc, void* listr, void* listl, void* listt, FILE* qry, FILE* qrysvg, FILE* qrytxt){
    int id,auxsele;
    int auxSl = 1;
    double x, x2, y, y2, r, w, h, selx, sely, selw, selh, auxX, auxY;

    void* form;
    void* node;

    form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl < auxsele){
            auxSl = auxsele;
        } 
     
    fscanf(qry, "%lf %lf %lf %lf", &selx, &sely, &selw, &selh);

    for (node = getFirst(listr); node; node = getNext(listr, node)){
        form = getData(node);        
        id = getRectId(form);
        x = getRectX(form);
        y = getRectY(form);
        w = getRectW(form);
        h = getRectH(form);

    if  (x >= selx && x + w <= selx + selw && y >= sely && y + h <= sely + selh){
        setRectSl(form,auxSl);
        
        form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl > auxsele){

            setSeleSl(form, auxSl);
        }
        auxSl = auxSl+1; 
        fprintf(qrysvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"1.75\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" />\n", x, y);
        fprintf(qrytxt, "sel+ rect id=%d\n", id);
    }
    }
    
    for (node = getFirst(listc); node; node = getNext(listc, node)){
        form = getData(node);
        id = getCircId(form);
        x = getCircX(form);
        y = getCircY(form);
        r = getCircR(form);
    if  (x - r >= selx && x + r <= selx + selw && y + r >= sely && y - r <= sely + selh){
        setCircSl(form,auxSl);

        form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl > auxsele){
            setSeleSl(form, auxSl);
        }
        auxSl = auxSl+1; 
        fprintf(qrysvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"1,75\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" />\n", x, y);
        fprintf(qrytxt, "sel+ circ id=%d\n", id);
    }
    }
    
    for (node = getFirst(listl); node; node = getNext(listl, node)){
        form = getData(node);
        id = getLineId(form);
        x = getLineX1(form);
        y = getLineY1(form);
        x2 = getLineX2(form);
        y2 = getLineY2(form);

    if  (x >= selx && x <= selx + selw && x2 >= selx && x2 <= selx + selw && y >= sely && y <= sely + selh && y2 >= sely && y2 <= sely + selh){
        if (x<x2){
            auxX = x;
            auxY = y;
        } else if(x2<x){
            auxX = x2;
            auxY = y2;
        } else if(y<y2){
            auxX = x;
            auxY = y;
        } else{
            auxX = x2;
            auxY = y2;
        }
        setLineSl(form,auxSl);

        form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl > auxsele){
            setSeleSl(form, auxSl);
        }
        auxSl = auxSl+1; 
        fprintf(qrysvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"1,75\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" />\n", auxX, auxY);
        fprintf(qrytxt, "sel+ line id=%d\n", id);
        fflush(qrysvg);    
    } 
    }

    for (node = getFirst(listt); node; node = getNext(listt, node)){
        form = getData(node);
        id = getTextId(form);
        x = getTextX(form);
        y = getTextY(form);

    if ( x>= selx && y >= sely){

        setTextSl(form,auxSl);

        form = getFirst(listsele);
        auxsele = getSeleSl(form);
        if (auxSl > auxsele){
            setSeleSl(form, auxSl);
        }
        auxSl = auxSl+1; 
        fprintf(qrysvg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"1,75\" stroke=\"red\" stroke-width=\"1\" fill=\"red\" />\n", x, y);
        fprintf(qrytxt, "sel+ text id=%d", id);
        fflush(qrysvg);            
    }    
    }

    fprintf(qrysvg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"red\" stroke-width=\"1\" fill-opacity=\"0.0\" fill=\"null\" />\n", selx, sely, selw, selh);
}

int dels(void* listsele,void* listc, void* listr, void* listl, void* listt, FILE* qry, FILE* qrysvg, FILE* qrytxt){
    int auxSl,id;
    void* form;
    void* node;

    for (node = getFirst(listc); node; node = getNext(listc, node)){
        form = getData(node);
        auxSl = getCircSl(form);
        id = getCircId(form);
        form = node;
        if (auxSl > 0){
            delNode(listc,form);
            fprintf(qrytxt, "dels circ id=%d\n", id);

        }
    }
    for (node = getFirst(listr); node; node = getNext(listr, node)){
        form = getData(node);
        auxSl = getRectSl(form);
        id = getRectId(form);
        form = node;
        if (auxSl > 0){
            delNode(listr,form);
            fprintf(qrytxt, "dels rect id=%d\n", id);
        }
    }
    for (node = getFirst(listt); node; node = getNext(listt, node)){
        form = getData(node);
        auxSl = getTextSl(form);
        id = getTextId(form);
        form = node;
        if (auxSl > 0){
            delNode(listr,form);
            fprintf(qrytxt, "dels text id=%d\n", id);
        }
    }
    for (node = getFirst(listl); node; node = getNext(listl, node)){
        form = getData(node);
        auxSl = getLineSl(form);
        id = getLineId(form);
        form = node;
        if (auxSl > 0){
            delNode(listr,form);
            fprintf(qrytxt, "dels line id=%d\n", id);
        }
    }

    form = getFirst(listsele);
    setSeleSl(form, 0);
        
}

int dps(void* listc, void* listr, void* listl, void* listt, FILE* qry, FILE* qrysvg, FILE* qrytxt){
    int i,auxSl, auxid;
    double  x, y, r, w, h;
    double dx, dy;
    char corp[20];
    char corb[20];
    void* form;
    void* node;
    void* newform;
    fscanf(qry, "%d %lf %lf %s %s", &i, &dx, &dy, &corb, &corp);
    
    for (node = getFirst(listc); node; node = getNext(listc, node)){
        form = getData(node);
        auxSl = getCircSl(form);
        //auxid = getCircId(form);
        x = getCircX(form);
        y = getCircY(form);
        r = getCircR(form);

        if (auxSl > 0){
            newform = callocDataC();
            setCircId(newform,i);
            setCircX(newform, dx + x);
            setCircY(newform, dy + y);
            setCircR(newform, r);
            setCircCorC(newform, corb);
            setCircCorP(newform, corp);
            insertAfter(listc, newform);
            //fprintf(qrytxt, "dps circ id=%d\n", i);
            i = i+1;

        }
    }
    for (node = getFirst(listr); node; node = getNext(listr, node)){
        form = getData(node);
        auxSl = getRectSl(form);
        //id = getRectId(form);
        x = getRectX(form);
        y = getRectY(form);
        w = getRectW(form);
        h = getRectH(form);
        
        if (auxSl > 0){
            newform = callocDataR();
            setRectId(newform,i);
            setRectX(newform, dx + x);
            setRectY(newform, dy + y);
            setRectW(newform, w);
            setRectH(newform, h);
            setRectCorC(newform, corb);
            setRectCorP(newform, corp);
            insertAfter(listr, newform);
            //fprintf(qrytxt, "dps rect id=%d\n", i);
            i = i+1;

        }
    }
    for (node = getFirst(listt); node; node = getNext(listt, node)){
        form = getData(node);
        auxSl = getTextSl(form);

        //id = getTextId(form);
        x = getTextX(form);
        y = getTextY(form);
        
        if (auxSl > 0){
            newform = callocDataR();
            setTextId(newform,i);
            setTextX(newform, dx + x);
            setTextY(newform, dy + y);
            setTextCorC(newform, corb);
            setTextCorP(newform, corp);
            insertAfter(listt, newform);
            //fprintf(qrytxt, "dps Text id=%d\n", i);
            i = i+1;
        }
    }
    for (node = getFirst(listl); node; node = getNext(listl, node)){
        form = getData(node);
        auxSl = getLineSl(form);
        //id = getLineId(form);
        x = getLineX1(form);
        h = getLineX2(form);
        y = getLineY1(form);
        w = getLineY2(form);
        if (auxSl > 0){
            newform = callocDataR();
            setRectId(newform,i);
            setLineX1(newform, dx + x);
            setLineX2(newform, dx + h);
            setLineY1(newform, dy + y);
            setLineY2(newform, dy + w);
            setLineCor(newform, corp);
            insertAfter(listl, newform);
            //fprintf(qrytxt, "dps line id=%d\n", i);
            i = i+1;
        }
    }

}

int ups(void* listsele,void* listc, void* listr, void* listl, void* listt, FILE* qry, FILE* qrysvg, FILE* qrytxt){
    int auxSl, auxid, n, auxsele, auxn;
    int i = 1;
    double  x, y, r, w, h;
    double dx, dy;
    char corp[20];
    char corb[20];
    void* form;
    void* node;
    void* newform;

    fscanf(qry, "%s %s %lf %lf %d",&corb, &corp, &dx, &dy, &n );
    

    form = getFirst(listsele);
    auxsele = getSeleSl(form);
    auxn = n + auxsele;  


    for (node = getFirst(listc); node; node = getNext(listc, node)){
        form = getData(node);
        auxSl = getCircSl(form);
        auxid = getCircId(form);
        x = getCircX(form);
        y = getCircY(form);
        r = getCircR(form);

        if (auxSl > auxn){
            setCircX(form, dx + x);
            setCircY(form, dy + y*i);
            setCircCorC(form, corb);
            setCircCorP(form, corp);
            //fprintf(qrytxt, "ups circ id=%d\n", auxid);
            i = i+1;

        }
    }
    for (node = getFirst(listr); node; node = getNext(listr, node)){
        form = getData(node);
        auxSl = getRectSl(form);
        auxid = getRectId(form);
        x = getRectX(form);
        y = getRectY(form);
        w = getRectW(form);
        h = getRectH(form);
        if (auxSl > auxn){
       // printf("\ncerto:%d, maior que: %d",auxSl,auxn);
       // printf("\ni:%d",i);
            setRectX(form, dx + x);
            setRectY(form, dy + y*i);
            setRectCorC(form, corb);
            setRectCorP(form, corp);
            //fprintf(qrytxt, "ups rect id=%d\n", auxid);
            i = i+1;

        }
    }
    for (node = getFirst(listt); node; node = getNext(listt, node)){
        form = getData(node);
        auxSl = getTextSl(form);
        auxid = getTextId(form);
        x = getTextX(form);
        y = getTextY(form);
        
        if (auxSl > auxn){
            setTextX(form, dx + x);
            setTextY(form, dy + y*i);
            setTextCorC(form, corb);
            setTextCorP(form, corp);
            //fprintf(qrytxt, "ups text id=%d\n", auxid);
            i = i+1;
        }
    }
    for (node = getFirst(listl); node; node = getNext(listl, node)){
        form = getData(node);
        auxSl = getLineSl(form);
        auxid = getLineId(form);
        x = getLineX1(form);
        h = getLineX2(form);
        y = getLineY1(form);
        w = getLineY2(form);
        if (auxSl > auxn){
            setLineX1(form, dx + x);
            setLineX2(form, dx + h);
            setLineY1(form, dy + y*i);
            setLineY2(form, dy + w*i);
            setLineCor(form, corp);
            //fprintf(qrytxt, "ups line id=%d\n", auxid);
            i = i+1;
        }
    }

}