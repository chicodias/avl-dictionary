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


typedef         /*Tipo ITEM da ABB*/
struct item_ 
{
    int chave;
    char nome[20];
}
ITEM;

typedef struct node_ NO;

         /* NÓ da ABB */
struct node_
{
     ITEM item;
     NO * esq;
     NO * dir;
};

typedef         /*  endereço da raiz e altura */
struct arv_
{
    NO * raiz;
} ARV;

/* Funções deste TAD */

ARV * abb_criar (void); /*Criacao da ABB e retorno do seu ponteiro*/

void abb_apagar (ARV **T); /*Apaga todo o conteudo da lista e libera o bloco de memoria*/

bool abb_inserir (ARV *T, ITEM item); /*Insere o ITEM na ABB*/

bool abb_remover (ARV *T, int chave); /* REMOVE um item da arvore */

ITEM * abb_buscar (ARV *T, int chave); /*Busca a chave na lista e e a retorna. se nao existir, retorna ERRO*/

void abb_imprimir (NO * h); /*Imprime os elementos na arvore ordenadamente*/

int abb_altura (ARV * T); /* retorna a altura de uma arvore */

bool abb_vazia (ARV * T); /* retorna 1 se a arv está vazia, 0 caso contrario, ERRO caso nao tenha sido alocada */

#endif /* ABB_H */