#include "strings.h"

// Funcao de controle para os algoritmos de ordenacao com string
// Pre-condicao: entrada de estrutura com dados de controle
// Pos-condicao: carrega um vetor de strings, realiza a chamada do(s) algoritmo(s) e libera o vetor ao final
void strControl(Control *control){
	char **vector = strParse(control);		// Leitura do arquivo de input
	if(control->sortType != 'A'){
		selectSortStr(control, vector);			// Executa o algoritmo de ordenacao escolhido
		if(control->output){
			writeStr(vector, control);				// Armazena o resultado da ordenacao no arquivo output
		}
	} else allSortsStr(control, vector);	// Executa todos os algoritmos
	kill(vector, control->num);						// Libera o ponteiro de ponteiros
}

// Armazena um vetor de strings em um arquivo
// Pre-condicao: vetor de strings e estrutura com dados de controle
// Pos-condicao: arquivo contendo o vetor de strings
void writeStr(char **vector, Control* control){
	FILE *f = fopen(control->output, "w+");	// Abre o arquivo de output para leitura e escrita
	for (int i = 0; i < control->num; ++i)
	{
		fprintf(f, "%s\n",vector[i]);   // Grava uma string no arquivo
	}
	fclose(f);  // Fecha o arquivo de output
}

// Carrega um vetor de strings de um arquivo
// Pre-condicao: entrada de estrutura com dados de controle
// Pos-condicao: retorna um vetor de strings com o conteudo do arquivo
char **strParse(Control *control){
	FILE *f = fopen(control->input, "r");		// abre o arquivo de input para leitura
	int length = 1;
	char **buffer = malloc(sizeof(char*)*length);		// variavel para guardar o conteudo do arquivo
	int i;
	for(i= 0; !feof(f); i++){		// percorre o arquivo
		if(i == length){	// caso necessite mais elementos para armazenar do que o espaco disponivel
			length = length * 2 + 1;
			buffer = realloc(buffer, sizeof(char*)*length);	// aloca mais espaco
		}
		buffer[i] = malloc(sizeof(char)*STRMAX);
		fscanf(f, " %s ", buffer[i]);			// grava o conteudo
	}
	fclose(f);  // Fecha o arquivo de input
	control->num = i;
	return buffer;
}

// Realiza a chamada dos metodos de ordenacao de strings
// Pre-condicao: vetor de strings e estrutura com dados de controle
// Pos-condicao: metodo de ordenacao eh chamado
void selectSortStr(Control *control, char **vector){
	switch(control->sortType){
		case 'I':
			insertionSortStr(vector, control->num);		// Insertion Sort
			break;
		case 'S':
			selectionSortStr(vector, control->num);		// Selection Sort
			break;
		case 'Q':
			quickSortStr(vector, control->num);				// Quicksort
			break;
		case 'M':
			mergeSortStr(vector, control->num);				// Mergesort
			break;
		case 'H':
			heapSortStr(vector, control->num);				// Heapsort
			break;
		default : return;
	}
}

// Realiza a chamada de todos os metodos de ordenacao de strings e imprime seus tempos de execucao
// Pre-condicao: vetor de strings e estrutura com dados de controle
// Pos-condicao: todos os metodos de ordenacao sao chamados e eh imprimido o tempo de execucao de cada um
void allSortsStr(Control* control,char **vector){
	char **cpy = copyStringVector(vector, control->num);	// copia o vetor a ser ordenado para nao altera-lo
	printf("Insertion sort time: %g\n", insertionSortStr(cpy, control->num));		// Insertion Sort
	kill(cpy, control->num);	// desaloca a estrutura cpy

	cpy = copyStringVector(vector, control->num);
	printf("Selection sort time: %g\n", selectionSortStr(cpy, control->num));		// Selection Sort
	kill(cpy, control->num);

	cpy = copyStringVector(vector, control->num);
	printf("Quick sort time: %g\n", quickSortStr(cpy, control->num));						// Quicksort
	kill(cpy, control->num);

	cpy = copyStringVector(vector, control->num);
	printf("Merge sort time: %g\n", mergeSortStr(cpy, control->num));						// Mergesort
	kill(cpy, control->num);

	cpy = copyStringVector(vector, control->num);
	printf("Heap sort time: %g\n", heapSortStr(cpy, control->num));							// Heapsort
	kill(cpy, control->num);
}

