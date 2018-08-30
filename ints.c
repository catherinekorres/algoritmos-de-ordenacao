#include "ints.h"

// Funcao de controle para os algoritmos de ordenacao com inteiros
// Pre-condicao: entrada de estrutura com dados de controle
// Pos-condicao: cria um vetor de inteiros aleatorios, realiza a chamada do(s) algoritmo(s) e libera o vetor ao final
void intControl(Control *control){
		int *vector = newRandomVector(control); // Criacao de vetor de inteiros aleatorios
		if(control->sortType != 'A'){
				selectSortInt(control, vector);     // Executa o algoritmo de ordenacao escolhido
				if(control->output){
						writeInt(vector, control);      // Armazena o resultado da ordenacao no arquivo output
				}
		} else allSortsInt(control, vector);    // Executa todos os algoritmos
		free(vector);                           // Libera o vetor
}

// Armazena um vetor de inteiros em um arquivo
// Pre-condicao: vetor de inteiros e estrutura com dados de controle
// Pos-condicao: arquivo contendo o vetor de inteiros
void writeInt(int *vector, Control* control){
		FILE *f = fopen(control->output, "w+"); // Abre o arquivo de output para leitura e escrita
		for (int i = 0; i < control->num; ++i)
		{
				fprintf(f, "%d\n",vector[i]);   // Grava um inteiro no arquivo
		}
		fclose(f);  // Fecha o arquivo de output
}

// Gera um vetor de inteiros aleatorios
// Pre-condicao: entrada de estrutura com dados de controle
// Pos-condicao: retorna um vetor de inteiro aleatorios
int *newRandomVector(Control *control){
		int size = control->num;                // Quantidade de numeros a serem gerados
		int *vector = malloc(sizeof(int)*size);
	    	srand(time(NULL));
		for (int i = 0; i < size; ++i)
		{
				vector[i] = rand() % INT_MAX;   // Gera um numero aleatorio e o armazena no vetor
		}
		return vector;
}

// Realiza a chamada dos metodos de ordenacao de inteiros
// Pre-condicao: vetor de inteiros e estrutura com dados de controle
// Pos-condicao: metodo de ordenacao eh chamado
void selectSortInt(Control *control, int *vector){
		switch(control->sortType){
				case 'I':
						insertionSortInt(vector, control->num);   // Insertion Sort
						break;
				case 'S':
						selectionSortInt(vector, control->num);   // Selection Sort
						break;
				case 'Q':
						quickSortInt(vector, control->num);       // Quicksort
						break;
				case 'M':
						mergeSortInt(vector, control->num);       // Mergesort
						break;
				case 'H':
						heapSortInt(vector, control->num);        // Heapsort
						break;
				default : return;
		}
}

// Realiza a chamada de todos os metodos de ordenacao de inteiros e imprime seus tempos de execucao
// Pre-condicao: vetor de inteiros e estrutura com dados de controle
// Pos-condicao: todos os metodos de ordenacao sao chamados e eh imprimido o tempo de execucao de cada um
void allSortsInt(Control* control,int* vector){
	printf("Insertion sort time: %g\n", insertionSortInt(vector, control->num));		// Insertion Sort
	free(vector);
	vector = newRandomVector(control);
	printf("Selection sort time: %g\n", selectionSortInt(vector, control->num));		// Selection Sort
	free(vector);
	vector = newRandomVector(control);
	printf("Quick sort time: %g\n", quickSortInt(vector, control->num));						// Quicksort
	free(vector);
	vector = newRandomVector(control);
	printf("Merge sort time: %g\n", mergeSortInt(vector, control->num));						// Mergesort
	free(vector);
	vector = newRandomVector(control);
	printf("Heap sort time: %g\n", heapSortInt(vector, control->num));							// Heapsort
}

// Metodo de ordenacao Insertion Sort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double insertionSortInt(int *vector, int size){
		clock_t time = clock(); // Armazena o tempo de execucao
		int i, j, temp;
		for (j = 1; j < size; j++) {
				temp = vector[j];
				for (i = j-1; i >= 0 && vector[i] > temp; i--)
						vector[i+1] = vector[i];

				vector[i+1] = temp; // Coloca o inteiro armazenado em temp na posicao correta
		}
	    	return (double)(clock() - time)/CLOCKS_PER_SEC;
}

// Metodo de ordenacao Selection Sort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double selectionSortInt(int *vet, int size){
    clock_t time = clock(); // Armazena o tempo de execucao
    int i, j, min, temp;
    for (i = 0; i < size-1; i++) {
        min = i;
        for (j = i+1; j < size; j++)
            if(vet[j] < vet[min]) min = j;

        // Troca o elemento na posicao i com o da posicao min do vetor
        temp = vet[i];
        vet[i] = vet[min];
        vet[min] = temp;
    }
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}

// Metodo de ordenacao Quicksort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: realiza a chamada do quicksort, ordena o vetor e retorna o tempo de execucao de metodo
double quickSortInt(int *vector, int size){
    clock_t time = clock(); 	// Armazena o tempo de execucao
    quickSortIntAux(vector, 0, size-1);		// Algoritmo de ordenacao
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}

// Funcao auxiliar que executa o Quicksort para inteiros
// Pre-condicao: vetor de inteiros, posicao inicial do vetor (esquerda, 'e') e posicao final do vetor (direita, 'd')
// Pos-condicao: ordena um vetor de inteiros recursivamente
void quickSortIntAux(int *vector, int e, int d){
    if (e < d)
    {
        int j = partitionInt(vector, e, d);		// ordena o vetor de inteiros em relacao ao pivo e retorna a nova posicao do pivo
        quickSortIntAux(vector, e, j-1);			// chamada do metodo para um subvetor a esquerda do pivo
        quickSortIntAux(vector, j+1, d);			// chamada do metodo para um subvetor a direita do pivo
    }
}

