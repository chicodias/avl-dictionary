/* 
 * File:   main.c
 * Author: Francisco Rosa Dias de Miranda e Hiago Vinicius Americo
 */

#include <stdio.h>
#include "avl.h"
#include "dicionario.h"

int main()
{
    /* opn = opção selecionada pelo usuario
        nops = numero de operaçoes requisitadas
        chave: chave a ser buscada 
        mov: filme utilizado pela busca ou inserção
        m_dicionario: numero do dicionario existente
        adicionar_remover: adicionar ou remover as palavras (0 ou 1)  
        DICS: vetor que armazena o endereço dos tres dicionarios
        */
    int opn, nops, n_dicionario, adicionar_remover, chave, i = 0;
    char mov[TAM_MAX], *p;
    AVL * TR = NULL, * DICIONARIOS[3] = {NULL, NULL, NULL}, * dic;

    while (1)
    {
        //printf ("Escolha a operacao:\n");
        scanf ("%d", &opn);
        
        switch (opn)
        {
            case 1:
            // criar dicionario
            // não criar uma lista sem antes apagar uma já existente, perdendo acesso a anterior
                if (DICIONARIOS[1] == NULL)
                {
                    DICIONARIOS[1] = avl_criar();
                    printf("1\n");
                }
                else
                {
                    avl_apagar (&TR);
                    DICIONARIOS[1] = avl_criar();
                    printf("1\n");
                }
                
                break;

            case 2:
            // atualizar dicionario
                scanf("%d", &n_dicionario);
                dic = DICIONARIOS[n_dicionario];
                // if(n_dicionario ) 
                
                while (1){
                    scanf("%d", &adicionar_remover);

                    if (adicionar_remover == '#')
                        break;

                    fgets(mov, TAM_MAX, stdin);

                    if(adicionar_remover == 1) // adicionar a palavra no dicionário
                    { 
                        dicionario_inserir(dic, mov);

                    }

                    if(adicionar_remover == 0) // remover a palavra no dicionário 
                    {
                        avl_remover(dic, mov);
                    
                    }


                }
            //case 3:
            // apagar dicionario
                //printf("Numero de Insercoes:\n");
                //scanf ("%d", &nops);
                //for (i = 0; i < nops; ++i)
                //{
                   // scanf ("%d %s",&mov.chave, mov.nome);

                   // printf ("%d\n", avl_inserir(TR, mov));
                //}
                //break;

            case 4:
            // verificar texto
                //printf ("Numero de remocoes:\n");
                scanf ("%d", &nops);
                for (i = 0; i < nops; ++i)
                {
                    scanf ("%d", &chave);
                 //   printf ("%d\n", avl_remover(TR, chave));
                }
                break;

            case 0:
            // sair da aplicacao
                avl_apagar (&DICIONARIOS[1]);
                return 0;
                break;

            default:
                return 1;
                break;
        }
    }
}