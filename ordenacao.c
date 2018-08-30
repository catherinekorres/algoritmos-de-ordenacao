#include "control.h"
#include "ints.h"
#include "strings.h"


int main(int argc, char const *argv[])
{
	Control *control = parseControl(argc, (char**)argv);	// estrutura com as informacoes de controle dos metodos
	if(control->type == 'N'){
		intControl(control);	// ordenacao de inteiros
	} else if(control->type == 'C'){
		strControl(control);	// ordenacao de caracteres
	}
	free(control);	// libera a estrutura de controle
	return 0;
}
