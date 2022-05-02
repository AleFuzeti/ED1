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