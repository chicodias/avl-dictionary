/* 
 * File:   avl.c
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */

#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a > b) ? a : b)

typedef struct node_ NO;

         /* NÓ da avl */
struct node_
{
    ITEM item;
    int altura;
    NO * esq;
    NO * dir;
};

struct arv_
{
    NO * raiz;
};

/* Cabeçalhos das funções de apoio internas ao TAD: */
void avl_apagar_nos (NO ** raiz);
bool avl_inserir_no (NO **raiz, ITEM item);
NO * avl_inserir_filho (int filho, NO *no, ITEM item);
NO* avl_buscar_no (NO* raiz, ITEM chave);
bool avl_remover_no (NO **raiz, ITEM chave);
void avl_imprimir_no (NO * r);
int avl_altura_no (NO * T);
NO *rodar_direita_esquerda(NO *a);
NO *rodar_esquerda_direita(NO *a);
NO * rodar_esquerda(NO *a);
NO * rodar_direita(NO *a);

/* @retorna o endereço da raiz de uma AVL */
ARV * avl_criar (void) /*Criacao da avl e retorno do seu ponteiro*/
{
    ARV *r = (ARV *) malloc (sizeof(ARV));
    r->raiz = NULL;

    if (r == NULL)
        r->raiz = NULL;
    return r;
}

/* recebe uma AVL, apaga seus nós e desaloca da memoria */
void avl_apagar (ARV **T) /*Apaga todo o conteudo da ARV e libera o bloco de memoria*/
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

/* @param: um item na arvore,
   @retorno: 1 se conseguir ou 0 caso contrario. */
bool avl_inserir (ARV **T, ITEM item)
{ 
    if (*T == NULL)
        return (ERRO);
    
    if (avl_vazia (*T))
    { 
        (*T)->raiz = (NO *) malloc (sizeof(NO)); 
        if ((*T)->raiz != NULL)
        {
            (*T)->raiz->item = item; 
            (*T)->raiz->esq = NULL; 
            (*T)->raiz->dir = NULL; 
            return (TRUE);        
        }    
    }  
   // nao inserir um elemento repetido na arvore
    if (avl_buscar(*T, item) == NULL)
        return (avl_inserir_no (&(*T)->raiz, item));
    
    // elemento ja estava na arvore
    return ERRO;    
}

// função de apoio - interna no .c do TAD 
bool avl_inserir_no (NO **raiz, ITEM item) 
{ 
    bool res = FALSE;
    if (strcmp(item.nome, (*raiz)->item.nome)  < 0) 
    {   
        if ((*raiz)->esq != NULL) 
            res = avl_inserir_no(&(*raiz)->esq, item);
        else
            res = avl_inserir_filho(FILHO_ESQ, (*raiz), item)!=NULL;

                 // desbalanceamento pro lado esquerdo
        if (avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir) == 2)
        {
           if (strcmp(item.nome, (*raiz)->esq->item.nome) < 0)
                    *raiz = rodar_direita(*raiz);  // Caso 2.1 
                else            
                    *raiz = rodar_esquerda_direita(*raiz); // Caso 2.2 
        }
    }



    else
    { 
        if (strcmp(item.nome, (*raiz)->item.nome)  > 0) 
        { 
            if ((*raiz)->dir != NULL) 
                res =  avl_inserir_no(&(*raiz)->dir, item); 
            else
                res = avl_inserir_filho(FILHO_DIR, *raiz, item)!=NULL;      
         // desbalanceamento pro lado direito
            if (avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir) == -2)
            {
                if (strcmp(item.nome, (*raiz)->dir->item.nome) > 0)
                    *raiz = rodar_esquerda(*raiz);  // Caso 1.1 
                else            
                    *raiz = rodar_direita_esquerda(*raiz); // Caso 1.2  
   
            }

        } 
        else
            return (FALSE);     
    } 
    
    (*raiz)->altura = max(avl_altura_no((*raiz)->esq), avl_altura_no((*raiz)->dir)) + 1; 
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
        pnovo->altura = 0;
        //pnovo->item.freq = 0;
        
        if (filho == FILHO_ESQ)
            no->esq = pnovo; 
        else           
            no->dir = pnovo;     
    }
    return (pnovo);  
}

