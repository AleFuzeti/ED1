#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "declaracoes.h"
#include "lista.h"
#include "data.h"
#include "system.h"
#include "paths.h" 
#include "qry.h" 
#include "queue.h" 
#include "svg.h" 
//#include "txt.h"

void readParam(int argc, char** argv, void* paths) {
    bool readbed = false; 
    bool readgeo = false; 
    bool readbsd = false; 
    bool readqry = false; 

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-e")) //path -  
        { i++;
         char* bed = calloc(strlen(argv[i]) + 1, sizeof(char));
            strcpy(bed, argv[i]); 
            readbed = true; 
            bed = prepareDir(bed); 
            setBed(paths, bed); 
        } 
        else if (!strcmp(argv[i], "-f")) //.geo  
        { i++;
            char* geofull = calloc(strlen(argv[i]) + 1, sizeof(char));
            char* geoarq = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            char* geoname = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            //setGeoFull(paths, argv[i]);
            strcpy(geofull, argv[i]); 
            readgeo = true; 
            //bool lais = true;
           // prepareDoc(paths, geoname, lais); 
            prepareDoc(geofull, geoname);
            strcpy(geoarq, geoname); 
            strcat(geoarq, ".geo"); 
            setGeoArq(paths, geoarq); 
            setGeoName(paths, geoname); 
            //free(geofull);
        }
        else if (!strcmp(argv[i], "-o")) //path - diretorio base de saida (BSD) 
            {i++;
            char* bsd = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            strcpy(bsd, argv[i]); 
            readbsd = true; 
            bsd = prepareDir(bsd); 
            setBsd(paths, bsd); 
        } 
        else if (!strcmp(argv[i], "-q")) //.qry 
        { i++; 
            char* qryfull = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            char* qryarq = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            char* qryname = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            //setGeoFull(paths, argv[i]);
            strcpy(qryfull, argv[i]); 
            readqry = true; 
            //bool lais = false;

            //prepareDoc(paths, qryname, lais); 
            prepareDoc(qryfull, qryname);
            strcpy(qryarq, qryname);
            strcat(qryarq, ".qry"); 
            setQryArq(paths, qryarq); 
            setQryName(paths, qryname); 
            //free(qryfull);
        } 
    } 
    if (readbed && readgeo)// bed/.geo 
        { char* bedgeo = calloc(strlen(getBed(paths)) + strlen(getGeoArq(paths)) + 1, sizeof(char)); 
        strcpy(bedgeo, getBed(paths)); 
        strcat(bedgeo, getGeoArq(paths)); 
        setBedGeo(paths, bedgeo); 
    } 
    if (readbed && readqry) //bed/.qry 
        { char* bedqry = calloc(strlen(getBed(paths)) + strlen(getQryArq(paths)) + 1, sizeof(char)); 
        strcpy(bedqry, getBed(paths)); 
        strcat(bedqry, getQryArq(paths));
        setBedQry(paths, bedqry);
    } 
    if (readbsd && readgeo) // bsd/geoname.svg 
        { char* bsdgeosvg = calloc(strlen(getBsd(paths)) + strlen(getGeoName(paths)) + 5, sizeof(char));
        strcpy(bsdgeosvg, getBsd(paths));
        strcat(bsdgeosvg, getGeoName(paths));
        strcat(bsdgeosvg, ".svg");
        setBsdGeoSvg(paths, bsdgeosvg);
    } 
    if (readbsd && readqry) // bsd/geoname_qryname.svg e bsd/geoname_qryname.txt 
        {char* bsdgeoqrysvg = calloc(strlen(getBsd(paths)) + strlen(getGeoName(paths)) + strlen(getQryName(paths)) + 6, sizeof(char));
        char* bsdgeoqrytxt = calloc(strlen(getBsd(paths)) + strlen(getGeoName(paths)) + strlen(getQryName(paths)) + 6, sizeof(char));
        strcpy(bsdgeoqrysvg, getBsd(paths));
        strcat(bsdgeoqrysvg, getGeoName(paths));

        strcat(bsdgeoqrysvg, "_");
        strcat(bsdgeoqrysvg, getQryName(paths));
        strcpy(bsdgeoqrytxt, bsdgeoqrysvg);
        strcat(bsdgeoqrysvg, ".svg");
        strcat(bsdgeoqrytxt, ".txt");
        setBsdGeoQrySvg(paths, bsdgeoqrysvg);
        setBsdGeoQryTxt(paths, bsdgeoqrytxt);
    }
} 

