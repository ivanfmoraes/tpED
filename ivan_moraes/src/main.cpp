#include <iostream>
#include "list.hpp"

/*ENTRADAS
int Q (0 < Q 200;000), indicando uma medicao em ml
char E (apos um espaco em branco), indicando o tipo de evento de entrada
  'i': indica a inclusao no seu programa de um recipiente de Q ml
  'r': indica que o recipiente de Q ml quebrou e deve ser removido do seu programa
  'p': indica que Rick deseja fazer uma medicao de Q ml
*/

int recipienteEquivalente(Node* cabecaRecipientes, int medida){
  new Node* last = *cabecaRecipientes; //no que vai passar pela lista fica como o primeiro
  while(last->prox != NULL){
    if(last->dado == medida){
      return 1;
    }
    else{
      last = last->prox;
    }
  }
  return 0;
}

int operacoesMinimas(Node* cabecaRecipientes, int medida){
  int operacoes = 0;
  int nivel = 1;

  if(medida == 0){	//caso base
    return 0;
  }

  if(recipienteEquivalente(cabecaRecipientes, medida) == 1){	//caso base
    return 1;
  }

  new Node* cabecaPermut;	//nos para as cabecas de lista
  new Node* cabecaProx;

  apendiceList(cabecaRecipientes, cabecaPermut);
  new Node* lastRecipientes;

  while(operacoes == 0){
  	lastRecipientes = *cabecaRecipientes;	//nos para iterar pelas listas
  	new Node* lastPermut = *cabecaPermut;	
  	new Node* lastProx = *cabecaProx;

    while(lastPermut->prox != NULL){
      while(lastRecipientes->prox != NULL){
      	//garanto que so vai fazer operacao se estiver aproximando do resultado
      	if(lastPermut->dado < medida){	
      		apendice(cabecaProx, lastPermut->dado + lastRecipientes->dado);
      	}
      	else{
      		apendice(cabecaProx, lastPermut->dado - lastRecipientes->dado);
      	}
      }
    }

    nivel += 1;

    //Deleta todas as listas e altera o valor da saida, acabando o loop
    if(checaElemento(cabecaProx, medida) == 1){
    	deleteList(cabecaPermut);
    	deleteList(cabecaProx);
    	deleteList(cabecaRecipientes);
    	operacoes = nivel;
    }

    //Prepara para mais um nivel de operacoes
    else{
    	deleteList(cabecaPermut);
    	new **Node cabecaPermut;
    	apendiceList(cabecaProx, cabecaPermut);
    	deleteList(cabecaProx);
    	new **Node cabecaProx;
    }
  }

  return operacoes;
}

int main() {
  int q;  //medicao em ml
  char e; //tipo de evento da entrada
  new Node* cabecaReci = NULL; 

  while(scanf("%d %c", &q, &e) != EOF) {
    if(e == 'i'){   //adicao
      apendice(cabecaReci, q);
    }

    else if(e == 'r'){  //remocao
      deleteNode(cabecaReci, q);
    }

    else if(e == 'p'){  //medicao
      printf("%d\n", operacoesMinimas(cabecaReci, q));
    }
  }

  return 0;
}