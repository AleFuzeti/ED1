#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "lista.h"

void readParam(int argc, char** argv, void* paths);
void readGeo(void* listc, void* listr, void* listl, void* listt, void* paths);
void readQry(void* listsele, void* listc, void* listr, void* listl, void* listt, void* paths, FILE* qrysvg, FILE* qrytxt);

int countInp(void* paths);

#endif