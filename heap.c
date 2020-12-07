/* 
 * File:   heap.h
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */
#include "stdlib.h"
#include "heap.h"
#include <string.h>
#include <stdio.h>

struct fila_prior 
{
    ITEM* vetor[TAM]; 
    int fim; // último elemento 
    int TAM_M; // tamanho amximo do vetor
};

/* funcoes internas ao tad */
void fix_down(FILA_PRIOR *fp);
void fix_up(FILA_PRIOR *fp);
void swap (FILA_PRIOR *fp, int i, int j);

void fila_inserir (FILA_PRIOR * f, ITEM item)
{

    if(!buscar(f,item))
    {
        ITEM * i = malloc (sizeof(ITEM));
        i->chave = 1;
        strcpy(i->nome, item.nome);
        printf("inseriu\n");
        return;
    }
    printf("nao inseriu\n");

}

bool buscar(FILA_PRIOR * f, ITEM item)
{
    printf("buscando por %s", item.nome);
    for(int i = 0; i< f->fim; i++)
        if( strcmp(f->vetor[i]->nome, item.nome) == 0)
        {
            printf("encontrou");
            f->vetor[i]->chave++;
            fix_up(f);
            return TRUE;
        }
    return FALSE;
}

void imprimir (FILA_PRIOR * f)
{
    for(int i = 0; i<f->fim; i++)
        printf("%d %s\n",f->vetor[i]->chave, f->vetor[i]->nome);
}

FILA_PRIOR *criar() 
{ 
    FILA_PRIOR *fp =   (FILA_PRIOR*)malloc(sizeof(FILA_PRIOR));
    if (fp != NULL)
        fp->fim = -1;     
     
    return fp;   
}

int cheia(FILA_PRIOR *fp) 
{
    return (fp->fim == TAM - 1);   
} 

int vazia(FILA_PRIOR *fp) 
{
    return (fp->fim == -1);   
}

int inserir (FILA_PRIOR *fp, ITEM *item) 
{ 
    if (!cheia(fp)) 
    { 
        fp->fim++; 
        fp->vetor[fp->fim] = item; 
        fix_up(fp); 
        return 1;     
    } 
    return 0;  
}

void fix_up(FILA_PRIOR *fp) 
{
     // função interna 
    int pos = fp->fim; 
    int pai = (pos - 1) / 2; 
    // para heap máximo
    while (pos > 0 && fp->vetor[pos]->chave > fp->vetor[pai]->chave)                   
    {      
        swap(fp, pos, pai); pos = pai;        
        pai = (pai - 1) / 2;    
    }  
}

void swap (FILA_PRIOR *fp, int i, int j) 
{
    // função interna    
    ITEM *tmp = fp->vetor[i]; 
    fp->vetor[i] = fp->vetor[j];
    fp->vetor[j] = tmp;
}

ITEM *remover (FILA_PRIOR *fp) 
{
    if (fp!= NULL && !vazia(fp)) 
    {         
        ITEM *item = fp->vetor[0]; 
        fp->vetor[0] = fp->vetor[fp->fim]; 
        fp->fim--; 
        fix_down(fp); 
        return item;     
    }
    return NULL; 
}

void fix_down(FILA_PRIOR *fp)
{ // função interna
    int fesq, fdir, maior, pos = 0;
    while(pos <= fp->fim / 2)
    { 
        fesq = 2 * pos + 1; 
        fdir = 2 * pos + 2; 
        if (fdir <= fp->fim && fp->vetor[fesq]->chave < fp->vetor[fdir]->chave) 
            maior = fdir; 
        else 
            maior = fesq;   
        if (fp->vetor[pos]->chave >= fp->vetor[maior]->chave) 
            break;                         
        // para heap máximo
        swap(fp, pos, maior);
        pos = maior;   
    } 
}

