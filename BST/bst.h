#ifndef BST_H
#define BST_H


#include<iostream>
using namespace std;

template<class D>
class bst
{
    struct node;

    private:
    node * p_root;

    public:
    bst() : p_root(nullptr){}
    bool insert(const D & d);
    ~bst();
    bool find(const D & d);
    bool remove(const D & d);

    D & operator [] (const D & d);

    private :
    bool find(node **& n, const D & data)
    {
        n = & p_root;
        while(*n)
        {
            if(data == (*n)->data){return true;}
            n = &(*n)-> p_child[data > (*n) -> data];
        }
        return false;
    }
bool delete_bst(node **& n, const D & data)
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


        (*n)->data = mov->data;

        if(save==nullptr)
            (*n)->p_child[0] = mov ->p_child [0];
        else
            save ->p_child[1] = save -> p_child[0];
        save = nullptr;
    }
    return true;
}
};
#include "bst.inl"
#endif // BST_H
