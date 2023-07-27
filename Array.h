#pragma once
#include <iostream>

template <typename T>
class Array{
    private:
        int m_size;
        T* m_arr = nullptr;
    public:
        Array<T>() = delete;
        Array<T>(int const);
        ~Array<T>();
        Array<T>(const Array<T>&);
        Array<T>& operator =(const Array<T>&);
        Array<T>(Array<T>&&);
        Array<T>& operator =(Array<T>&&);
    public:
        T get_element(int const);
        int size();
        void rand_init();
        T& operator [](int);
        T& at(int);
        void push_back(T);
        void pop_back();
};

template <typename T>
Array<T>::Array(int const size){
    if (size < 1){
        std::cerr << "Size can't be lower than 1" << std::endl;
        abort();
    }
    this->m_size = size;
    m_arr = new T[this->m_size];
}

template <typename T>
Array<T>::~Array(){
    delete[] m_arr;
    m_arr = nullptr;
}

template <typename T>
Array<T>::Array(const Array<T>& obj)
    : m_size(obj.m_size)
{
    this->m_arr = new T[m_size];
    for (int i = 0; i < m_size; i++){
        this->m_arr[i] = obj.m_arr[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& obj){
    if (this != &obj){
        delete[] this->m_arr;
        this->m_arr = nullptr;
        this->m_size = obj.m_size;
        this->m_arr = new T[m_size];
        for (int i = 0; i < m_size; i++){
            this->m_arr[i] = obj.m_arr[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::Array(Array<T>&& obj)
    : m_size(obj.m_size), m_arr(obj.m_arr)
{
    obj.m_size = 0;
    obj.m_arr = nullptr;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& obj){
    if (this != &obj){
        delete[] this->m_arr;
        this->m_size = obj.m_size;
        this->m_arr = obj.m_arr;
        obj.m_size = 0;
        obj.m_arr = nullptr;
    }
    return *this;
}


template <typename T>
T Array<T>::get_element(int const i){
    return m_arr[i];
}

template <typename T>
void Array<T>::rand_init(){
    for (int i = 0; i < m_size; i++)
    {
        m_arr[i] = rand() % 90 + 10;
    }
}

template <typename T>
int Array<T>::size(){
    return m_size;
}

template <typename T>
T& Array<T>::operator [] (int const i){
    return m_arr[i];
}

template <typename T>
T& Array<T>::at(int i){
    if (i < 0 || i > m_size){
        std::cerr << "\nIndex is not in range" << std::endl;
        abort();
    }
    return m_arr[i];
}

template <typename T>
void Array<T>::push_back(T t){
    T* temp = new T[m_size+1];
    for (int i = 0; i < m_size; i++){
        temp[i] = m_arr[i];
    }
    temp[m_size++] = t;
    delete[] m_arr;
    m_arr = temp;
    temp = nullptr;
}

template <typename T>
void Array<T>::pop_back(){
    T* temp = new T[m_size-1];
    for (int i = 0; i < m_size; i++){
        temp[i] = m_arr[i];
    }
    m_size--;
    delete[] m_arr;
    m_arr = temp;
    temp = nullptr;
}