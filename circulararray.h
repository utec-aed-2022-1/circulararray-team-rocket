#include <iostream>
#include <stdexcept>
#include <stack>

#ifndef CIRCULARARRAY_H_
#define CIRCULARARRAY_H_

using namespace std;

template <class T>
class CircularArray
{
protected:
    T *array;
    int capacity;
    int back=-1, front=-1;    
public:
    CircularArray();                      
    CircularArray(int);                   
    virtual ~CircularArray();             
    void push_front(T data);              
    void push_back(T data);               
    void insert(T data, int pos);         
    T pop_front();                        
    T pop_back();                         
    bool is_full();                       
    bool is_empty();                        
    int size();                           
    void clear();                         
    T &operator[](int);                   
    void sort();                          
    bool is_sorted();                     
    void reverse();                       
    string to_string(string sep=" ");     
private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray(){
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity){
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray(){
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index){
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index){
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep){
    int index=front;
    string result = ""; 
    for (int i = 0; i < size(); i++){
        result += std::to_string((*this)[index]) + sep;
        index=next(index);
    }
    return result;  
}

// Agrega un elemento al comienzo
template <class T>
void CircularArray<T>::push_front(T data){
      if (is_empty()){
        back=0;
        front=0;
        array[front] = data;
      }
      else if (is_full()){
        throw("El array se encuentra completo");
      }
      else {
        front = prev(front);
        array[front] = data; 
      }
};

// Agrega un elemento al final
template <class T>
void CircularArray<T>::push_back(T data){
    if (is_empty()){
        back=0;
        front=0;
        array[back] = data;
      }
      else if (is_full()){
        throw("El array se encuentra completo");
      }
      else {
        back = next(back);
        array[back] = data; 
      }
};

// Inserta el elemento en la posición indicada
template <class T>
void CircularArray<T>::insert(T data, int pos){
      array[pos] = data;
};

// Remueve el elemento al comienzo
template <class T>
T CircularArray<T>::pop_front(){
  if (is_empty()){
    throw("El array se encuentra vacio");
  }
  T dataEliminada = array[front];
  front = next(front);
  return dataEliminada;
};

// Remueve el elemento al final
template <class T>
T CircularArray<T>::pop_back(){
  if (is_empty()){
    throw("El array se encuentra vacio");
  }
  T dataEliminada = array[back];
  back = prev(back);
  return dataEliminada;
};

// Retorna si el array está lleno o no
template <class T>
bool CircularArray<T>::is_full(){
  return next(back) == front;
};

// Retorna si el array está vacía o no
template <class T>
bool CircularArray<T>::is_empty(){
  return ((back==-1) && (front==-1));
};

// Retorna el tamaño del array
template <class T>
int CircularArray<T>::size(){
  if (is_empty()){return 0;}
  else if (back == front){return 1;}
  else if (back>front){return back-front+1;}
  else {return  abs((front-back-1) - capacity);}
};

// Elimina todos los elementos del array
template <class T>
void CircularArray<T>::clear(){
  delete[] array;
  front= back= -1;
};

//Ordena todos los elementos del array de menor a mayor
template <class T>
void CircularArray<T>::sort(){
    bool swap = true;
    int index=front;
    while (swap){
        swap = false;
        for (int i=0; i<size()-1; ++i){
            int nextIndex = next(index);
            if (array[nextIndex]<array[index]){
                T temp = array[index];
                array[index] = array[nextIndex];
                array[nextIndex] = temp;
                swap = true;
            }
            index = next(index);
        }
        index=front;
    }
};

//Veriica si el array se encuentra ordenado de menor a mayor
template <class T>
bool CircularArray<T>::is_sorted(){
  int index=front;
  for(int i=0; i<size(); i++){
    int nextIndex = next(index);
    if(array[index]>array[nextIndex]){
      return false;
    }
    index=next(index);
  }
  return true;
};

//Invierte los valores del array
template <class T>
void CircularArray<T>::reverse(){
  stack<T> stackTemporal;
  int index=front;
  for(int i=0; i<size(); i++){
    stackTemporal.push(array[index]);
    index=next(index);
  }

  int index_2=front;
  for(int i=0; i<size(); i++){
    array[index] = stackTemporal.top();
    stackTemporal.pop();
    index=next(index);
  }
};

//Accede a un elemento del array mediante el operador[]
template <class T>
T& CircularArray<T>::operator[](int index){
    if (index >= size()){
        throw("El indice excede el limite del array");
    }
    else if (index < 0){
        throw("El indice ingresado es invalido");
    }
    return array[index];
} 

#endif 


