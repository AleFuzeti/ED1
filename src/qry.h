#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int inp( void* listc, void* listr, void* listl, void* listt, void* queue, FILE* qry, FILE* qrysvg, FILE* qrytxt);
int rmp(void* queue, FILE* qry, FILE* qrysvg, FILE* qrytxt);
int pol(void* queue, FILE* qry, FILE* qrysvg, FILE* qrytxt);
int clp(void* queue, FILE* qry, FILE* qrysvg, FILE* qrytxt);
int sel(void* listsele, void* listc, void* listr, void* listl, void* listt, FILE* qry,FILE* qrysvg,FILE* qrytxt);
int selPlus(void* listsele, void* listc, void* listr, void* listl, void* listt, FILE* qry, FILE* qrysvg, FILE* qrytxt);
int dels(void* listsele,void* listc, void* listr, void* listl, void* listt, FILE* qry, FILE* qrysvg, FILE* qrytxt);
int dps(void* listc, void* listr, void* listl, void* listt, FILE* qry, FILE* qrysvg, FILE* qrytxt);
int ups(void* listsele,void* listc, void* listr, void* listl, void* listt, FILE* qry, FILE* qrysvg, FILE* qrytxt);