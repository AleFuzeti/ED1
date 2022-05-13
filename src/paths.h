#ifndef PATHS_H
#define PATHS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void* createAllPaths();
char* prepareDir(char* dir);
//char* prepareDoc(void* path, char* onlyname, bool lais);
char* prepareDoc(char* asread, char* onlyname);

void freee(void* paths);

void* setQryFull (void* path, char* qryfull);
void* setGeoFull (void* path, char* geofull);
char* getQryFull(void* path);
char* getGeoFull(void* path);


void* setQryName(void* path, char* qryname);
void* setGeoName(void* path, char* geoname);
void* setBed (void* path, char* bed);
void* setBsd(void* path, char* bsd);
void* setBedGeo(void* path, char* bedgeo);
void* setGeoArq(void* path, char* geoarq);
void* setBedQry(void* path, char* bedqry);
void* setQryArq(void* path, char* qryarq);
void* setBsdGeoSvg(void* path, char* bsdgeosvg);
void* setBsdGeoQrySvg(void* path, char* bsdgeoqrysvg);
void* setBsdGeoQryTxt(void* path, char* bsdgeoqrytxt);

char* getQryName(void* path);
char* getGeoName(void* path);

char* getBed(void* path);
char* getBsd(void* path);
char* getBedGeo(void* path);
char* getGeoArq(void* path);
char* getBedQry(void* path);
char* getQryArq(void* path);
char* getBsdGeoSvg(void* path);
char* getBsdGeoQrySvg(void* path);
char* getBsdGeoQryTxt(void* path);
   
#endif