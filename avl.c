/* 
 * File:   avl.c
 * Author: Francisco Rosa Dias de Miranda e Hiago Vinicius Americo
 */
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
NO* avl_buscar_no (NO* raiz, ITEM chave);
void avl_imprimir_no (NO * r);
bool avl_remover_no (NO **raiz, ITEM chave);
int avl_altura_no (NO * T);
NO *rodar_direita_esquerda(NO *a);
NO *rodar_esquerda_direita(NO *a);
NO * rodar_esquerda(NO *a);
NO * rodar_direita(NO *a);


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
    if (avl_buscar(T, item) == NULL)
        return (avl_inserir_no (T->raiz, item));

    // elemento ja estava na arvore
    return ERRO;    
}

// função de apoio - interna no .c do TAD 
bool avl_inserir_no (NO *raiz, ITEM item) 
{ 
    bool res = TRUE;

    // se esta a esquerda da raiz
    if (strcmp(item, raiz->item) < 0) 
    {   
        // insere na esquerda da raiz
        if (raiz->esq != NULL) 
            res = avl_inserir_no(raiz->esq, item);

        // insere no filho esquerdo
        else
            res = avl_inserir_filho(FILHO_ESQ, raiz, item)!=NULL;
        
        // desbalanceamento pro lado esquerdo
        if (avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir) == 2)
        {
            if (strcmp(item, raiz->esq->item) < 0)
                raiz = rodar_direita(raiz);  // Caso 2.1 
            else            
                raiz = rodar_esquerda_direita(raiz); // Caso 2.2      
        }

    } 
    // a direita da saiz
    else
    { 
        if (strcmp(item, raiz->item) > 0) 
        { 
            if(raiz->dir != NULL) 
                res = avl_inserir_no(raiz->dir, item); 
            else
                res = avl_inserir_filho(FILHO_DIR, raiz, item)!=NULL;      
            
            // desbalanceamento pro lado direito
            if (avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir) == -2)
            {
                if (strcmp(item, raiz->dir->item) > 0)
                    raiz = rodar_esquerda(raiz);  // Caso 1.1 
                else            
                    raiz = rodar_direita_esquerda(raiz); // Caso 1.2      
            }            
        }
        else
            res = FALSE;     
    }
    raiz->altura = max(avl_altura_no(raiz->esq), avl_altura_no(raiz->dir)) + 1; 
    
    return res;
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
ITEM * avl_buscar (AVL *T, ITEM chave)
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
NO* avl_buscar_no (NO* raiz, ITEM chave) 
{ 
    if(raiz == NULL)
        return NULL;     

    else 
        if(strcmp(chave,raiz->item) == 0)
            return (raiz);      
        else 
            if (strcmp(chave, raiz->item) < 0) 
                return (avl_buscar_no(raiz->esq, chave));        
            else 
                return (avl_buscar_no(raiz->dir, chave));
}

/* REMOVE um elemento da árvore. retorna TRUE se conseguir ou FALSE caso contrario */
bool avl_remover (AVL *T, ITEM chave)
{    
    if (T != NULL)
        return (avl_remover_no (&T->raiz, chave)); 
    
    return(FALSE);
}

 // função interna no .c 
bool avl_remover_no (NO **raiz, ITEM chave)
{
    bool res = TRUE;

    if ((*raiz) == NULL) 
        return FALSE; // chave não existe
        
    if(strcmp((*raiz)->item, chave) == 0)
    { //chave encontrada     
        NO *aux = (*raiz);
        // CASOS 1 : filho esquerdo vazio 
        if ((*raiz)->esq == NULL) 
        {          
            (*raiz) = (*raiz)->dir; 
            free(aux);          
            aux = NULL;

            // desbalanceamento pro lado esquerdo
            if (avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir) == 2)
            {
                if (strcmp(chave, (*raiz)->esq->item) < 0)
                    *raiz = rodar_direita(*raiz);  // Caso 2.1 
                else            
                    *raiz = rodar_esquerda_direita(*raiz); // Caso 2.2      
            }
                   
        }   
        // CASO 2: filho direito vazio
        else if ((*raiz)->dir == NULL) 
        {              
            (*raiz) = (*raiz)->esq; 
            free(aux);              
            aux = NULL;           

            // desbalanceamento pro lado direito
            if (avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir) == -2)
            {
                if (strcmp(chave, (*raiz)->dir->item) > 0)
                    *raiz = rodar_esquerda(*raiz);  // Caso 1.1 
                else            
                    *raiz = rodar_direita_esquerda(*raiz); // Caso 1.2      
            }

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


            // desbalanceamento pro lado esquerdo
            if (avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir) == 2)
            {
                if (strcmp(chave, (*raiz)->esq->item) < 0)
                    *raiz = rodar_direita(*raiz);  // Caso 2.1 
                else            
                    *raiz = rodar_esquerda_direita(*raiz); // Caso 2.2      
            }


        }      
    }
    else if (strcmp ((*raiz)->item, chave) > 0)
    { 
        res = avl_remover_no (&(*raiz)->esq, chave); 
    }
    else
    {
        res = avl_remover_no (&(*raiz)->dir, chave); 
    }

    (*raiz)->altura = max(avl_altura_no((*raiz)->esq), avl_altura_no((*raiz)->dir)) + 1; 

    return res;     
}

/* retorna a altura de uma árvore */
int avl_altura (AVL * T)
{
    if (T == NULL)
        return ERRO;
    return (avl_altura_no(T->raiz));
}

/* Função auxiliar ao TAD */
int avl_altura_no (NO * no)
{
    if (no == NULL) 
        return -1;
    else 
        return no->altura;     
    
}
void avl_imprimir (AVL * T){
    avl_imprimir_no (T->raiz);
}

/* Imprime a árvore em ordem */
void avl_imprimir_no (NO * r)
{
    if (r == NULL) return;
    
    avl_imprimir_no(r->esq);
    printf("%s\n",r->item); 
    avl_imprimir_no(r->dir);
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

