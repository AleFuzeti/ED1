#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "declaracoes.h"
#include "lista.h"
#include "data.h"
#include "system.h"
#include "paths.h" 
//#include "qry.h" 
//#include "queue.h" 
//#include "svg.h" 
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
            strcpy(geofull, argv[i]); 
            readgeo = true; 
            prepareDoc(geofull, geoname); 
            strcpy(geoarq, geoname); 
            strcat(geoarq, ".geo"); 
            setGeoArq(paths, geoarq); 
            setGeoName(paths, geoname); 
        }
        else if (!strcmp(argv[i], "-o")) //path - diretorio base de saÃ­da (BSD) 
            {i++;
            char* bsd = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            strcpy(bsd, argv[i]); 
            readbsd = true; 
            bsd = prepareDir(bsd); 
            setBsd(paths, bsd); 
        } 
        else if (!strcmp(argv[i], "-q")) //.qry (sob o diretorio BED) 
            { i++; 
            char* qryfull = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            char* qryarq = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            char* qryname = calloc(strlen(argv[i]) + 1, sizeof(char)); 
            strcpy(qryfull, argv[i]); 
            readqry = true; 
            prepareDoc(qryfull, qryname); 
            strcpy(qryarq, qryname);
            strcat(qryarq, ".qry"); 
            setQryArq(paths, qryarq); 
            setQryName(paths, qryname); 
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
    if (readbsd && readqry) // bsd/geoname_qryname.svg and bsd/geoname_qryname.txt 
        { char* bsdgeoqrysvg = calloc(strlen(getBsd(paths)) + strlen(getGeoName(paths)) + strlen(getQryName(paths)) + 6, sizeof(char));
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

void readGeo(void*listc, void* listr, void* listl, void* listt, void* paths) {
    int id;
    double x, x2, y, y2, r, w, h;
    char type[1], corb[20], corp[20], cor[20], a[1], txto[100];
    //void* listc = newList();
    //void* listr = newList();
    //void* listl = newList();
    //void* listt = newList();
    void* newform;
    //void* newnode;
    FILE* geo = fopen(getBedGeo(paths), "r");

    if (geo == NULL) { 
        printf("Error opening the .geo file.\n");
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
            //setCirc(newform, id, x, y, r, corb, corp);
            // newnode = createNode();
            // addDataToNode(newnode, newform);
            insertAfter(listc, newnode);
            
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
            //setRect(newform, id, x, y, w, h, corb, corp);
            //newnode = createNode();
            //addDataToNode(newnode, newform);
            insertAfter(listr, newnode); 
       } 
        else if (!strcmp(type, "l")) //Line 
        {   fscanf(geo, "%d %lf %lf %lf %lf %s", &id, &x, &y, &x2, &y2, cor);
            newform = callocDataL();

            setLineId(newform,id);
            setLineX1(newform,x1);
            setLineY1(newform,y1);
            setLineX2(newform,x2);
            setLineY2(newform,y2);
            setLineCor(newform,cor);
            //setLine(newform, id, x, y, x2, y2, cor);
            //newnode = createNode();
            //addDataToNode(newnode, newform);
            insertAfter(listl, newnode);
        } 
        else if (!strcmp(type, "t")) //Text 
        {   fscanf(geo, "%d %lf %lf %s %s %s %[^\n]s", &id, &x, &y, corb, corp, a, txto);
            newform = callocDataT();

            setTextId(newform,id);
            setTextX(newform,x);
            setTextY(newform,y);
            setTextCorP(newform,corb);
            setTextCorB(newform,corb);
            setTextA(newform,a);
            //falta o texto!!!!!!!!!!!!

            //setText(newform, id, x, y, corb, corp, a, txto);
            //newnode = createNode();
            //addDataToNode(newnode, newform);
            insertAtTail(listt, newnode);
        } 
    } 
    fclose(geo);
} 

/*int countInp(void* paths) { 
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
}*/ 

void readQry(void* lists, void* paths, FILE* qrysvg, FILE* qrytxt) { 
    int id, n;
    double d, e, x, y, w, h, dx, dy;
    char func[4];
    char corb[20], corp[20];
    int msize = countInp(paths);

    void* queue = createQueue(msize);
    FILE* qry = fopen(getBedQry(paths), "r");
    if (qry == NULL) { 
        printf("Error opening the .qry file.\n");
        exit(EXIT_FAILURE);
    } 
    while (!feof(qry)) { 
        fscanf(qry, "%s", func);
        if (!strcmp(func, "inp")) //2 
        { 
            inp(lists, queue, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "rmp")) //3 
        { 
            rmp(queue, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "pol")) //9 
        { 
            pol(queue, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "clp")) //4 
        { 
            clp(queue, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "sel")) //5 done 
        { 
            sel(lists, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "sel+")) //6 
        { 
            selPlus(lists, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "dels")) //7 
        { 
            dels(lists, qry, qrysvg, qrytxt);
        } 
        else if (!strcmp(func, "dps")) //1 
        {   
            dps(lists, qry, qrysvg, qrytxt);
        }   
        else if (!strcmp(func, "ups")) //8 
        { 
            ups(lists, qry, qrysvg, qrytxt);
        } 
        //strcpy(func, "SP");
    } 
    fclose(qry);
 }