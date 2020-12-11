/* 
 * File:   item.h
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */
#ifndef item_H
#define item_H

#define bool int /*Define tipo booleano*/
#define TRUE 1
#define FALSE 0
#define ERRO -32000


typedef         /*Tipo ITEM da avl*/
struct item_ 
{
    char *nome; // palavra armazenada
    int chave;  // prioridade
}
ITEM;


/* recebe uma string, e aloca na memória */
char * alocaPalavra (char * pal);

/* libera uma palavra do heap */
void liberaPalavra(char ** pal);



#endif