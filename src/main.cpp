#include <iostream>
#include "Vector.h"
#include <vector.cpp>
using namespace std;

int main (){
  Vector lista;

  // Adicionando numeros de 1 a 50
  for(int i = 1; i <= 50; i++){
    lista.push_back(i);
  }

  // Imprimindo elementos da lista
  for(int i = 0; i < lista.getSize(); i++){
    cout << lista[i] << " ";
  }
}