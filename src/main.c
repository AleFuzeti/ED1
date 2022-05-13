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

void main (int argc, char** argv){
    void* listc = newList();
    void* listr = newList();
    void* listl = newList();
    void* listt = newList();

    void* paths = createAllPaths();
    readParam(argc, argv, paths);
    readGeo(listc, listr, listl, listt, paths);
    printOnSvg(listc,listr,listl,listt, getBsdGeoSvg(paths));

    if(getQryArq(paths)){
        FILE* qrysvg = fopen(getBsdGeoQrySvg(paths), "w");
        fprintf(qrysvg, "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");
        FILE* qrytxt = fopen(getBsdGeoQryTxt(paths), "w");

        printf("qrysvg: %s\n", getBsdGeoQrySvg(paths));
        printf("qrytxt: %s\n", getBsdGeoQryTxt(paths));

        void* listsele = newList();
        void* newform = callocDataSele();
        setSeleSl(newform,0);
        insertAfter(listsele, newform);

        readQry(listsele, listc, listr, listl, listt, paths, qrysvg, qrytxt);
        printOnOpen(listc, listr, listl, listt, qrysvg);
        fprintf(qrysvg, "</svg>\n");
        fclose(qrysvg);
        fclose(qrytxt);
    }
    
    freeList(listc);
    freeList(listt);
    freeList(listr);
    freeList(listl);

    freee(paths);
}