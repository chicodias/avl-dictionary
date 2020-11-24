/* 
 * File:   avl.c
 * Author: Francisco Rosa Dias de Miranda e Hiago Vinicius Americo
 */
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

/* Cabeçalhos das funções de apoio internas ao TAD: */
void abb_apagar_nos (NO ** raiz);
bool abb_inserir_no (NO *raiz, ITEM item);
NO * abb_inserir_filho (int filho, NO *no, ITEM item);
NO* abb_buscar_no (NO* raiz, int chave);
bool abb_remover_no (NO **raiz, int chave);
int abb_altura_no (NO * T);


ARV * abb_criar (void) /*Criacao da ABB e retorno do seu ponteiro*/
{
    ARV *r = (ARV *) malloc (sizeof(ARV));
    r->raiz = NULL;

    if (r == NULL)
        r->raiz = NULL;

    return r;
}

void abb_apagar (ARV **T) /*Apaga todo o conteudo da ARV e libera o bloco de memoria*/
{
    if (*T != NULL)
    {
        abb_apagar_nos(&(*T)->raiz);
        free (*T);
        *T = NULL;
    }
}

void abb_apagar_nos (NO ** raiz) /* função interna ao TAD */
{
    if (*raiz != NULL) 
    {           
        abb_apagar_nos(&(*raiz)->esq); 
        abb_apagar_nos(&(*raiz)->dir); 
        free(*raiz);      
        *raiz = NULL;    
    }
}

/* insere um item na arvore, retorna 1 se conseguir ou 0 caso contrario. */
bool abb_inserir (ARV *T, ITEM item)
{ 
    if (T == NULL)
        return (ERRO);
    
    if (abb_vazia (T))
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
    if (abb_buscar(T, item.chave) == NULL)
        return (abb_inserir_no (T->raiz, item));

    // elemento ja estava na arvore
    return ERRO;    
}

// função de apoio - interna no .c do TAD 
bool abb_inserir_no (NO *raiz, ITEM item) 
{ 
    if (item.chave < raiz->item.chave) 
    {   
        if (raiz->esq != NULL) 
            return (abb_inserir_no(raiz->esq, item));
        else
            return (abb_inserir_filho(FILHO_ESQ, raiz, item)!=NULL);
    } 
    else
    { 
        if (item.chave > raiz->item.chave) 
        { 
            if(raiz->dir != NULL) 
                return abb_inserir_no(raiz->dir, item); 
            else
                return (abb_inserir_filho(FILHO_DIR, raiz, item)!=NULL);      
        } 
        else
            return (FALSE);     
    } 
}

// função de apoio – interna ao .c do TAD
NO *abb_inserir_filho (int filho, NO *no, ITEM item) 
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
ITEM * abb_buscar (ARV *T, int chave)
{ 
    if(T == NULL) 
        return NULL; 
    
    if (abb_vazia(T))  
        return NULL; 
    
    else 
    {    
        NO* no = abb_buscar_no (T->raiz, chave); 
        return (&(no->item));        
    } 
} 

/* funcao auxiliar ao TAD */
NO* abb_buscar_no (NO* raiz, int chave) 
{ 
    if(raiz == NULL)
        return NULL;     

    else 
        if(chave == raiz->item.chave)
            return (raiz);      
        else 
            if (chave < raiz->item.chave) 
                return (abb_buscar_no(raiz->esq, chave));        
            else 
                return (abb_buscar_no(raiz->dir, chave));
}

/* REMOVE um elemento da árvore. retorna TRUE se conseguir ou FALSE caso contrario */
bool abb_remover (ARV *T, int chave)
{    
    if (T != NULL)
        return (abb_remover_no (&T->raiz, chave)); 
    
    return(FALSE);
}

 // função interna no .c 
bool abb_remover_no (NO **raiz, int chave)
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
        abb_remover_no (&(*raiz)->esq, chave); 
    else
        abb_remover_no (&(*raiz)->dir, chave); 
    
    return (TRUE);     
}

/* retorna a altura de uma árvore */
int abb_altura (ARV * T)
{
    if (T == NULL)
        return ERRO;
    return (abb_altura_no(T->raiz));
}

/* Função auxiliar ao TAD */
int abb_altura_no (NO * T)
{
    if (T == NULL) 
      return -1; // altura da árvore vazia
   else {
      int he = abb_altura_no (T->esq);
      int hd = abb_altura_no (T->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

/* Imprime a árvore em ordem */
void abb_imprimir (NO * r)
{
    if (r == NULL) return;
    
    abb_imprimir(r->esq);
    printf("%d %s\n", r->item.chave, r->item.nome); 
    abb_imprimir(r->dir);
}

/*  VERIFICA SE A ABB É VAZIA */
bool abb_vazia (ARV * T)
{
    if (T == NULL)
        return ERRO;
    return (T->raiz == NULL);
}