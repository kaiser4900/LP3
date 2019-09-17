#include "linked_list.h"
template<class T>
struct linked_list<T>::node
{
    T dato;
    node * p_next;
    node * p_prev;
    node(const T & d,node *p, node *n)
    {
        p_prev = p;
        dato = d;
        p_next = n;
    }
};
template<class T>
struct linked_list<T>::iterator
{
    node * n;
    public:
    iterator(node * n_ = nullptr)
    {
        n = n_;
    }
    ~iterator() = default;
    T & operator *()
    {
        return n->dato;
    }
    iterator & operator ++()
    {
        n = n->p_next;
        return *this;
    }
    iterator & operator --() //tarea completada
    {
        n = n->p_prev;
        return *this;
    }
    bool operator != (const iterator & it)
    {
        return n!= it.n;
    }
};
template<class T>
linked_list<T>::~linked_list<T>()
{
    node * del = p_head;
    while(del)
    {
        p_head = del -> p_next;
        delete del;
        del = p_head;
    }
}
template <class T>
class linked_list<T>::iterator linked_list<T>::begin()
{
    return iterator (p_head);
}

template<class T>
class linked_list<T>::iterator linked_list<T>::end()
{
    node * back;
    back = p_head;
    while (back)
    {
          back = back ->p_next;
          if(!back->p_next)
              return iterator (back);
    }
}
template<class T>
T & linked_list<T>::operator[](int i)
{
    int j=0;
    node * back;
    back = p_head;
    if(i != 0)
    {
        while (j<i)
        {
              back = back ->p_next;
              j++;
        }
    }
    return back->dato;
}
template <class T>
int linked_list<T>::size()
{
    node * cont;
    cont = p_head;
    int i = 0;
    if(cont)
    {
    	i++;
    }
    while (cont)
    {
          if(cont ->p_next)
          {
                cont = cont ->p_next;
                i++;
          }
          else
              return i;
    }
	return i;
}
template <class T>
void linked_list<T>::push_front(const T & d)
{
    p_head = new node (d,nullptr ,p_head);
    node * aux = p_head;
    if(aux -> p_next)
    {
        aux = aux -> p_next;
        aux->p_prev = p_head;
    }
}
template<class T>
void linked_list<T>::remove(iterator it)
{
node * del = it.n;

    if( del->p_prev && del->p_next)
    {
        node * prev = del->p_prev;
        node * next = del->p_next;
        prev -> p_next = next;
        next -> p_prev = prev;
        delete del;
    }
    else if (del == p_head) {
        remove_front();
        //it = p_head;
    }
    else {
        remove_back();
    }
}
template <class T>
void linked_list<T>::remove_front()
{
    if(p_head!=nullptr)
    {
        node * del = p_head;
        if(p_head -> p_next)
        {
            p_head = p_head -> p_next;
        }
        delete del;
        p_head -> p_prev = nullptr;
    }
}
template <class T>
void linked_list<T>::push_back(const T & d)
{
    if(p_head)
    {
        node * back = p_head;
        bool  aux = true;
        while(aux)
        {
            if(back -> p_next == nullptr)
            {
                 back -> p_next  = new node (d,back,nullptr);
                 aux = false;
            }
            else
                back = back -> p_next;
        }
    }
    else
    {
        push_front(d);
    }

}
template<class T>
void linked_list<T>::remove_back()
{
    if(p_head!=nullptr)
    {
        node * back = p_head;
        bool  aux = true;
        while(aux)
        {
			if(back -> p_next)
			{
				back = back -> p_next;
			}
			else
				break;
            if(back -> p_next == nullptr)
            {
                node * del = back;
                back = back -> p_prev;
                back -> p_next = nullptr;
                delete del;
                aux = false;
            }
        }
    }
}