/* busca uma chave na árvore e retorna o respectivo item */
ITEM * avl_buscar (ARV *T, ITEM chave)
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

    else //encontrou
        if(strcmp(chave.nome, raiz->item.nome) == 0)
        {
         //   raiz->item.freq++;
            return (raiz);      
        }
        else 
            if (strcmp(chave.nome, raiz->item.nome) < 0) 
                return (avl_buscar_no(raiz->esq, chave));        
            else 
                return (avl_buscar_no(raiz->dir, chave));
}



/* REMOVE um elemento da árvore. retorna TRUE se conseguir ou FALSE caso contrario */
bool avl_remover (ARV **T, ITEM chave)
{    
    if (T != NULL)
        return (avl_remover_no (&(*T)->raiz, chave)); 
    
    return(FALSE);
}

 // função interna no .c 
bool avl_remover_no (NO **raiz, ITEM chave)
{
    bool res = FALSE;
    if ((*raiz) != NULL) 
    {        
        if(strcmp(chave.nome, (*raiz)->item.nome) == 0)
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
                NO * t = (*raiz)->esq;
                ITEM tmp;
                while (t != NULL && t->dir != NULL)
                    t = t->dir; 
            
            // copia o conteúdo desse nó, remove-o da árvore, em seguida substitui pelo nó a ser 
            // inicialmente removido
                strcpy(tmp.nome, t->item.nome);
                tmp.freq = t->item.freq;
                
                avl_remover_no(raiz, t->item);
                
                strcpy((*raiz)->item.nome, tmp.nome);
                (*raiz)->item.freq = tmp.freq;
            }
            res= TRUE;
        }
        else if (strcmp(chave.nome, (*raiz)->item.nome) < 0)
            res=avl_remover_no (&(*raiz)->esq, chave); 
        else    
            res=avl_remover_no (&(*raiz)->dir, chave);      

        
        
        if((*raiz)!=NULL)
        {   //atualizar alturas
            (*raiz)->altura = max(avl_altura_no((*raiz)->esq), avl_altura_no((*raiz)->dir)) + 1; 

        // verificar balanceamento
             // desbalanceamento pro lado direito
            if (avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir) == -2)
            {                
                if (strcmp(chave.nome, (*raiz)->dir->item.nome) > 0)
                    *raiz = rodar_esquerda(*raiz);  // Caso 1.1 
                else            
                    *raiz = rodar_direita_esquerda(*raiz); // Caso 1.2  
            }
            // desbalanceamento pro lado esquerdo
            if (avl_altura_no((*raiz)->esq) - avl_altura_no((*raiz)->dir) == 2)
            {
                if (strcmp(chave.nome, (*raiz)->esq->item.nome) < 0)
                    *raiz = rodar_direita(*raiz);  // Caso 2.1 
                else            
                    *raiz = rodar_esquerda_direita(*raiz); // Caso 2.2 
            }
                
        }

    }
    return res;
}


/* retorna a altura de uma árvore */
int avl_altura (ARV * T)
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

/* Imprime a árvore em ordem */
void avl_imprimir (ARV *T)
{   
    return avl_imprimir_no(T->raiz);
}
    
void avl_imprimir_no (NO * r)
{    
    if (r == NULL) return;
    avl_imprimir_no(r->esq);
    printf("%s\n", r->item.nome); 
    avl_imprimir_no(r->dir);
}

/*  VERIFICA SE A avl É VAZIA */
bool avl_vazia (ARV * T)
{
    if (T == NULL)
        return ERRO;
    return (T->raiz == NULL);
}

/* funções de rotação da AVL auxiliares ao TAD */

NO * rodar_direita(NO *a) 
{   
    NO *b = a->esq;   
    a->esq = b->dir;   
    b->dir = a; 
    
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