// Seleciona um pivo e ordena os elementos em relacao e este pivo
// Pre-condicao: vetor de inteiros, posicao inicial do vetor (esquerda, 'e') e posicao final do vetor (direita, 'd')
// Pos-condicao: ordena o vetor em relacao ao pivo:
//								elementos menores que o pivo vao para sua esquerda
//								elementos maiores que o pivo vao para sua direita
// Apos ordenacao, retorna a nova posicao do ultimo pivo
int partitionInt(int *vector, int e, int d){
    int pivot,i,j,temp;

    pivot = vector[d];	// pivo recebe o elemento a direita do vetor
    j = e;
    for( i = e; i < d; i++)		// percorre o vetor da esquerda para a direita
    {
       if(vector[i] <= pivot)		// elemento na posicao i menor ou igual ao pivo
       {
				 		// elemento na posicao i colocado a esquerda do pivo
            temp = vector[j];
            vector[j] = vector[i];
            vector[i] = temp;
            j++;
        }
    }

    vector[d] = vector[j];	// elemento maior que o pivo eh colocado a direita do vetor para proxima iteracao
    vector[j] = pivot;			// pivo colocado na posicao correta
    return j;								// retorna a nova posicao do ultimo pivo
}

// Metodo de ordenacao Mergesort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double mergeSortInt(int *vector, int size){
    clock_t time = clock(); // Armazena o tempo de execucao
    mergeSortIntAux(vector, 0, size-1);		// Algoritmo de ordenacao
    return (double)(clock() - time)/CLOCKS_PER_SEC;
}

// Funcao auxiliar que executa o Mergesort para inteiros
// Pre-condicao: vetor de inteiros, posicao inicial do vetor (esquerda, 'e') e posicao final do vetor (direita, 'd')
// Pos-condicao: ordena um vetor de inteiros recursivamente
void mergeSortIntAux(int *vector, int e, int d) {
		if(e < d-1)
		{
		    int m = (e+d)/2;	// inteiro para armazenar a posicao da metade do vetor
		    mergeSortIntAux(vector,e,m);	// chamada do metodo para a metade esquerda do vetor de inteiros
		// printf("dead\n");
		    mergeSortIntAux(vector,m,d);	// chamada do metodo para a metade direita do vetor de inteiros
		    IntercalaInt(vector,e,m,d);		// realiza a uniao das duas metades do vetor, ordenando seus elementos
		}
}

// Ordena um vetor em relacao a sua metade esquerda e direita, intercalando (ordenando) seus elementos no processo
// Pre-condicao: vetor de inteiros, posicao inicial do vetor (esquerda, 'e'), posicao da metade ('m') do vetor e posicao final do vetor (direita, 'd')
// Pos-condicao: retorna o vetor de inteiros ordenado
void IntercalaInt(int *vector, int e, int m, int d) {
		int i, j, k;
		int *vet_aux = malloc((d-e)*sizeof(int));	// vetor auxiliar para ordenar o vetor

		i = e; j = m; k = 0;	// variaveis auxiliares para percorrer as duas metades do vetor

		while( i < m && j < d) {	// percorre as duas metades do vetor simultaneamente
				// compara um elemento da metade esquerda com outro elemento da metade direita do vetor
				// caso o elemento i seja menor que o j:
				//		o elemento i eh inserido no vetor auxiliar, e anda-se uma casa na metade esquerda do vetor
				// caso o elemento j seja menor que o i:
				//		o elemento j eh inserido no vetor auxiliar, e anda-se uma casa na metade direita do vetor
				if(vector[i] <= vector[j]) vet_aux[k++] = vector[i++];
				else vet_aux[k++] = vector[j++];
		}
		while (i < m) vet_aux[k++] = vector[i++];
	  while (j < d) vet_aux[k++] = vector[j++];

	  for(i = e; i < d; i++) vector[i] = vet_aux[i-e];	// retorna o vetor ordenado
	  free(vet_aux);
}

// Metodo de ordenacao Heapsort
// Pre-condicao: vetor de inteiros e tamanho do vetor
// Pos-condicao: ordena o vetor e retorna o tempo de execucao de metodo
double heapSortInt(int *vector, int size){
    clock_t time = clock(); // Armazena o tempo de execucao

    int i = size / 2, father, child, temp;

    while(1) {	// loop de execucao do metodo
        if (i > 0) {
            i--;
            temp = vector[i];	// variavel auxiliar para guardar o valor da raiz da arvore
        }else {
            size--;
            if (size == 0) return (double)(clock() - time)/CLOCKS_PER_SEC;
            temp = vector[size];
            vector[size] = vector[0];	// posiciona a nova raiz (o maior elemento da arvore binaria) na ultima posicao do vetor
        }

        father = i;
        child = i * 2 + 1;

        while (child < size) {	// loop para percorrer a arvore
            if ((child + 1 < size)  &&  (vector[child + 1] > vector[child]))
                child++;
            if (vector[child] > temp) {		// caso o filho seja maior que o pai
                vector[father] = vector[child];		// filho se torna o pai
                father = child;
                child = father * 2 + 1;		// posicao dos filhos deste novo pai
            } else {
                break;	// todos os pais sao maiores, logo sai do loop
            }
        }
        vector[father] = temp;	// raiz antiga eh realocada
    }
}