/* 
 * File:   item.c
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */
#define _POSIX_C_SOURCE 200809L
#include <string.h>

#include "item.h"

/* recebe uma string, e aloca na memória */
char * alocaPalavra (char * pal)
{
    int n = strnlen(pal, 50);
    char * str = (char *) malloc(n*sizeof(char)+1);
    if (str == NULL)
        return NULL;

    strcpy(str, pal);
    return str;
}

void liberaPalavra(char ** pal)
{
    free(*pal);
    *pal = NULL;
}