// Metodo de ordenacao Insertion Sort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double insertionSortStr(char **vector, int size){
		clock_t time = clock();		// Armazena o tempo de execucao
		int i, j;
		char str[STRMAX];
		for (j = 1; j < size; j++) {
				strcpy(str, vector[j]);
				for (i = j-1; i >= 0 && strcmp(str, vector[i]) < 1; i--)
						strcpy(vector[i+1],vector[i]);
				strcpy(vector[i+1], str); 	// Coloca a string armazenado em str na posicao correta
		}
		return (double)(clock() - time)/CLOCKS_PER_SEC;
}

// Metodo de ordenacao Selection Sort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double selectionSortStr(char **vet, int size) {
		clock_t time = clock();		// Armazena o tempo de execucao
		for (int i = 0; i < size-1; i++) {
				int min = i;
				for (int j = i+1; j < size; j++) {
						if(strcmp(vet[j], vet[min]) < 1){
							min = j;
						}
				}
		char str[STRMAX];

		// Troca o elemento na posicao i com o da posicao min do vetor
		strcpy(str, vet[i]);
		strcpy(vet[i], vet[min]);
		strcpy(vet[min], str);
		}
		return (double)(clock() - time)/CLOCKS_PER_SEC;
}


// Cria um ponteiro de ponteiros para copiar o conteudo de um vetor de strings
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: retorna a copia do vetor de strings
char** copyStringVector(char **vector, int size){
	char **buffer = malloc(sizeof(char*)*size);	// cria o ponteiro de ponteiros de strings
	for (int i = 0; i < size; ++i)	// percorre o vetor de strings
	{
		buffer[i] = malloc(sizeof(char)*STRMAX ) ;
		strcpy( buffer[i], vector[i]);	// copia o conteudo do vetor
	}
	return buffer;
}

// Desaloca um ponteiro de ponteiros de strings
// Pre-condicao: ponteiro de ponteiros de strings e tamanho do ponteiro
// Pos-condicao: estrutura de ponteiro de ponteiros desalocada
void kill(char **str, int max){
		for (int i = 0; i < max; i++){	// percorre o ponteiro de ponteiros
				free(str[i]);
		}
		free(str);
}

// Metodo de ordenacao Quicksort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double quickSortStr(char **vector, int size){
		clock_t time = clock();		// Armazena o tempo de execucao
		quickSortStrAux(vector, 0, size-1);		// Algoritmo de ordenacao
		return (double)(clock() - time)/CLOCKS_PER_SEC;
}

// Funcao auxiliar que executa o Quicksort para strings
// Pre-condicao: vetor de strings, posicao inicial do vetor (low) e posicao final do vetor (high)
// Pos-condicao: ordena um vetor de strings recursivamente
void quickSortStrAux(char **arr, int low, int high)
{
    if (low < high)
    {
      	int pi = partitionStr(arr, low, high);		// ordena o vetor de strings em relacao ao pivo e retorna a nova posicao do pivo
      	quickSortStrAux(arr, low, pi - 1);				// chamada do metodo para um subvetor a esquerda do pivo
        quickSortStrAux(arr, pi + 1, high);				// chamada do metodo para um subvetor a direita do pivo
    }
}

// Seleciona um pivo e ordena os elementos em relacao e este pivo
// Pre-condicao: vetor de strings, posicao inicial do vetor (low) e posicao final do vetor (high)
// Pos-condicao: ordena o vetor em relacao ao pivo:
//								elementos menores que o pivo vao para sua esquerda
//								elementos maiores que o pivo vao para sua direita
// Apos ordenacao, retorna a nova posicao do ultimo pivo
int partitionStr (char **arr, int low, int high)
{
    char pivot[STRMAX];
    strcpy(pivot, arr[high]);		// pivo recebe o elemento a direita do vetor
    int i = (low - 1);

    for (int j = low; j < high; j++)	// percorre o vetor da esquerda para a direita
    {
        if (strcmp(arr[j], pivot) < 1)
        {
            i++;
            char t[STRMAX];
						// elemento na posicao j colocado a esquerda do pivo
            strcpy(t, arr[i]);
    		strcpy(arr[i], arr[j]);
    		strcpy(arr[j], t);
        }
    }

    char t[STRMAX];
    strcpy(t, arr[i+1]);
    strcpy(arr[i+1], arr[high]);	// pivo colocado na posicao correta
    strcpy(arr[high], t);					// elemento maior que o pivo eh colocado a direita do vetor para proxima iteracao
    return (i + 1);								// retorna a nova posicao do ultimo pivo
}

