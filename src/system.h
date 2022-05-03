#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readParam(int argc, char** argv, void* paths);
void readGeo(void* listc, void* listr, void* listl, void* listt, void* paths);
void readQry(void* listc, void* listr, void* listl, void* listt, void* paths, FILE* qrysvg, FILE* qrytxt);

    void* setBed (void* path, char* bed);
    void* setBsd(void* path, char* bsd);
    void* setBedGeo(void* path, char* bedgeo);
    void* setGeoArq(void* path, char* geoarq);
    void* setGeoName(void* path, char* geoname);
    void* setBedQry(void* path, char* bedqry);
    void* setQryArq(void* path, char* qryarq);
    void* setQryName(void* path, char* qryname);
    void* setBsdGeoSvg(void* path, char* bsdgeosvg);
    void* setBsdGeoQrySvg(void* path, char* bsdgeoqrysvg);
    void* setBsdGeoQryTxt(void* path, char* bsdgeoqrytxt);

    char* getBed(void* path);
    char* getBsd(void* path);
    char* getBedGeo(void* path);
    char* getGeoArq(void* path);
    char* getGeoName(void* path);
    char* getBedQry(void* path);
    char* getQryArq(void* path);
    char* getQryName(void* path);
    char* getBsdGeoSvg(void* path);
    char* getBsdGeoQrySvg(void* path);
    char* getBsdGeoQryTxt(void* path);
   
#endif