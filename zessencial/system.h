#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readParam(int argc, char** argv, void* paths);
void readGeo( void* paths);
void readQry(void* lists, void* paths, FILE* qrysvg, FILE* qrytxt);

#endif