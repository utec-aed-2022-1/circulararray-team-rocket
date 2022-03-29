#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
    public:
    QueueArray();
    QueueArray(int);
    virtual ~QueueArray();
    void enqueue(T data);
    T dequeue();
    void display();
};

template <class T>
QueueArray<T>::QueueArray(){
    QueueArray(0);
}

template <class T>
QueueArray<T>::QueueArray(int _capacity){
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
QueueArray<T>::~QueueArray(){

}

template <class T>
void QueueArray<T>::enqueue(T data){
    this->push_back(data);
}

template <class T>
T QueueArray<T>::dequeue(){
    T result=this->pop_front();
    return result;
}

template <class T>
void QueueArray<T>::display(){
    cout<<this->to_string(" ");
}
