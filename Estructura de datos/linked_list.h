#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "fstream"
using namespace std;
template<class T>

class linked_list
{
public:
    struct node;
    struct iterator;

private:
        node * p_head;
    public:

    linked_list(): p_head(nullptr){}
    ~linked_list();

    iterator begin();

    iterator end();

    T & operator []( int i);

    int size();

    void push_front(const T & d);

    void remove(iterator it);

    void remove_front();

    void push_back(const T & d); //tarea completada

    void remove_back(); //tarea completada

};
#include "linked_list.inl"
#endif // LINKED_LIST_H
