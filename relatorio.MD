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

Este relatório tem o intuito de explicar os TAD's utilizados em nosso código. Demonstraremos também informações sobre nossa implementação em linguagem em C na documentação do código.

Utilizamos a estrutura Árvore AVL(Adelson-Velskii e ) (..)

- Quais  Estruturas  de  Dados  e  respectivas  abordagens  de  implementaçãoforam escolhidas para modelar o problema? Justifique baseado na solução implementada.

- Quais  vantagens  e  limitações  as  estruturas/implementações escolhidas apresentam?
- Explique claramente e detalhadamente a lógica utilizada para resolver o problema. Como   as   estruturas   (e   respectivas   operações   básicas)   são   utilizadas para representar (e resolver) o problema?

## Parte 2 – Implementação (60% da nota final)
Esta   parte   avalia   a   estratégia   de   implementação   utilizada.   Por   isso,   serão   considerados    aspectos    como    organização,    corretude, eficiência do    código    e    documentação interna.

## Parte 3 - Análise de Eficiência e Relatório
### Complexidade das estruturas e operações envolvidas

A **Árvore AVL** tem complexidade $O(log n)$ para todas as operações e ocupa espaço $n$, onde $n$ é o número de nós da árvore.




- Medir tempo de execução
- gráfico de escalabilidade
- análise de complexidade utilizando O
- explicar o resultado, relacionando o algoritmo utilizado com a complexidade computacional do
algoritmo implementado. Crescimento do tempo, melhor e pior casos.