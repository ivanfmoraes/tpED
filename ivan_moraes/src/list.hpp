/*
Tutorial usado:
https://www.geeksforgeeks.org/linked-list-set-1-introduction/
*/

#ifndef LIST_H
#define LIST_H

class Node{
public: 
    int dado; 
    Node* prox;

    //Adiciona um novo elemento ao final da lista
    void apendice(Node** refCabeca, int novoDado);	
    //Adiciona todos os elementos da primeira lista a segunda
    void apendiceList(Node** refCabeca0, Node** refCabeca1);	

    //Checa se um elemento esta na lista
    int checaElemento(Node** refCabeca, int chave);

    //Deleta a primeira ocorrencia do elemento
	void deleteNode(Node** refCabeca, int chave);
    //Deleta todos os elementos de uma lista	
    void deleteList(Node** refCabeca);	
}; 

#endif