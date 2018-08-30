#include "control.h"

// Selecao do algoritmo de ordenacao
// Pre-condicao: entrada de string informando o algoritmo
// Pos-condicao: retorna o caractere correspondente ao algoritmo. caso nqo encontre correspondencia, recebe A (all), que equivale a todos os algoritmos.
char sortParse(char *str){
	if(!strcmp("insertion", str))return 'I';
	if(!strcmp("selection", str))return 'S';
	if(!strcmp("quicksort", str))return 'Q';
	if(!strcmp("mergesort", str))return 'M';
	if(!strcmp("heapsort", str)) return 'H';
	return 'A';
}

// Parser para analisar as instrucoes passadas via linha de comando
// Pre-condicao: argumentos via linha de comando
// Pos-condicao: retorna uma estrutura que contem  os dados de controle
Control *parseControl(int argc, char *argv[]){
	Control *control = (Control*)malloc(sizeof(Control));
	control->type = *argv[1];   // Leitura do argumento inserido via linha de comando,
                              // informando o tipo de dados a ser ordenado

	if (control->type == 'N')   // Checa se o tipo eh inteiro
	{
		control->input[0] = '\0';       // Nao ha input no caso de inteiros
		control->num = atoi(argv[2]);   // Recebe a quantidade de numeros a ser gerados aleatoriamente

	} else if(control->type == 'C'){      // Checa se o tipo eh caractere
		strcpy(control->input, argv[2]);    // Recebe o nome do arquivo que contem os dados
		control->num = 0;                   // Zera o contador de numeros, que nao sera utilizado
	}

	if(argc > 3){   // Checa se existe mais alguma instrucao
		control->sortType = sortParse(argv[3]);         // Armazena qual algoritmo de ordenacao sera utilizado
		if(argc > 4) strcpy(control->output, argv[4]);  // Armazena o nome do arquivo output, caso tenha sido passado
		else control->output[0] = '\0';
	} else{
		control->sortType = 'A';    // Caso nao exista outra instrucao, todos os algoritmos serao utilizados
		control->output[0] = '\0';  // E nao havera output
	}
	return control;
}

// Imprime a estrutura de controle
// Pre-condicao: estrutura de controle
// Pos-condicao: estrutura de controle imprimida na tela
void printControl(Control *control){
	printf("type = %c\n",control->type );
	printf("num = %d\n",control->num );
	printf("sorttype = %c\n",control->sortType );
	printf("input = %s\n",control->input );
	printf("output = %s\n",control->output );
}
