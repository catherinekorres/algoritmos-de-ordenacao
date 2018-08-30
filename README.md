# Algoritmos de Ordenação
Trabalho apresentado para disciplina Algoritmos e Estruturas de Dados, pelo curso de Ciência da Computação da UNIOESTE em agosto de 2018

# Especificações do trabalho

Fazer um programa em linguagem C para implementar os seguintes algoritmos de ordenação:
- Ordenação por Inserção (Insertion Sort)
- Ordenação por Seleção (Selection Sort)
- Quicksort
- Mergesort
- Heapsort

O programa deve ter dois modos de funcionamento:
1. ordenação de uma entrada usando um algoritmo específico gerando um arquivo de saída
2. comparação entre todos os algoritmos de ordenação através da medida de tempo da execução de
ordenação gerando um relatório
Em ambos modos de funcionamento, as informaçães devem ser passadas via linha de comando para
o programa, devendo ser capaz de ordenar números inteiros e cadeias de caracteres. No caso de inteiros,
deve ser informada a quantidade de números, devendo eles serem gerados aleatoriamente. No caso de
cadeias de caracteres deve ser passado um arquito texto como entrada, sendo os caracteres espaço e ENTER
interpretados como separadores de cadeias.

Abaixo, seguem exemplos de chamadas do programa:

$> ordenacao N 2000 quicksort saida.txt

Devem ser gerados 2000 números aleatórios que serão ordenados usando o algoritmo quicksort e o
resultado será gravado no arquivo saida.txt


$> ordenacao C arqentrada.txt mergesort saida.txt

O conteúdo do arquivo arqentrada.txt será ordenado usando o algoritmo mergesort e o resultado
será gravado no arquivo saida.txt


$> ordenacao N 5000

Devem ser gerados 5000 números aleatórios que serão ordenados por todos os algoritmos de ordenação
para efeito de comparação, cujos tempos de execução serão apresentados em um relatório na console.


$> ordenacao C arqentrada.txt

O conteúdo do arquivo arqentrada.txt será ordenado por todos os algoritmos de ordenação para
efeito de comparação, cujos tempos de execução serão apresentados em um relatório no console.
