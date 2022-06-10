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
	int mov;
	int conta = 0;
	
void esvaziar(){
    PILHA *aux;
    
    aux = topo;
    while(topo !=NULL)
    {
    	aux = topo;
    	topo = topo->prox;
    	free(aux);
    	
    }
    printf("\n A pilha foi zerada !");
    
}
	
contador(){
    conta=conta + 1;
}

	
void push(){
	elemento = (PILHA*) malloc (sizeof(PILHA));
	elemento->valor = rand() % 1000 ;
	elemento->prox = topo;
	topo = elemento;
	contador();
	printf("\n- Inserido:  Valor =     %d    Endereço = %x", topo->valor, topo);
}

int pop(){
	int removido;
	PILHA *aux;

	
	if(topo == NULL){
		printf("\nA Pilha esta vazia\n");
	}else{
	aux = topo;
	removido = topo->valor;
	topo = topo->prox;
	printf("\n- Removido:   Valor =     %d    Endereço = %x", removido, aux);
    free(aux);
    contador();
	}
}

void show(){
	PILHA *aux;
	if(topo == NULL){
		printf("\nA Pilha esta vazia");
	}else{
    aux = topo;
    printf("\nOs valores atuais na pilha sao:\n\n ");
    while(aux != NULL)
    {
        printf("\n- Valor =      %d    Endereço = %x ", aux->valor, aux);
        aux = aux->prox;
    }
	}
    printf("\n\n");


	return;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	int control, i, ciclos, quantPush, quantPop, inserted=0, removed=0;
	
	printf("\nDigite a quantidade de ciclos que deseja realizar: ");
	scanf("%d", &ciclos);
	
	for(i=0; i < ciclos; i++){
	    printf("\n===========================================================");
	    printf("\nQuantidade de movimentações no %d° ciclo: ", i+1);
	    scanf("%d", &mov);
	    
    	do{	
			printf("\n===========================================================");	
    		printf("\n\nEscolha uma opção: \n\n [1] Inserir  \n [2] Retirar \n [3] Imprimir \n [4] Sair \n\nA opção escolhida é: ");
    		scanf("%d", &control);
    		printf("\n===========================================================");
    		if(control == 1)
    		{	
    			printf("\nDigite a quantidade de elementos que deseja inserir: ");
    			scanf("%d", &quantPush);
    			while( inserted < quantPush && conta <= mov){
    				push();
    				inserted++;
    			}
    			inserted = 0;
    		}
    		
    		if(control == 2)
    		{
    		    if(topo == NULL){
    		        printf("\nA pilha esta vazia, insira um elemento primeiro !");
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
    		
    		if(control == 3){
    			show();		
    		}
    		if(conta >= mov || control == 4){
    			printf("\n===============================================");
    			printf("\n\nO limite maximo de movimentações na pilha foi atingido,\napós essa impressão ela será zerada.\n ");
    			show();
    			esvaziar();
    		    control = 0;
    		}
    
    	}while(control != 0 );
    	conta = 0;
	}
	
	printf("\nO numero de ciclos foi atingido");
	

	return 0;
}
