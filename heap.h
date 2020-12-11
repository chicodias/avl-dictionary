/* 
 * File:   heap.h
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */

#ifndef heap_H
#define heap_H

#include "item.h"

typedef
struct fila_prior FILA_PRIOR;

// protótipos das funções

void imprimir (FILA_PRIOR * f, int n); // imprime os n primeiros termos da fila na stdout

void fila_inserir (FILA_PRIOR * f, ITEM item); // aloca um ITEM e insere-o na fila

bool buscar(FILA_PRIOR * f, ITEM item); // busca um elemento na fila e incrementa sua prioridade se encontrar

void excluir (FILA_PRIOR ** F); // exclui uma fila

FILA_PRIOR *criar(int n); // cria a fila

int cheia(FILA_PRIOR *fp); // verifica se a fila está cheia

int vazia(FILA_PRIOR *fp); // verifica se a fila esta vazia

ITEM *remover (FILA_PRIOR *fp); // remove um elemento da fila

#endif /* heap.h */