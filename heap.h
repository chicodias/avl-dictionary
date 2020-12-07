/* 
 * File:   heap.h
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */
#include "avl.h"
#ifndef heap_H
#define heap_H

#define TAM 100

typedef
struct fila_prior FILA_PRIOR;

/* typedef struct item ITEM;

struct item 
{
    int elem;
    int chave; // prioridade  
};  */
    
// protótipos das funções

FILA_PRIOR *criar();
int cheia(FILA_PRIOR *fp);
int vazia(FILA_PRIOR *fp);
int inserir (FILA_PRIOR *fp, ITEM *item);
ITEM *remover (FILA_PRIOR *fp);


#endif /* heap.h */