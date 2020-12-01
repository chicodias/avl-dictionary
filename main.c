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
    int opn, nops, n_dicionario, chave, i = 0;
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
            // atualizar dicionario
                scanf("%d", &n_dicionario);
                switch(opn)
                {
                    // criar dicionario novamente
                    case 1:
                    if(TR == NULL)
                    {
                        TR = abb_criar();
                        printf("1\n");
                    }
                    else{
                        abb_apagar (&TR);
                        TR = abb_criar();
                        printf("1\n");
                    }
                    /* duvida, vai atualizar de novo (?) Recursivo talvez
                    case 2:
                    */

                    case 3:
                    // apagar dicionário
                        for(i = 0; i < nops; ++i)
                        {
                            scanf("%d %s", &mov.chave, mov.nome);

                            printf("%d\n", abb_inserir(TR, mov));
                        }
                        break;

                    case 4:
                    // verificar texto
                        scanf("%d", &nops);
                        for(i = 0; i < nops; ++i)
                        {
                            scanf("%d", &chave);
                            printf("%d\n", abb_remover(TR, chave));
                        }
                        break;

                    case 0:
                    // sair da aplicação
                        abb_apagar(&TR);
                        return 0;
                        break;

                    default:
                        return 1;
                        break;
                }

            case 3:
            // apagar dicionario
                //printf("Numero de Insercoes:\n");
                scanf ("%d", &nops);
                for (i = 0; i < nops; ++i)
                {
                    scanf ("%d %s",&mov.chave, mov.nome);

                    printf ("%d\n", abb_inserir(TR, mov));
                }
                break;

            case 4:
            // verificar texto
                //printf ("Numero de remocoes:\n");
                scanf ("%d", &nops);
                for (i = 0; i < nops; ++i)
                {
                    scanf ("%d", &chave);
                    printf ("%d\n", abb_remover(TR, chave));
                }
                break;

            case 0:
            // sair da aplicacao
                abb_apagar (&TR);
                return 0;
                break;

            default:
                return 1;
                break;
        }
    }
}