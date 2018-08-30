#ifndef INTS_H
#define INTS_H

#include <time.h>
#include <stdlib.h>
#include <limits.h>

#include "control.h"

// Funcao de controle para os algoritmos de ordenacao com inteiros
// Pre-condicao: entrada de estrutura com dados de controle
// Pos-condicao: cria um vetor de inteiros aleatorios, realiza a chamada do(s) algoritmo(s) e libera o vetor ao final
void intControl(Control *control);

// Armazena um vetor de inteiros em um arquivo
// Pre-condicao: vetor de inteiros e estrutura com dados de controle
// Pos-condicao: arquivo contendo o vetor de inteiros
void writeInt(int *vector, Control* control);

// Gera um vetor de inteiros aleatorios
// Pre-condicao: entrada de estrutura com dados de controle
// Pos-condicao: retorna um vetor de inteiro aleatorios
int *newRandomVector(Control *control);

// Realiza a chamada dos metodos de ordenacao de inteiros
// Pre-condicao: vetor de inteiros e estrutura com dados de controle
// Pos-condicao: metodo de ordenacao eh chamado
void selectSortInt(Control *control, int *vector);

// Realiza a chamada de todos os metodos de ordenacao de inteiros e imprime seus tempos de execucao
// Pre-condicao: vetor de inteiros e estrutura com dados de controle
// Pos-condicao: todos os metodos de ordenacao sao chamados e eh imprimido o tempo de execucao de cada um
void allSortsInt(Control *control,int *vector);

// Metodo de ordenacao Insertion Sort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double insertionSortInt(int *vector, int size);

// Metodo de ordenacao Selection Sort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double selectionSortInt(int *vet, int size);

// Metodo de ordenacao Quicksort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double quickSortInt(int *vector, int size);

// Funcao auxiliar que executa o Quicksort para inteiros
// Pre-condicao: vetor de inteiros, posicao inicial do vetor (esquerda, 'e') e posicao final do vetor (direita, 'd')
// Pos-condicao: ordena um vetor de inteiros recursivamente
void quickSortIntAux(int *vector, int e, int d);

// Seleciona um pivo e ordena os elementos em relacao e este pivo
// Pre-condicao: vetor de inteiros, posicao inicial do vetor (esquerda, 'e') e posicao final do vetor (direita, 'd')
// Pos-condicao: ordena o vetor em relacao ao pivo:
//								elementos menores que o pivo vao para sua esquerda
//								elementos maiores que o pivo vao para sua direita
// Apos ordenacao, retorna a nova posicao do ultimo pivo
int partitionInt(int *vector, int e, int d);

// Metodo de ordenacao Mergesort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double mergeSortInt(int *vector, int size);

// Funcao auxiliar que executa o Mergesort para inteiros
// Pre-condicao: vetor de inteiros, posicao inicial do vetor (esquerda, 'e') e posicao final do vetor (direita, 'd')
// Pos-condicao: ordena um vetor de inteiros recursivamente
void mergeSortIntAux(int *vector, int e, int d);

// Ordena um vetor em relacao a sua metade esquerda e direita, intercalando (ordenando) seus elementos no processo
// Pre-condicao: vetor de inteiros, posicao inicial do vetor (esquerda, 'e'), posicao da metade ('m') do vetor e posicao final do vetor (direita, 'd')
// Pos-condicao: retorna o vetor de inteiros ordenado
void IntercalaInt(int *vector, int e, int m, int d);

// Metodo de ordenacao Heapsort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double heapSortInt(int *vector, int size);

#endif
