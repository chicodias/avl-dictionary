/* 
 * File:   avl.h
 * Author: Francisco Rosa Dias de Miranda e Hiago Vinicius Americo
 */
#ifndef AVL_H
#define AVL_H

#define bool int /*Define tipo booleano*/
#define TRUE 1
#define FALSE 0
#define ERRO -32000

#define FILHO_ESQ 0 
#define FILHO_DIR 1

typedef struct avl AVL;
typedef char * ITEM;

/* Funções deste TAD */

AVL * avl_criar (void); /*Criacao da ABB e retorno do seu ponteiro*/

void avl_apagar (AVL **T); /*Apaga todo o conteudo da lista e libera o bloco de memoria*/

bool avl_inserir (AVL *T, ITEM item); /*Insere o ITEM na ABB*/

bool avl_remover (AVL *T, int chave); /* REMOVE um item da arvore */

ITEM * avl_buscar (AVL *T, int chave); /*Busca a chave na lista e e a retorna. se nao existir, retorna ERRO*/

void avl_imprimir (AVL * T); /*Imprime os elementos na arvore ordenadamente*/

int avl_altura (AVL * T); /* retorna a altura de uma arvore */

bool avl_vazia (AVL * T); /* retorna 1 se a arv está vazia, 0 caso contrario, ERRO caso nao tenha sido alocada */

#endif /* A_H */