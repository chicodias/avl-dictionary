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
        mov: filme retornado pela busca
        m_dicionario: numero do dicionario existente
        adicionar_remover: adicionar ou remover as palavras (0 ou 1)  */
    int opn, nops, n_dicionario, adicionar_remover, chave, i = 0;
    ITEM mov, *p;
    ARV * TR = NULL;

    while (1)
    {
        //printf ("Escolha a operacao:\n");
        scanf ("%d", &opn);
        
        switch (opn)
        {
            case 1:
            // criar dicionario
            // não criar uma lista sem antes apagar uma já existente, perdendo acesso a anterior
                if (TR == NULL)
                {
                    TR = avl_criar();
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
            // atualizar dicionario
                scanf("%d", &n_dicionario);

                // if(n_dicionario ) 
                
                do{
                    scanf("%d %s", &adicionar_remover, mov.nome);

                    if(adicionar_remover == 1) // adicionar a palavra no dicionário
                    { 
                        avl_inserir(AVL *T, ITEM item);

                    }

                    if(adicionar_remover == 0) // remover a palavra no dicionário 
                    {
                        avl_remover(AVL *T, ITEM item);
                    
                    }


                }while(adicionar_remover != '#');
            case 3:
            // apagar dicionario
                //printf("Numero de Insercoes:\n");
                scanf ("%d", &nops);
                for (i = 0; i < nops; ++i)
                {
                    scanf ("%d %s",&mov.chave, mov.nome);

                    printf ("%d\n", avl_inserir(TR, mov));
                }
                break;

            case 4:
            // verificar texto
                //printf ("Numero de remocoes:\n");
                scanf ("%d", &nops);
                for (i = 0; i < nops; ++i)
                {
                    scanf ("%d", &chave);
                    printf ("%d\n", avl_remover(TR, chave));
                }
                break;

            case 0:
            // sair da aplicacao
                avl_apagar (&TR);
                return 0;
                break;

            default:
                return 1;
                break;
        }
    }
}