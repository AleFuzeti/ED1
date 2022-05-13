#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "declaracoes.h"
#include "lista.h"
#include "data.h"
#include "paths.h"
#include  "system.h"
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
    //char* qryfull;
    //char* geofull;


} all_paths;

void* createAllPaths(){
    all_paths* aux = calloc(1, sizeof(all_paths));
    return aux;
}

char* prepareDir(char* dir){
    if (dir[strlen(dir)-1] != '/'){
        dir = realloc(dir, strlen(dir) + 2);
        strcat(dir, "/");
        return dir;
    }
}

//char* prepareDoc(void* path, char* onlyname, bool lais){
char* prepareDoc(char* asread, char* onlyname){
    int index = 0, pos = 0;
    bool found = false;
    //all_paths* aux = path;
   // char*asread;

    /*if(lais){
        asread = aux->geofull;
    }else{
        asread = aux->qryfull;
    }*/
    
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


void freee(void* paths){
    all_paths* aux = paths;
    
    if(aux->bed){
        free(aux->bed);
    }
    if(aux->bsd){
        free(aux->bsd);
    }
    if(aux->bedgeo){
        free(aux->bedgeo);
    }
    if(aux->geoarq){
        free(aux->geoarq);
    }
    if(aux->geoname){
        free(aux->geoname);
    }
    if(aux->bedqry){
        free(aux->bedqry);
    }
    if(aux->qryarq){
        free(aux->qryarq);
    }
    if(aux->qryname){
        free(aux->qryname);
    }
    if(aux->bsdgeosvg){
        free(aux->bsdgeosvg);
    }
    if(aux->bsdgeoqrysvg){
        free(aux->bsdgeoqrysvg);
    }
    if(aux->bsdgeoqrytxt){
        free(aux->bsdgeoqrytxt);
    
    }


    free(paths);
}

/*
void* setGeoFull (void* path, char* geofull){
    all_paths* paths = (all_paths*)path;
    paths->geofull = geofull;    
}
void* setQryFull (void* path, char* qryfull){
    all_paths* paths = (all_paths*)path;
    paths->qryfull = qryfull;    
}
char* getQryFull(void* path){
    all_paths* paths = path;
    return paths->qryfull;
}
char* getGeoFull(void* path){
    all_paths* paths = path;
    return paths->geofull;
}
*/


void* setBed (void* path, char* bed){
    all_paths* paths = (all_paths*)path;
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
void* setQryName(void* path, char* qryname){
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
char* getGeoName(void* path){
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
char* getQryName(void* path){
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