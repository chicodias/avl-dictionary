/* 
 * File:   main.c
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "heap.h"
#include <string.h>

int main()
{
    /* opn = opção selecionada pelo usuario
        nops = numero de operaçoes requisitadas
        chave: chave a ser buscada 
        mov: palavra retornada pela busca  */
    int opn, i = 0, n_dicionario, palavras_frequentes;
    char nops[50];
    ITEM mov;
    ARV * TR = NULL;
    ARV * DICIONARIOS[3] = {NULL, NULL, NULL}, ** dic; //armazena o endereco do dicionario a ser utililado
    bool criou;
    FILA_PRIOR * F;

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
                for (i = 0; i <= 3 && !criou; i++)
                {
                    if (DICIONARIOS[i] == NULL)
                    {
                        DICIONARIOS[i] = avl_criar();
                        printf("DICIONARIO %d CRIADO\n", i+1);
                        criou = TRUE;
                        dic = &DICIONARIOS[i];
                    }
                    if(i == 3){
                        printf("IMPOSSIVEL CRIAR\n");
                    }
                }
                if (criou)
                {
                    while(1)
                    {
                        scanf (" %s",mov.nome);

                        if(strcmp(mov.nome,"#") == 0) break;                 

                        avl_inserir(dic, mov);
                    }
                
                }
                    
                break;

            case 2:
                // atualizar dicionario
                scanf("%d", &n_dicionario);
                
                if (n_dicionario > 3 || n_dicionario < 1 || DICIONARIOS[n_dicionario-1] == NULL)
                {
                    printf("DICIONARIO %d INEXISTENTE\n",  n_dicionario);
                    break;
                }
                else if(DICIONARIOS[n_dicionario-1] != NULL)
                    *dic = DICIONARIOS[n_dicionario-1];

                while(1)
                    {                      
                        scanf (" %s", nops);
                        if(strcmp(nops,"#") == 0) break;
                        else
                        {                       
                            scanf (" %s", mov.nome);
                            if(atoi(nops) == 1)
                            {
                                if(avl_buscar(*dic,mov) == NULL)
                                {
                                    if(avl_inserir(dic, mov))
                                        printf ("%s INSERIDA EM %d\n",mov.nome,n_dicionario);
                                }
                                else
                                    printf ("%s JA EXISTE EM %d\n",mov.nome,n_dicionario);
                            }
                            else if (atoi(nops) == 0)
                            {
                                if (avl_remover(dic, mov))
                                   printf ("%s EXCLUIDA DE %d\n",mov.nome,n_dicionario);                        
                            }
                            

                        }

                    }                          
                
                break;

            case 3: 
            // apagar dicionario

                scanf("%d", &n_dicionario); // lendo a operação e o numero do dicionaro que vai apagar               
                if (n_dicionario > 3 || n_dicionario < 1 || DICIONARIOS[n_dicionario-1] == NULL)
                    printf("DICIONARIO %d INEXISTENTE\n",  n_dicionario);
                else if(DICIONARIOS[n_dicionario-1] != NULL)
                {
                    *dic = DICIONARIOS[n_dicionario-1];
                    avl_apagar(dic);
                    printf("DICIONARIO %d APAGADO\n", n_dicionario);
                
                }
                break;
            case 4:

                // verificar texto

               scanf("%d %d", &n_dicionario, &palavras_frequentes); //lendo o id do dicionario e quantas palavras mais frequentes aparecem
                
                if (n_dicionario > 3 || n_dicionario < 1 || DICIONARIOS[n_dicionario-1] == NULL){
                    printf("DICIONARIO %d INEXISTENTE\n",  n_dicionario);
                    break;
                }
                else if(DICIONARIOS[n_dicionario-1] != NULL)
                    *dic = DICIONARIOS[n_dicionario-1];
                
                if( palavras_frequentes <= 0)
                {
                    printf("IMPOSSIVEL INFORMAR %d PALAVRAS MAIS FREQUENTES", palavras_frequentes);
                    break;
                }
                if (TR == NULL)
                    TR = avl_criar();
                else break; 
                F = criar(avl_tamanho(*dic));
                // le as palavras
                while(1)
                {
                    scanf (" %s",mov.nome);

                    if(strcmp(mov.nome,"#") == 0) break;                 
                    // insere as palavras e contabiliza a frequencia das repetidas
                    
                    // se nao encontrar no dicionario, insere como palavra unica
                    if( avl_buscar(*dic, mov) == NULL)
                        avl_inserir(&TR, mov);
                    else
                        fila_inserir(F,mov);

                }

                avl_imprimir(TR);
                imprimir(F, palavras_frequentes);

                // organizar TR por ordem de frequencia
                // imprimir os termos de acordo com ela até que 
                // palavras_frequentes termos sejam impressos

                excluir(F);
                avl_apagar(&TR);
                break;
            
            case 0:
                for (i = 0; i < 3; i++)
                    if (DICIONARIOS[i] != NULL)
                        avl_apagar (&DICIONARIOS[i]);

                return 0;
                break;

            default:
                return 1;
                break;
        }
    }
}