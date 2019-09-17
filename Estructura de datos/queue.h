#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"
using namespace std;

template<class T>
class Queue
{
private:
    linked_list<T> queque;
public:

	Queue(){}
	Queue(string p)
	{
		for(int i = 0; i < p.size(); i++)
		{
			queque.push_back(p[i]);
		}

	}
	int size()
	{
		return queque.size();
	}
	void push_back(T a)
	{
		queque.push_back(a);
	}
	void push_front(T a)
	{
		queque.push_front(a);
	}
	T pop_back()
	{
	    T aux = queque[0];
		queque.remove_back();
		return aux;
	}
	T pop_front()
	{
	    T aux = queque[queque.size()-1];
		queque.remove_front();
		return aux;
	}
	T front()
	{
		return queque[queque.size()];
	}
	T back()
	{
		return queque[0];
	}

	/*T & operator []( int i)
	{
		return queque[i];
	}*/
};
#endif

