#include "Vector.h"

Vector::Vector()
{
  size = 0;
  capacity = 5;
  ptr = new int[capacity];
}

void Vector::reserve(int n)
{
   if(n > capacity)
    {
      int *new_ptr = new int[n];
      for(int i = 0; i < size; i++)
      {
        new_ptr[i] = ptr[i];
      }
      delete[] ptr;
      ptr = new_ptr;
      capacity = n;
    }
}

int& Vector::at(int n) const
{
  if(n < 0 || n >= size){
      throw std::out_of_range("Index out of range");
    }
    return ptr[n];
}

void Vector::push_back(int& value){
  
  if(size >= capacity){
    reserve(capacity * 2);
  }
      ptr[size] = value;
      size++;
}

void Vector::pop_back()
{
     if(size > 0)
    {
      size--;
    }
}

// Troca o elemento no índice k pelo elemento value
void Vector::replaceAt(int value, int k)
{
  if(k >= 0 && k <= size - 1){
    ptr[k] = value;
  }
}

// Remove o elemento com índice k na lista
void Vector::removeAt(int k)
{
  if(k >= 0 && k <= size - 1){
    for(int i = k; i < size - 1; i++){
      ptr[i] = ptr[i + 1];
    }
    decrementSize();
  }
}
 /*

  Adiciona o elemento value na posição k da lista
  antes de fazer a inserção, todos os elementos do índice k
  são deslocados uma posição para a direita
 
 */
 bool Vector::insert(int value, int k)
 {
  if(k >= 0 && k <= size - 1){
    reserve(size + 1);
    for(int i = size; i > k; i--){
      ptr[i] = ptr[i - 1];
    }
    ptr[k] = value;
    incrementSize();
    return true;
  }
 }

 // Remove todas as ocorrências do elemento value na lista
 void Vector::removeAll(int value)
 {
  for(int i = 0; i < size; i++){
    if(ptr[i] == value){
      removeAt(i);
      i--;
    }
  }
 }

 void Vector::decrementSize()
 {
   if(size > 0){
      --size;
    }
 }

 void Vector::incrementSize()
 {
  if(size < capacity){
      ++size;
    }
 }
