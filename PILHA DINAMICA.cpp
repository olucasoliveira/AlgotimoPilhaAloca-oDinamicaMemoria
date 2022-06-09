#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct pilhaDinamica{
	int valor;
	struct pilhaDinamica *prox;
}PILHA;

	PILHA *topo;
	PILHA *elemento;
	

void push(){
	elemento = (PILHA*) malloc (sizeof(PILHA));
	elemento->valor = rand() % 1000 ;
	elemento->prox = topo;
	topo = elemento;	
}

int pop(){
	int removido;
	PILHA *aux;
	
	if(topo == NULL){
		printf("\nA Pilha esta vazia\n\nInsira algum elemento primeiro\n");
	}else{
		aux = topo;
		removido = topo->valor;
		topo = topo->prox;
		printf("\nO valor %d foi removido da pilha\n\n", removido);
    		free(aux);
	}
}

void show(){
	PILHA *aux;
	if(topo == NULL){
		printf("\nA Pilha esta vazia\n\nInsira algum elemento primeiro\n");
	}else{
	    aux = topo;
	    printf("\nOs valores inseridos na pilha sao:\n\n ");
	    while(aux != NULL)
	    {
		printf("\n      %d ", aux->valor);
		aux = aux->prox;
	    }
		}
	 printf("\n\n");

	return;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	int control, quantPush, quantPop, inserted=0, removed=0;
	
	do{		
		printf("\nEscolha uma opção: \n\n [1] Inserir  \n [2] Retirar \n [3] Imprimir \n [4] Sair \n\nA opção escolhida é: ");
		scanf("%d", &control);
		
		if(control == 1)
		{	
			printf("\nDigite a quantidade de elementos que deseja inserir: ");
			scanf("%d", &quantPush);
			while( inserted < quantPush){
				push();
				inserted++;
			}
			inserted = 0;
		}
		
		if(control == 2)
		{
			if(topo == NULL){
				printf("\nA pilha esta vazia, ensina um elemento primeiro");
			
			}else{
				printf("\nDigite a quantidade de elementos que deseja remover: ");
				scanf("%d", &quantPop);
				while( removed < quantPop){
					pop();
					removed++;
				}
				removed = 0;
			}
		}	
		
		if(control == 3)
		{
			show();		
		}
		
		if(control == 4)
		{
			control = 0;
		}
		
	}while( control != 0 );
	
	printf("\nVocê saiu do programa");
	

	return 0;
}
