#include "bst.h"
template<class D>
struct bst<D>::node
{
    D data;
    node * p_child[2];
	node * root;

    node(const D & d) : data(d)
    {
        p_child[0] = p_child[1] = root =nullptr;
    }
    ~node() = default;
};
template<class D>
bool bst<D>::insert(const D & d)
{
    node **n;
    if(find(n,d)) return false;
    *n = new node(d);
    return true;
}
template<class D>
bool bst<D>::find(const D & d)
{
    node **n;
    return (find (n,d));
}
template<class D>
bool bst<D>::remove(const D & d)
{
    node **n;
    if(!find(n,d)) return false;
    return (delete_bst(n,d));
}
template<class D>
D & bst<D>::operator[](const D & d)
{
    node ** n;
    if(!find(n,d))
        *n = new node (d);
    return (*n) -> data;
}
template<class D>
bst<D>::~bst<D>()
{
    while(p_root != nullptr)
    {
        remove(p_root->data);
    }
}

