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
  Vector()
  {
    this->capacity = 5;
    this->size = 0;
    this->ptr = new int[this->capacity];
  }

  void Vector::push_back(const int& value)
  {
    // Insere um valor inteiro na lista somente se houver espaço
    if(this->size < this->capacity){
      this->ptr[this->size] = value;
      this->size++;
    }
  }

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
  int& at(int n) const 
  {
    if(n < 0 || n >= this->size){
      throw std::out_of_range("Index out of range");
    }
    return this->ptr[n];
  }

  // Retorna uma referência para o primeiro elemento da lista
  int& operator[](int n)
  {
    return this->ptr[n];
  }
  /*
  
    Verifica se a lista está cheia, se sim, aloca mais espaço
    realocando novos elementos para o novo vetor. Em todos os
    outros casos, a chamada da função não tem realocação de memória
    e a capacidade do vetor não é afetada
  
  */
  void reserve(int n)
  {
    if(n > this->capacity)
    {
      int *new_ptr = new int[n];
      for(int i = 0; i < this->size; i++)
      {
        new_ptr[i] = this->ptr[i];
      }
      delete[] this->ptr;
      this->ptr = new_ptr;
      this->capacity = n;
    }
  }

  // Função para decrementar o tamanho da lista, utilizada na função removeAt
  void decrementSize()
  {
    if(size > 0){
      --size;
    }
  }

  // Função para incrementar o tamanho da lista, utilizada na função insert
  void incrementSize()
  {
    if(size < capacity){
      ++size;
    }
  }

  /*
  Recebe um inteiro como argumento e o adiciona 
  logo após o ultimo elemento da lista.
  */
  void push_back(int& value)
  {
    if(this->size < this->capacity)
    {
      this->ptr[this->size] = value;
      this->size++;
    }
  }

  /*
  Remove o ultimo elemento da lista se a lista não estiver
  vazia. Caso contrário, faz nada
  */
  void pop_back()
  {
    if(this->size > 0)
    {
      this->size--;
    }
  }


  // Destructor libera a mémoria que foi alocada dinamicamente
  ~Vector(){
    delete[] this->ptr;
  }
};


#endif // VECTOR_H