#ifndef BST_H
#define BST_H


#include<iostream>
using namespace std;

template<class K, class D>
class bst
{
    struct node;

    private:
    node * p_root;

    public:
    bst() : p_root(nullptr){}
    bool insert(const K & k, const D & d);
    ~bst();
    bool find(const K & k);
    bool remove(const K & k);

    D & operator [] (const K & key);

    private :
    bool find(node **& n, const K & key)
    {
        n = & p_root;
        while(*n)
        {
            if(key == (*n)->key){return true;}
            n = &(*n)-> p_child[key > (*n) -> key];
        }
        return false;
    }
bool delete_bst(node **& n, const K & key)
{
    node * save;
    node * mov;
    node * aux;
    if((*n)-> p_child[0] == nullptr && (*n)->p_child[1] == nullptr)
    {
        *n = nullptr;
    }
    else if ((*n)->p_child[0]== nullptr)
    {
        aux = *n;
        *n = (*n)->p_child[1];
        aux = nullptr;
    }
    else if ((*n)->p_child[1]== nullptr)
    {
        aux = *n;
        *n = (*n)->p_child[0];
        aux = nullptr;
    }
    else
    {
        mov = (*n)->p_child[0];
        save = nullptr;

        while(mov->p_child[0] != nullptr)
        {
            save = mov;
            mov = mov ->p_child[1];
        }


        (*n)->key = mov->key;
        (*n)->dato = mov->dato;

        if(save==nullptr)
            (*n)->p_child[0] = mov ->p_child [0];
        else
            save ->p_child[1] = save -> p_child[0];
        save = nullptr;
        // eliminar cuando tenga dos hijos
    }
    return true;
}
};
#include "bst.inl"
#endif // BST_H
