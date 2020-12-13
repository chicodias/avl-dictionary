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
/* libera uma palavra alocada do heap e seta seu ponteiro para NULL */
void liberaPalavra(char ** pal)
{
    free(*pal);
    *pal = NULL;
}

/* Compara dois ITENS */
/* compara dois elementos */
int compar(const void * A, const void * B)
{
    ITEM * a = *(ITEM **) A,
         * b = *(ITEM **) B;
         
    if (a->chave != b->chave)
        return b->chave - a->chave;
    else
        return strcmp(a->nome, b->nome);
}

/* compara dois itens
@retorno > 0 se b > a
         <0 caso contrario */
int compara(ITEM * a, ITEM * b)
{
         
    if (a->chave != b->chave)
        return b->chave - a->chave;
    else
        return strcmp(a->nome, b->nome);
}
