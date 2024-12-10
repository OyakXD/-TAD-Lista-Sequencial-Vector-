#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

// Implementação de uma Lista linear
class Vector 
{
  private:
  int size; // Numero de elementos na lista
  int capacity; // Tamanho total do array(Lista)
  int *ptr; // Ponteiro para o arry de inteiros

  public:
  /*
    Construtor default: cria uma lista vazia 
    com capacidade inicial para 5 inteiros
  */
  Vector();

  // Retorna a capacidade total da lista
  int getCapacity() const 
  {
    return this->capacity;
  }

  // Retorna o tamanho atual da lista
  int getSize() const
  {
    return this->size;
  }

  // Retorna true se e somente se a lista estiver vazia
  bool empty() const 
  {
    if(this->size == 0){
      return true;
    }
  }
  
  /*
   Retorna uma referência para o elemento na posição N
   a função verifica automaticamente se n está dentro dos
   limites de elementos válidos no vetor, lançando uma exceção
   ''std::out_of_range'' caso contrário
  
  */ 
  int& Vector::at(int n) const;

  // Retorna uma referência para o primeiro elemento da lista
  int& operator[](int n);
  /*
  
    Verifica se a lista está cheia, se sim, aloca mais espaço
    realocando novos elementos para o novo vetor. Em todos os
    outros casos, a chamada da função não tem realocação de memória
    e a capacidade do vetor não é afetada
  
  */
  void Vector::reserve(int n);

  // Função para decrementar o tamanho da lista, utilizada na função removeAt
  void Vector::decrementSize();

  // Função para incrementar o tamanho da lista, utilizada na função insert
  void Vector::incrementSize();

  /*
  Recebe um inteiro como argumento e o adiciona 
  logo após o ultimo elemento da lista.
  */
  void push_back(int& value);

  /*
  Remove o ultimo elemento da lista se a lista não estiver
  vazia. Caso contrário, faz nada
  */
  void pop_back();

  void replaceAt(int value, int k);
  
  void removeAt(int k);

  bool insert(int value, int k);

  void removeAll(int value);


  // Destructor libera a mémoria que foi alocada dinamicamente
  ~Vector(){
    delete[] this->ptr;
  }
};


#endif // VECTOR_H