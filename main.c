/* 
 * File:   main.c
 * Author: Francisco Rosa Dias de Miranda
 */

#include <stdio.h>
#include "avl.h"

int main()
{
    /* opn = opção selecionada pelo usuario
        nops = numero de operaçoes requisitadas
        chave: chave a ser buscada 
        mov: filme retornado pela busca  */
    int opn, nops, chave, i = 0;
    ITEM mov, *p;
    ARV * TR = NULL;

    while (1)
    {
        //printf ("Escolha a operacao:\n");
        scanf ("%d", &opn);
        
        switch (opn)
        {
            case 1:

            // não criar uma lista sem antes apagar uma já existente, perdendo acesso a anterior
                if (TR == NULL)
                {
                    TR = abb_criar();
                    printf("1\n");
                }
                else
                {
                    abb_apagar (&TR);
                    TR = abb_criar();
                    printf("1\n");
                }
                
                break;

            case 2:
                abb_apagar (&TR);
                break;

            case 3:
                //printf("Numero de Insercoes:\n");
                scanf ("%d", &nops);
                for (i = 0; i < nops; ++i)
                {
                    scanf ("%d %s",&mov.chave, mov.nome);

                    printf ("%d\n", abb_inserir(TR, mov));
                }
                break;

            case 4:
                //printf ("Numero de remocoes:\n");
                scanf ("%d", &nops);
                for (i = 0; i < nops; ++i)
                {
                    scanf ("%d", &chave);
                    printf ("%d\n", abb_remover(TR, chave));
                }
                break;

            case 5:
                //printf ("Numero de buscas:\n");
                scanf ("%d", &nops);
                for (i = 0; i < nops; ++i)
                {
                    scanf ("%d", &chave);
                    p = abb_buscar (TR, chave);
                    if (p != NULL)
                        printf ("%s\n", p->nome);
                    else
                        printf ("%d\n", ERRO);
                }
                break;

            case 6:
                if(TR != NULL)
                    abb_imprimir (TR->raiz);
                else
                    printf ("%d\n", ERRO);
                break;

            case 7:
                printf ("%d\n", abb_altura (TR));
                break;

            case 0:
                abb_apagar (&TR);
                return 0;
                break;

            default:
                return 1;
                break;
        }
    }
}