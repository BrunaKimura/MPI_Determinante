# Cálculo da Determinante usando MPI
<b><div style="text-align: right">
Bruna Mayumi Kimura</div>
<div style="text-align: right">
Engenharia de Computação - Insper
</div></b>

-------------------------------

## Introdução

Este projeto consiste em calcular a determinante de uma determinada matriz utilizando memória distribuída. Para tanto foi utilizado a função MPI. Além disso, fazer uma análise de desempenho sobre os modelos.

## Cálculo da Determinante

O código com apenas o cálculo da determinante pode ser encontrado no arquivo `Tarefa.cpp`. Nele é possível ver a implementação do algoritmo em C++.

O cálcula da determinante foi feito utilizando o teorema de Laplace. Este cálculo consiste em reduzir a matriz até um tamanho que seja possível calcular a determinantes com outros meios. Para tanto, é necessário escolher uma linha que será eliminada e fazer o cálculo segundo a fórmula:

\sum i

Aij = (-1) i + j. Dij

onde:



No caso deste algoritmo o cálculo foi feito utilizando recursão para diminuir a matriz até chegar no caso base, uma matriz de 1x1. Neste caso, a determinante é o próprio valor da matriz. A cada passo da recursão a matriz é reescrita para um tamanho menor, ou seja, de 5x5 é reduzida para 4x4, em seguida para 3x3, sucessivamente até chegar ao caso base. O retorno da função é utilizada na fórmula acima e assim, somando os resultados tem-se a determinante.

## Distribuindo na memória

Para a distribuição da memória, utilizou-se o MPI. A implementação do algoritmo foi escrita em C++ e pode ser encontrado no arquivo `Tarefa_MPI.cpp`.

## Modo de uso

## Desempenho

## Conclusão

## Melhorias futuras