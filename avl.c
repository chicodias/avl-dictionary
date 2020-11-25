/* 
 * File:   avl.c
 * Author: Francisco Rosa Dias de Miranda e Hiago Vinicius Americo
 */
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)

typedef struct no NO;

struct no 
{      
    ITEM item; 
    NO * esq; 
    NO * dir; 
    int altura;  // altura do nó
};

struct avl 
{
     NO *raiz;      
};




/* Cabeçalhos das funções de apoio internas ao TAD: */
void avl_apagar_nos (NO ** raiz);
bool avl_inserir_no (NO *raiz, ITEM item);
NO * avl_inserir_filho (int filho, NO *no, ITEM item);
NO* avl_buscar_no (NO* raiz, int chave);
bool avl_remover_no (NO **raiz, int chave);
int avl_altura_no (NO * T);


AVL * avl_criar (void) /*Criacao da AVL e retorno do seu ponteiro*/
{
    AVL *r = (AVL *) malloc (sizeof(AVL));
    r->raiz = NULL;

    if (r == NULL)
        r->raiz = NULL;

    return r;
}

void avl_apagar (AVL **T) /*Apaga todo o conteudo da AVL e libera o bloco de memoria*/
{
    if (*T != NULL)
    {
        avl_apagar_nos(&(*T)->raiz);
        free (*T);
        *T = NULL;
    }
}

void avl_apagar_nos (NO ** raiz) /* função interna ao TAD */
{
    if (*raiz != NULL) 
    {           
        avl_apagar_nos(&(*raiz)->esq); 
        avl_apagar_nos(&(*raiz)->dir); 
        free(*raiz);      
        *raiz = NULL;    
    }
}

/* insere um item na AVLore, retorna 1 se conseguir ou 0 caso contrario. */
bool avl_inserir (AVL *T, ITEM item)
{ 
    if (T == NULL)
        return (ERRO);
    
    if (avl_vazia (T))
    { 
        T->raiz = (NO *) malloc (sizeof(NO)); 
        if (T->raiz != NULL)
        {
            T->raiz->item = item; 
            T->raiz->esq = NULL; 
            T->raiz->dir = NULL; 
            return (TRUE);        
        }    
    }  
   // nao inserir um elemento repetido na arvore
    if (avl_buscar(T, item.chave) == NULL)
        return (avl_inserir_no (T->raiz, item));

    // elemento ja estava na arvore
    return ERRO;    
}

// função de apoio - interna no .c do TAD 
bool avl_inserir_no (NO *raiz, ITEM item) 
{ 
    if (item.chave < raiz->item.chave) 
    {   
        if (raiz->esq != NULL) 
            return (avl_inserir_no(raiz->esq, item));
        else
            return (avl_inserir_filho(FILHO_ESQ, raiz, item)!=NULL);
    } 
    else
    { 
        if (item.chave > raiz->item.chave) 
        { 
            if(raiz->dir != NULL) 
                return avl_inserir_no(raiz->dir, item); 
            else
                return (avl_inserir_filho(FILHO_DIR, raiz, item)!=NULL);      
        } 
        else
            return (FALSE);     
    } 
}

// função de apoio – interna ao .c do TAD
NO *avl_inserir_filho (int filho, NO *no, ITEM item) 
{     
    NO * pnovo = (NO *) malloc (sizeof (NO)); 
    
    if (pnovo != NULL) 
    { 
        pnovo->dir = NULL; 
        pnovo->esq = NULL; 
        pnovo->item = item; 
        
        if (filho == FILHO_ESQ)
            no->esq = pnovo; 
        else           
            no->dir = pnovo;     
    }
    return (pnovo);  
}

/* busca uma chave na árvore e retorna o respectivo item */
ITEM * avl_buscar (AVL *T, int chave)
{ 
    if(T == NULL) 
        return NULL; 
    
    if (avl_vazia(T))  
        return NULL; 
    
    else 
    {    
        NO* no = avl_buscar_no (T->raiz, chave); 
        return (&(no->item));        
    } 
} 

