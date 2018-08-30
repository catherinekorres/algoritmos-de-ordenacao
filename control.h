#ifndef CONTROL_H
#define CONTROL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define STRMAX 255

// Estrutura para armazenar dados de controle dos algoritmos de ordenacao
typedef struct Control
{
	char type;              // Define que tipo de dados sera ordenado
	int num;                // Armazena a quantidade de dados que serao ordenados
	char sortType;          // Define qual algoritmo de ordenacao sera utilizado
	char input[STRMAX];     // Dados de entrada
	char output[STRMAX];    // Dados de saida, reordenados
} Control;


// FUNCOES DE CONTROLE

// Selecao do algoritmo de ordenacao
// Pre-condicao: entrada de string informando o algoritmo
// Pos-condicao: retorna o caractere correspondente ao algoritmo. caso nao encontre correspondencia, recebe A (all), que equivale a todos os algoritmos.
char sortParse(char *str);

// Parser para analisar as instru?es passadas via linha de comando
// Pre-condicao: argumentos via linha de comando
// Pos-condicao: retorna uma estrutura que contem  os dados de controle
Control *parseControl(int argc, char *argv[]);

// Imprime a estrutura de controle
// Pre-condicao: estrutura de controle
// Pos-condicao: estrutura de controle imprimida na tela
void printControl(Control *control);


#endif
