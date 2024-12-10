#include "Vector.h"

Vector list;

// Troca o elemento no índice k pelo elemento value
void replaceAt(int value, int k)
{
  if(k >= 0 && k <= list.getSize() - 1){
    list[k] = value;
  }
}

// Remove o elemento com índice k na lista
void removeAt(int k)
{
  if(k >= 0 && k <= list.getSize() - 1){
    for(int i = k; i < list.getSize() - 1; i++){
      list[i] = list[i + 1];
    }
    list.decrementSize();
  }
}
 /*

  Adiciona o elemento value na posição k da lista
  antes de fazer a inserção, todos os elementos do índice k
  são deslocados uma posição para a direita
 
 */
 bool insert(int value, int k)
 {
  if(k >= 0 && k <= list.getSize() - 1){
    list.reserve(list.getSize() + 1);
    for(int i = list.getSize(); i > k; i--){
      list[i] = list[i - 1];
    }
    list[k] = value;
    list.incrementSize();
    return true;
  }
 }

 // Remove todas as ocorrências do elemento value na lista
 void removeAll(int value)
 {
  for(int i = 0; i < list.getSize(); i++){
    if(list[i] == value){
      removeAt(i);
      i--;
    }
  }
 }
