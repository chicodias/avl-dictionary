---
  output: pdf_document
---

# Relatório do Projeto 2: Verificador de palavras
### SCC0223 - Estruturas de Dados I

##### Hiago Américo, nUSP: 11218469. Francisco Dias, nUSP: 4402962.

**Objetivo:** Este relatório tem como objetivo explicar os algoritmos e estruturas de dados utilizados na criação de um programa para avaliar trechos utilizando dicionários pré-fornecidos, retornando as palavras do trecho que não estão contidas no dicionário e as palavras mais frequentes do trecho que são palavras-chave.

## Descrição do problema

A classificação de conteúdo textual é um dos grandes desafios atuais da área conhecida como processamento de linguagem natural (PLN). Neste trabalho, entendemos como **classificação** a técnica de identificar um conjunto de significados ou conceitos de um texto.

Uma das maneiras de criar algoritmos que sejam capazes de reconhecer o conteúdo de um texto, é filtrando as palavras mais pertinentes ao domínio do tema objetivo, e excluindo palavras "comuns" da linguagem, ou seja, que não agreguem significado semântico para a análise. Dessa forma, o assunto pode ser indicado pela alta presença de palavras relevantes que não façam parte de um dicionário pré-estabelecido.

O programa criado tem como principal objetivo verificar trechos de texto a partir de um dicionário e retornar as palavras não encontradas e as $n$ palavras do dicionário mais frequentes no trecho, com suas respectivas frequências.

## Modelagem

Dentre as cinco opções apresentadas ao usuário, temos:

- **1**: Criar dicionário
  - Um dicionário é criado, se for possível,
  - O usuário digita as palavras a serem adicionadas ao dicionário.
- **2**: Atualizar dicionário
  - O usuário informa o dicionário a ser alterado,
  - É informado (1) para uma inserção ou (0) para uma remoção
  - A palavra é atualizada no dicionário.
- **3**: Apagar dicionário
  - É informado a ID de um dicionário, em seguida removido.
- **4**: Verificar texto
  - É informada a ID de um dicionário e um inteiro inteiro $n$ de palavras mais frequentes a ser retornado,
  - O trecho é informado,
  - O programa retorna as palavras não contidas no dicionário e as $n$ mais frequentes, em ordem alfabética e de frequência.
- **5**: Encerrar aplicação
  - Todas as estruturas são excluídas da memória e a aplicação é finalizada.

O final da entrada é indicado pelo caractere '#'. Dessa forma, não é sabido pelo programador o tamanho da entrada em pré-execução. Assim, é mandatório a utilização de TAD's com alocacão dinâmica de memória.

Para escolher qual estrutura de dados será mais adequada para resolver o problema, primeiramente pensemos nas primitivas que estarão envolvidas em tempo de execução.

Na opção **1**, temos, além da inicialização de um dicionário que abrigará aos termos, a *inserção* de um número arbitrário destes pelo usuário, o que pode ocorrer em ordem alfabética, sendo que não podem haver palavras em duplicidade. Da mesma forma, a opção **2** também precisará fazer uma *busca* para a *inserção*, assim como também para uma eventual *remoção*. Na opção **3**, é feita a *exclusão* de um dos dicionários criados pelo usuário.

Já na opção 4, fazemos a *inserção* do trecho a ser analizado, *buscamos* as palavras que estejam em nosso dicionário, contabilizamos a *frequência* dessas, *imprimimos* as palavras que não foram encontradas no dicionário


Como um pré-requisito para a criação de nosso programa era a necessidade da utilização de **estruturas de dados não lineares**, escolhemos modelar o problema através a adoção de **árvores AVL**. Uma **árvore AVL** (assim chamada devido ao nome de seus inventores, Adelson-Velsky and Landis) é uma árvore binária de busca auto-balaceada.

Toda **árvore AVL** é balanceada, ou seja, sua altura é $O(logn)$. A vantagem do balanceamento é possibilitar que a busca seja de complexidade $O(logn)$. Com isso, as operações de inserção e remoção devem possuir custo similar. No caso da **árvore AVL**, a inserção e remoção têm custo $O(logn)$.

Como temos alguns dados mais importante do que outros, utilizamos também uma **Fila de Prioridade** para o armazenamento das palavras. Nessa fila, garantimos que uns objetos com mais importância são recuperados em primeiro lugar. Com isso, temos que os objetos com menos prioridade nunca é removido na fila. 


## Implementação 

Apresentaremos as funções utilizadas na implementação do código e a documentação das mesmas. Como utilizamos duas estruturas de dados (Árvore AVL e Fila de Prioridades Decrescente), teremos então dois arquivos TAD's sendo eles:

- **heap.h**
  - *FILA_PRIOR criar*: criação da fila;
  - *int cheia*: recebe uma fila, verifica se ela está cheia e retorna 1 caso esteja ou 0 caso contrário;
  - *int vazia*: recebe uma fila, verifica se ela está vazia e retorna 1 caso esteja ou 0 caso contrário;
  - *int inserir*: recebe uma fila e um item para inserir;
  - *ITEM remover*: remove e retorna o item com maior (menor) prioridade da fila.

- **avl.h**
  - *ARV avl_criar*: criação da AVL e retorno do seu ponteiro;
  - *void avl_apagar*: apaga todo o conteudo da lista e desaloca memória;
  - *bool avl_inserir*: recebe uma AVL e um item para inseri-lo na árvore e retorna 1 caso consiga ou 0 caso contrário;
  - *bool avl_remover*: recebe uma AVL e um item para removê-lo, retorna 1 caso consiga ou 0 caso contrário;
  - *ITEM avl_buscar*: recebe uma AVL e uma chave para buscar um elemento na árvore, retornará caso exista ou retorna ERRO caso não exista;
  - *void avl_imprimir*: recebe uma AVL para imprimi-lá ordenamente;
  - *int avl_altura*: recebe uma AVL e retorna a altura da mesma;
  - *bool avl_vazia*: recebe uma AVL e retorna 1 caso esteja vazia, 0 caso contrário ou ERRO caso não tenha sido alocada.



