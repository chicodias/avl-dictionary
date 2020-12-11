/* 
 * File:   heap.h
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */

#ifndef heap_H
#define heap_H

#include "item.h"
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
void imprimir (FILA_PRIOR * f, int n);

void fila_inserir (FILA_PRIOR * f, ITEM item); // insere um elemento na fila


bool buscar(FILA_PRIOR * f, ITEM item); // busca um elemento na fila
void excluir (FILA_PRIOR ** F); // exclui uma fila


FILA_PRIOR *criar(int n); // cria a fila
int cheia(FILA_PRIOR *fp); // verifica se a fila está cheia
int vazia(FILA_PRIOR *fp); // verifica se a fila esta vazia
int inserir (FILA_PRIOR *fp, ITEM *item); // insere um elemento na fila
ITEM *remover (FILA_PRIOR *fp); // remove um elemento da fila

#endif /* heap.h */