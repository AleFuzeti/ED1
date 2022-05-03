#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "declaracoes.h"
#include "lista.h"
#include "data.h"
#include "paths.h"

typedef struct all_paths
{
    char* bed;
    char* bsd;
    char* bedgeo;
    char* geoarq;
    char* geoname;
    char* bedqry;
    char* qryarq;
    char* qryname;
    char* bsdgeosvg;
    char* bsdgeoqrysvg;
    char* bsdgeoqrytxt;
} all_paths;

void* createAllPaths(){
    all_paths* aux = calloc(1, sizeof(all_paths));
    return aux;
}

char* prepareDir(char* dir){
    if (dir[strlen(dir - 1)] != '/'){
        dir = realloc(dir, strlen(dir) + 2);
        strcat(dir, "/");
        return dir;
    }
}

char* prepareDoc(char* asread, char* onlyname){
    int index = 0, pos = 0;
    bool found = false;

    for (int i = strlen(asread) - 1; i >= 0; i--){
        if (asread[i] == '/'){
            index = i;
            found = true;
            break;
        }
    }
    if (found){
        for(int i = index + 1; i < strlen(asread); i++){
            if (asread[1] == '.'){
                onlyname[pos] = '\0';
                break;
            }
            else{
                onlyname[pos] = asread[i];
                pos++;
            }
        }
    }
    else{
        strcpy(onlyname, asread);
        for (int i = 0; i < strlen(onlyname); i++){
            if (onlyname[i] == '.'){
                onlyname[i] = '\0';
            }
        }
    }
}

    void* setBed (void* path, char* bed){
        all_paths* paths = path;
        paths->bed = bed;
    }
    void* setBsd(void* path, char* bsd){
        all_paths* paths = path;
        paths->bsd = bsd;
    }
    void* setBedGeo(void* path, char* bedgeo){
        all_paths* paths = path;
        paths->bedgeo = bedgeo;
    }
    void* setGeoArq(void* path, char* geoarq){
        all_paths* paths = path;
        paths->geoarq = geoarq;
    }
    void* setGeoName(void* path, char* geoname){
        all_paths* paths = path;
        paths->geoname = geoname;
    }
    void* setBedQry(void* path, char* bedqry){
        all_paths* paths = path;
        paths->bedqry = bedqry;
    }
    void* setQryArq(void* path, char* qryarq){
        all_paths* paths = path;
        paths->qryarq = qryarq;
    }
    void* setQryname(void* path, char* qryname){
        all_paths* paths = path;
        paths->qryname = qryname;
    }
    void* setBsdGeoSvg(void* path, char* bsdgeosvg){
        all_paths* paths = path;
        paths->bsdgeosvg = bsdgeosvg;
    }
    void* setBsdGeoQrySvg(void* path, char* bsdgeoqrysvg){
        all_paths* paths = path;
        paths->bsdgeoqrysvg = bsdgeoqrysvg;
    }
    void* setBsdGeoQryTxt(void* path, char* bsdgeoqrytxt){
        all_paths* paths = path;
        paths->bsdgeoqrytxt = bsdgeoqrytxt;
    }

    char* getBed(void* path){
        all_paths* paths = path;
        return paths->bed;
    }
    char* getBsd(void* path){
        all_paths* paths = path;
        return paths->bsd;
    }
    char* getBedGeo(void* path){
        all_paths* paths = path;
        return paths->bedgeo;
    }
    char* getGeoArq(void* path){
        all_paths* paths = path;
        return paths->geoarq; 
    }
    char* getGeoname(void* path){
        all_paths* paths = path;
        return paths->geoname;
    } 

    char* getBedQry(void* path){
        all_paths* paths = path;
        return paths->bedqry;
    } 
    char* getQryArq(void* path){
        all_paths* paths = path;
        return paths->qryarq;
    } 
    char* getQryname(void* path){
        all_paths* paths = path;
        return paths->qryname;
    } 
    char* getBsdGeoSvg(void* path){
        all_paths* paths = path;
        return paths->bsdgeosvg;
    } 
    char* getBsdGeoQrySvg(void* path){
        all_paths* paths = path;
        return paths->bsdgeoqrysvg;
    } 
    char* getBsdGeoQryTxt(void* path){
        all_paths* paths = path;
        return paths->bsdgeoqrytxt;
    } 
   