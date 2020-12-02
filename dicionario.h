/* 
 * File:   avl.h
 * Author: Francisco Rosa Dias de Miranda e Hiago Vinicius Americo
 */
#ifndef DIC_H
#define DIC_H

#include "avl.h"

/* Insere um elemento no dicionario*/
bool dicionario_inserir (AVL *T, ITEM item);

/* Remove um elemento do dicionário  */
bool dicionario_remover (AVL *T, ITEM item);

#endif /* dicionario.H */