void readGeo(void* listc, void* listr, void* listl, void* listt, void* paths) {
    int id, aux = 0;
    double x, x2, y, y2, r, w, h;
    char type[1], corb[20], corp[20], cor[20], a, txto[100];
    void* newform;

    FILE* geo = fopen(getBedGeo(paths), "r");

    if (geo == NULL) { 
        printf("Erro abrindo o .geo \n");
        exit(EXIT_FAILURE);
    } 

    while (!feof(geo)) { fscanf(geo, "%s", type);
        if (!strcmp(type, "c")) //Circle 
        {   fscanf(geo, "%d %lf %lf %lf %s %s", &id, &x, &y, &r, corb, corp);
            newform = callocDataC();

            setCircId(newform,id);
            setCircX(newform,x);
            setCircY(newform,y);
            setCircR(newform,r);
            setCircCorC(newform,corb);
            setCircCorP(newform,corp);
            setCircSl(newform,aux);
            insertAfter(listc, newform);
            
        } 
        else if (!strcmp(type, "r")) //Rectangle 
        {   fscanf(geo, "%d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp);
            newform = callocDataR();

            setRectId(newform,id);
            setRectX(newform,x);
            setRectY(newform,y);
            setRectW(newform,w);
            setRectH(newform,h);
            setRectCorC(newform,corb);
            setRectCorP(newform,corp);
            setRectSl(newform,aux);
            insertAfter(listr, newform); 
       } 
        else if (!strcmp(type, "l")) //Line 
        {   fscanf(geo, "%d %lf %lf %lf %lf %s", &id, &x, &y, &x2, &y2, cor);
            newform = callocDataL();
            setLineId(newform,id);
            setLineX1(newform,x);
            setLineY1(newform,y);
            setLineX2(newform,x2);
            setLineY2(newform,y2);
            setLineCor(newform,cor);
            setLineSl(newform,aux);
            insertAfter(listl, newform);
        } 
        else if (!strcmp(type, "t")) //Text 
        {   fscanf(geo, "%d %lf %lf %s %s %c %s", &id, &x, &y, corb, corp, &a, txto);
            newform = callocDataT();

            setTextId(newform,id);
            setTextX(newform,x);
            setTextY(newform,y);
            setTextCorP(newform,corb);
            setTextCorC(newform,corp);
            setTextA(newform,a);
            setTextText(newform,txto);
            setTextSl(newform,aux);
            insertAfter(listt, newform);
        } 
    } 
    fclose(geo);
} 

int countInp(void* paths) { 
    int count = 0;
    char func[30];
    FILE* qry = fopen(getBedQry(paths), "r");
    if (qry == NULL) { 
        printf("Error opening the .qry file.\n");
        exit(EXIT_FAILURE);
    } 
    while (!feof(qry)) {   
        fscanf(qry, "%s", func);
        if (!strcmp(func, "inp")) { 
            count++;
        } 
    } 
    fclose(qry);
    printf("%d\n", count);
    return count;
} 

void readQry(void* listsele, void* listc, void* listr, void* listl, void* listt, void* paths, FILE* qrysvg, FILE* qrytxt){ 
    int id, n;
    double d, e, x, y, w, h, dx, dy;
    char func[4];
    char corb[20], corp[20];
    int msize = countInp(paths);

    //void* queue = createQueue(msize);
    FILE* qry = fopen(getBedQry(paths), "r");
    if (qry == NULL) { 
        printf("Error opening the .qry file.\n");
        exit(EXIT_FAILURE);
    } 
    while (!feof(qry)) { 
        fscanf(qry, "%s", func);
        if (!strcmp(func, "inp")) //2 
        { 
            //inp(listc, listr, listl, listt, queue, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "rmp")) //3 
        { 
            //rmp(queue, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "pol")) //9 
        { 
            //pol(queue, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "clp")) //4 
        { 
            //clp(queue, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "sel")) //5 done 
        { 
            sel(listsele, listc, listr, listl, listt, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "sel+")) //6 
        { 
            selPlus(listsele, listc, listr, listl, listt, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "dels")) //7 
        { 
            dels(listsele,listc, listr, listl, listt, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "dps")) //1 
        {   
            dps(listc, listr, listl, listt, qry, qrysvg, qrytxt);
        }   
        else if (!strcmp(func, "ups")) //8 
        { 
            ups(listsele,listc, listr, listl, listt, qry, qrysvg, qrytxt);
        } 
        //strcpy(func, "SP");
    } 
    fclose(qry);
}