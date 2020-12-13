/* 
 * File:   main.c
 * Author: Francisco Rosa Dias de Miranda e
 *          Hiago Vinicius Americo
 */

#include "item.h"
#include "avl.h"
#include "heap.h"


int main()
{
    /*  opn = opção selecionada pelo usuario
        nops = numero de operaçoes requisitadas
        pal: chave a ser buscada 
        mov: ITEM para auxiliar no chamado as funçoes  */
    int opn, i = 0, n_dicionario=1, palavras_frequentes;
    char nops[30], pal[50];
    ITEM mov;
    ARV * TR = NULL;
    ARV * DICIONARIOS[3] = {NULL, NULL, NULL}, ** dic = NULL; //armazena o endereco do dicionario a ser utilizado
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
            criou = FALSE;
            

                // CRIA UM DICIONARIO DE ID i +1.
                for (i = 0; i < 3 && !criou; i++)
                {
                    if (DICIONARIOS[i] == NULL)
                    {
                        DICIONARIOS[i] = avl_criar();
                        printf("DICIONARIO %d CRIADO\n", i+1);
                        criou = TRUE;
                        dic = &DICIONARIOS[i];
                    }
                }
                if (criou)
                {
                    while(1)
                    {
                        scanf (" %s",pal);

                        if(strcmp(pal,"#") == 0) break;

                        mov.nome = pal;

                        avl_inserir(dic, mov);
                    }
                
                }
                else
                    printf("IMPOSSIVEL CRIAR\n"); 
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
                    dic = &DICIONARIOS[n_dicionario-1];

                while(1)
                    {                      
                        scanf (" %s", nops);
                        if(strcmp(nops,"#") == 0) break;
                        else
                        {                       
                            scanf (" %s", pal);
                            mov.nome = pal;
                            if(atoi(nops) == 1)
                            {
                                if(avl_buscar(*dic,mov) == NULL)
                                {
                                    mov.nome = pal;
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
                                else 
                                    printf ("%s INEXISTENTE EM %d\n",mov.nome,n_dicionario);
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
                    dic = &DICIONARIOS[n_dicionario-1];
                    avl_apagar(dic);
                    dic = NULL;
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
                    dic = &DICIONARIOS[n_dicionario-1];
                
                if (TR == NULL)
                    TR = avl_criar();
                else break; 
                F = criar(avl_tamanho(*dic));
                // le as palavras
                while(1)
                {
                    scanf (" %s",pal);

                    if(strcmp(pal,"#") == 0) break;                 
                    // insere as palavras e contabiliza a frequencia das repetidas
                    mov.nome = pal;
                    // se nao encontrar no dicionario, insere como palavra unica
                    if( avl_buscar(*dic, mov) == NULL)
                        avl_inserir(&TR, mov);
                    else
                        fila_inserir(F,mov);

                }
                
                // organizar TR por ordem de frequencia
                // imprimir os termos de acordo com ela até que 
                // palavras_frequentes termos sejam impressos
                avl_imprimir(TR);
                if( palavras_frequentes <= 0)
                {
                    printf("IMPOSSIVEL INFORMAR %d PALAVRAS MAIS FREQUENTES", palavras_frequentes);
                    break;
                }
                else
                imprimir(F, palavras_frequentes);

                excluir(&F);
                avl_apagar(&TR);

                break;
            
            case 0: // encerra a aplicacão
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