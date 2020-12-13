/* 
 * File:   item.h
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */
#ifndef item_H
#define item_H

/* bibliotecas padrão do C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define bool int /*Define tipo booleano*/
#define TRUE 1
#define FALSE 0
#define ERRO -32000


typedef         /*Tipo ITEM da AVL e da FP*/
struct item_ 
{
    char *nome; // palavra armazenada
    int chave;  // prioridade
}
ITEM;


/* recebe uma string, e aloca na memória */
char * alocaPalavra (char * pal);

/* libera uma palavra do heap */
void liberaPalavra(char ** pal);

/* compara dois itens em ordem de chave*/
int compar(const void * A, const void * B);
int compara(ITEM * a, ITEM * b);


#endif