// Metodo de ordenacao Mergesort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double mergeSortStr(char **vet, int size){
		clock_t time = clock();		// Armazena o tempo de execucao
		mergeSortStrAux(vet, 0, size-1);		// Algoritmo de ordenacao
		return (double)(clock() - time)/CLOCKS_PER_SEC;
}

// Funcao auxiliar que executa o Mergesort para strings
// Pre-condicao: vetor de strings, posicao inicial do vetor (esquerda, 'e') e posicao final do vetor (direita, 'd')
// Pos-condicao: ordena um vetor de strings recursivamente
void mergeSortStrAux(char **vet,int e, int d) {
		if(e < d - 1)
		{
				int m = (e+d)/2;	// inteiro para armazenar a posicao da metade do vetor
				mergeSortStrAux(vet,e,m);		// chamada do metodo para a metade esquerda do vetor de strings
				mergeSortStrAux(vet,m,d);		// chamada do metodo para a metade direita do vetor de strings
				IntercalaStr(vet,e,m,d);		// realiza a uniao das duas metades do vetor, ordenando seus elementos
		}
}

// Ordena um vetor em relacao a sua metade esquerda e direita, intercalando (ordenando) seus elementos no processo
// Pre-condicao: vetor de strings, posicao inicial do vetor (esquerda, 'e'), posicao da metade ('m') do vetor e posicao final do vetor (direita, 'd')
// Pos-condicao: retorna o vetor de strings ordenado
void IntercalaStr(char **vet,int e, int m, int d) {
		int i, j, k;
		char vet_aux[d-e][STRMAX];	// vetor auxiliar para ordenar o vetor

		i = e; j = m; k = 0;	// variaveis auxiliares para percorrer as duas metades do vetor

		while( i < m && j < d) {	// percorre as duas metades do vetor simultaneamente
			// compara um elemento da metade esquerda com outro elemento da metade direita do vetor
			// caso o elemento i seja menor que o j:
			//		o elemento i eh inserido no vetor auxiliar, e anda-se uma casa na metade esquerda do vetor
			// caso o elemento j seja menor que o i:
			//		o elemento j eh inserido no vetor auxiliar, e anda-se uma casa na metade direita do vetor
			if(strcmp(vet[i], vet[j]) < 1) strcpy(vet_aux[k++], vet[i++]);
				else strcpy(vet_aux[k++], vet[j++]);
		}
		while (i < m) strcpy(vet_aux[k++], vet[i++]);
		while (j < d) strcpy(vet_aux[k++], vet[j++]);

		for(i = e; i < d; i++) strcpy(vet[i], vet_aux[i-e]);	// retorna o vetor ordenado
}

// Metodo de ordenacao Heapsort
// Pre-condicao: vetor de strings e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double heapSortStr(char** vector, int size) {
	clock_t time = clock();		// Armazena o tempo de execucao

    int i = size / 2, father, child;
    char temp[STRMAX];

    while(1) {	// loop de execucao do metodo
        if (i > 0) {
            i--;
            strcpy(temp, vector[i]);	// variavel auxiliar para guardar o valor da raiz da arvore
        }else {
            size--;
            if (size == 0) 	return (double)(clock() - time)/CLOCKS_PER_SEC;
            strcpy(temp, vector[size]);
            strcpy(vector[size], vector[0]);	// posiciona a nova raiz (o maior elemento da arvore binaria) na ultima posicao do vetor
        }

        father = i;
        child = i * 2 + 1;

        while (child < size) {	// loop para percorrer a arvore
            if ((child + 1 < size)  &&  (strcmp(vector[child + 1], vector[child])) >= 1)
                child++;
            if (strcmp(vector[child],  temp) >= 1) {		// caso o filho seja maior que o pai
                strcpy(vector[father], vector[child]);	// filho se torna o pai
                father = child;
                child = father * 2 + 1;		// posicao dos filhos deste novo pai
            } else {
                break;	// todos os pais sao maiores, logo sai do loop
            }
        }

        strcpy(vector[father], temp);	// raiz antiga eh realocada
    }
}
