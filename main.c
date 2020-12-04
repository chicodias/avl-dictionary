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
        palavras_frequentes:  quantidade de palavras frequentes
        */
    int opn, nops, n_dicionario, adicionar_remover, palavras_frequentes, chave, i = 0;
    char mov[TAM_MAX], *p;
    AVL * TR = NULL, * DICIONARIOS[3] = {NULL, NULL, NULL}, * dic;
    bool criou;

    while (1)
    {
        //printf ("Escolha a operacao:\n");
        scanf ("%d", &opn);
        
        switch (opn)
        {
            case 1:
            // criar dicionario
            // não criar uma lista sem antes apagar uma já existente, perdendo acesso a anterior
            criou = FALSE;

            // CRIA UM DICIONARIO DE ID i +1.
            for (int i = 0; i <= 3 && !criou; i++)
            {
                if (DICIONARIOS[i] == NULL)
                {
                    DICIONARIOS[i] = avl_criar();
                    printf("DICIONARIO %d CRIADO\n", i+1);
                    criou = TRUE;
                }
                if(i == 3){
                    printf("IMPOSSIVEL CRIAR\n");
                }
            }
            
            if (criou)
            {
                while (1){
                    
                    fgets(mov, TAM_MAX, stdin);

                    if (mov == '#')
                        break;

                    avl_inserir(DICIONARIOS[i+1], mov);
                }
            }
                
                break;

            case 2:
            // atualizar dicionario
            
                scanf("%d", &n_dicionario);
                dic = DICIONARIOS[n_dicionario];
                if (n_dicionario > 3 || n_dicionario < 1 || DICIONARIOS[n_dicionario] == NULL)
                {
                    printf("DICIONARIO %d INEXISTENTE\n",  n_dicionario);
                }
                else
                {        
                    while (1)
                    {
                        scanf("%d", &adicionar_remover);

                        if (adicionar_remover == '#')
                            break;

                        fgets(mov, TAM_MAX, stdin);

                        if(adicionar_remover) // adicionar a palavra no dicionário
                            avl_inserir(dic, mov);

                        else // remover a palavra no dicionário 
                            avl_remover(dic, mov);
                    }
                }
            case 3:
            // apagar dicionario
                scanf("%d", &n_dicionario); // lendo a operação e o numero do dicionaro que vai apagar

                dic = DICIONARIOS[n_dicionario];
                if(n_dicionario > 3 || n_dicionario < 1 || DICIONARIOS[n_dicionario] == NULL) // verifica a existência do dicionário
                {
                    printf("DICIONARIO %d INEXISTENTE\n", n_dicionario);
                }

                else
                {
                    avl_apagar(dic);
                    printf("DICIONARIO %d APAGADO", n_dicionario);
                }
                break;

            case 4:
            // verificar texto
                scanf("%d %d", &n_dicionario, &palavras_frequentes); //lendo o id do dicionario e quantas palavras mais frequentes aparecem

                if( palavras_frequentes <= 0)
                    printf("IMPOSSIVEL INFORMAR %d PALAVRAS MAIS FREQUENTES", palavras_frequentes);


                if(n_dicionario > 3 || n_dicionario < 1 || DICIONARIOS[n_dicionario] == NULL) // verifica a existência do dicionário
                {
                    printf("DICIONARIO %d INEXISTENTE\n", n_dicionario);
                }
                else
                {
                    while(1)
                    {
                        avl_inserir(AVL *T, ITEM item);
                    }
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