/* funcao auxiliar ao TAD */
NO* avl_buscar_no (NO* raiz, int chave) 
{ 
    if(raiz == NULL)
        return NULL;     

    else 
        if(chave == raiz->item.chave)
            return (raiz);      
        else 
            if (chave < raiz->item.chave) 
                return (avl_buscar_no(raiz->esq, chave));        
            else 
                return (avl_buscar_no(raiz->dir, chave));
}

/* REMOVE um elemento da árvore. retorna TRUE se conseguir ou FALSE caso contrario */
bool avl_remover (AVL *T, int chave)
{    
    if (T != NULL)
        return (avl_remover_no (&T->raiz, chave)); 
    
    return(FALSE);
}

 // função interna no .c 
bool avl_remover_no (NO **raiz, int chave)
{
    if ((*raiz) == NULL) 
        return (FALSE); // chave não existe
        
    if((*raiz)->item.chave == chave)
    { //chave encontrada     
        NO *aux = (*raiz);  // CASOS 1 e 2 
        if ((*raiz)->esq == NULL) 
        {          
            (*raiz) = (*raiz)->dir; 
            free(aux);          
            aux = NULL;       
        }   
        else if ((*raiz)->dir == NULL) 
        {              
            (*raiz) = (*raiz)->esq; 
            free(aux);              
            aux = NULL;           
        }
        else 
        {// CASO 3 – troca

          // encontra a maior chave esquerda
            NO * t = (*raiz)->esq, * u;
            while (t != NULL)
            {
                u = t;
                t = t->dir;
            }

            u->esq = (*raiz)->esq;
            u->dir = (*raiz)->dir;
            (*raiz) = u;
            free(aux);
            aux = NULL;
        }      
    }
    else if ((*raiz)->item.chave > chave) 
        avl_remover_no (&(*raiz)->esq, chave); 
    else
        avl_remover_no (&(*raiz)->dir, chave); 
    
    return (TRUE);     
}

/* retorna a altura de uma árvore */
int avl_altura (AVL * T)
{
    if (T == NULL)
        return ERRO;
    return (avl_altura_no(T->raiz));
}

/* Função auxiliar ao TAD */
int avl_altura_no (NO * T)
{
    if (T == NULL) 
      return -1; // altura da árvore vazia
   else {
      int he = avl_altura_no (T->esq);
      int hd = avl_altura_no (T->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}
void avl_imprimir (AVL * T){
    avl_imprimir_no (T->raiz);
}

/* Imprime a árvore em ordem */
void avl_imprimir_no (NO * r)
{
    if (r == NULL) return;
    
    avl_imprimir(r->esq);
    printf("%s\n",r->item); 
    avl_imprimir(r->dir);
}

/*  VERIFICA SE A avl É VAZIA */
bool avl_vazia (AVL * T)
{
    if (T == NULL)
        return ERRO;
    return (T->raiz == NULL);
}


NO * rodar_direita(NO *a) 
{   
    NO *b = a->esq;   
    a->esq = b->dir;   
    b->dir = a; // atualizar alturas de A e B  
    
    a->altura = max(avl_altura_no(a->esq), avl_altura_no(a->dir)) + 1;
    b->altura = max(avl_altura_no(b->esq), a->altura) + 1;
    
    return b;
}

NO * rodar_esquerda(NO *a) 
{    
    NO *b = a->dir;    
    a->dir = b->esq;
    b->esq = a;
    // atualizar alturas de A e B   
    a->altura = max(avl_altura_no(a->esq), avl_altura_no(a->dir)) + 1;
    b->altura = max(avl_altura_no(b->dir),a->altura) + 1;
    return b;
}


NO *rodar_esquerda_direita(NO *a)   
{
    a->esq = rodar_esquerda(a->esq);
    return rodar_direita(a);  
}

NO *rodar_direita_esquerda(NO *a)   
{    
    a->dir = rodar_direita(a->dir); 
    return rodar_esquerda(a);  
}

