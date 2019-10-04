/*
Tutorial usado:
https://www.geeksforgeeks.org/linked-list-set-1-introduction/
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.hpp"

//Adiciona um novo elemento ao final da lista
void Node::apendice(Node** refCabeca, int novoDado){
    new Node* novoNode = (Node*) malloc(sizeof(Node)); //aloca o no
    new Node* last = *refCabeca; //no que vai passar pela lista fica como o primeiro
   
    novoNode->dado = novoDado;  //Adiciona os atributos do no
    novoNode->prox = NULL; 
  
    if (*refCabeca == NULL){    //Se estiver vazio, o no vira a cabeca
       *refCabeca = novoNode;
       return;
    }
       
    while (last->prox != NULL){     //atravessa ate nao apontar para outro
        if(last->dado == novoDado){ //se o dado for repetido, nao adiciona
            return
        }
        else{
            last = last->prox; 
        }
    }
   
    last->prox = novoNode;  //aponta para o novo no
    return;     
}

//Adiciona todos os elementos da primeira lista a segunda
void Node::apendiceList(Node** refCabeca0, Node** refCabeca1){
    new Node* last = *refCabeca0;

    while (last->prox != NULL){     //atravessa ate nao apontar para outro
        apendice(refCabeca1, last->dado);
        last = last->prox;
    }
}

//Checa se um elemento esta na lista
int checaElemento(Node** refCabeca, int chave){
	new Node* last = *refCabeca;

	while (last->prox != NULL){     //atravessa ate nao apontar para outro
        if(last->dado == chave){
        	return 1;
        }
        last = last->prox;
    }
    return 0;
}



//Deleta a primeira ocorrencia do elemento
void deleteNode(Node **refCabeca, int chave){ 
    Node* temp = *refCabeca, *prev;
  
    //Se a chave estiver na cabeca
    if (temp != NULL && temp->dado == chave){ 
        *refCabeca = temp->prox;    //altera a cabeca
        delete temp;                 //libera a cabeca antiga
        return; 
    } 
  
    //Procura pela chave a ser deletada
    while (temp != NULL && temp->dado != chave){ 
        prev = temp; 
        temp = temp->prox; 
    } 
  
    //Se nao estiver presente volta
    if (temp == NULL){
        return; 
    }

    //Retira o apontador da anterior e leva para a proxima
    prev->prox = temp->prox; 

    delete temp;
} 


//Deleta todos os elementos de uma lista
void Node::deleteList(Node** refCabeca){  
    Node* current = *refCabeca; //referencia dentro da funcao
    Node* prox;
  
    while (current != NULL){  
        prox = current->prox;  
        delete current;  
        current = prox;  
    }  
          
    *refCabeca = NULL;  
}  