/* 
 * File:   main.c
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */

#include <stdio.h>
#include "avl.h"
#include <string.h>

int main()
{
    /* opn = opção selecionada pelo usuario
        nops = numero de operaçoes requisitadas
        chave: chave a ser buscada 
        mov: palavra retornada pela busca  */
    int opn, nops, i = 0, n_dicionario, palavras_frequentes;
    ITEM mov;
    ARV * TR = NULL;
    ARV * DICIONARIOS[3] = {NULL, NULL, NULL}, ** dic; //armazena o endereco do dicionario a ser utililado
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

                        printf ("%d\n", avl_inserir(dic, mov));
                    }
                
                }
                    
                break;

            case 2:
                // atualizar dicionario
                scanf("%d", &n_dicionario);
                
                if (n_dicionario > 3 || n_dicionario < 1 || DICIONARIOS[n_dicionario-1] == NULL)
                    printf("DICIONARIO %d INEXISTENTE\n",  n_dicionario);
                else if(DICIONARIOS[n_dicionario-1] != NULL)
                    *dic = DICIONARIOS[n_dicionario-1];

                while(1)
                    {
                        scanf (" %s",mov.nome);

                        if(strcmp(mov.nome,"#") == 0) break;

                        else
                        {                           
                            scanf ("%d %s", &nops, mov.nome);

                            printf("%d %s\n", nops, mov.nome);
                        
                            if(nops == 1)
                                printf ("%d\n", avl_inserir(dic, mov));

                            else if (nops == 0)
                                printf ("%d\n",avl_remover(dic, mov));                        
                            else
                                printf("Opcao invalida.\n");

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
                    printf("IMPOSSIVEL INFORMAR %d PALAVRAS MAIS FREQUENTES", palavras_frequentes);

                if (TR == NULL)
                    TR = avl_criar();
                else break; // o que é pra fazer?
                
                // le as palavras
                while(1)
                {
                    scanf (" %s",mov.nome);

                    if(strcmp(mov.nome,"#") == 0) break;                 

                    avl_inserir(dic, mov);
                }
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