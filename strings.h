#ifndef STRINGS_H
#define STRINGS_H

#include <time.h>
#include <stdlib.h>
#include "control.h"

// Funcao de controle para os algoritmos de ordenacao com string
// Pre-condicao: entrada de estrutura com dados de controle
// Pos-condicao: carrega um vetor de strings, realiza a chamada do(s) algoritmo(s) e libera o vetor ao final
void strControl(Control *control);

// Armazena um vetor de strings em um arquivo
// Pre-condicao: vetor de strings e estrutura com dados de controle
// Pos-condicao: arquivo contendo o vetor de strings
void writeStr(char** vector, Control* control);

// Carrega um vetor de strings de um arquivo
// Pre-condicao: entrada de estrutura com dados de controle
// Pos-condicao: retorna um vetor de strings
char **strParse(Control* input);

// Realiza a chamada dos metodos de ordenacao de strings
// Pre-condicao: vetor de strings e estrutura com dados de controle
// Pos-condicao: metodo de ordenacao eh chamado
void selectSortStr(Control *control, char** vector);

// Realiza a chamada de todos os metodos de ordenacao de strings e imprime seus tempos de execucao
// Pre-condicao: vetor de strings e estrutura com dados de controle
// Pos-condicao: todos os metodos de ordenacao sao chamados e eh imprimido o tempo de execucao de cada um
void allSortsStr(Control *control,char** vector);

// Metodo de ordenacao Insertion Sort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double insertionSortStr(char** vector, int size);

// Metodo de ordenacao Selection Sort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double selectionSortStr(char **vet, int size);

// Cria um ponteiro de ponteiros para copiar o conteudo de um vetor de strings
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: retorna a copia do vetor de strings
char** copyStringVector(char **vector, int size);

// Desaloca um ponteiro de ponteiros de strings
// Pre-condicao: ponteiro de ponteiros de strings e tamanho do ponteiro
// Pos-condicao: estrutura de ponteiro de ponteiros desalocada
void kill(char **str, int max);

// Metodo de ordenacao Quicksort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double quickSortStr(char **vector, int size);

// Funcao auxiliar que executa o Quicksort para strings
// Pre-condicao: vetor de strings, posicao inicial do vetor (low) e posicao final do vetor (high)
// Pos-condicao: ordena um vetor de strings recursivamente
void quickSortStrAux(char **arr, int low, int high);

// Seleciona um pivo e ordena os elementos em relacao e este pivo
// Pre-condicao: vetor de strings, posicao inicial do vetor (low) e posicao final do vetor (high)
// Pos-condicao: ordena o vetor em relacao ao pivo:
//								elementos menores que o pivo vao para sua esquerda
//								elementos maiores que o pivo vao para sua direita
// Apos ordenacao, retorna a nova posicao do ultimo pivo
int partitionStr(char **arr, int low, int high);

// Metodo de ordenacao Mergesort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double mergeSortStr(char **vet, int size);

// Funcao auxiliar que executa o Mergesort para strings
// Pre-condicao: vetor de strings, posicao inicial do vetor (esquerda, 'e') e posicao final do vetor (direita, 'd')
// Pos-condicao: ordena um vetor de strings recursivamente
void mergeSortStrAux(char **vet,int e, int d);

// Ordena um vetor em relacao a sua metade esquerda e direita, intercalando (ordenando) seus elementos no processo
// Pre-condicao: vetor de strings, posicao inicial do vetor (esquerda, 'e'), posicao da metade ('m') do vetor e posicao final do vetor (direita, 'd')
// Pos-condicao: retorna o vetor de strings ordenado
void IntercalaStr(char **vet,int e, int m, int d);

// Metodo de ordenacao Heapsort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double heapSortStr(char** vector, int size);

#endif
