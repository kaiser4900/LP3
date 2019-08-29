#include<iostream>
#include<ctime>
#include<algorithm>
#include<stdlib.h>
#include<cassert>
using namespace std;
class Linked_list_array
{
    private:

	int *p_head;
        size_t size = 0;
	public:

		Linked_list_array ()
		{
            p_head = new int[10000000];
        }

		~Linked_list_array()
		{
		     delete [] p_head;
        }
        int size_p()
        {
            return size;
        }
        int & operator() ( size_t index)
        {
            assert(index<size);
            return p_head[index];
        }
        void push_back(const int &a)
        {
            size++;
            p_head[size] = a;
        }
        void push_front(const int &a)
        {
            size++;
            int * aux = new int[size+5];
            aux[size] = '\0';
            for(int i = 0; i < size; i++)
            {
                aux[i] = p_head[i];
            }
            p_head[0] = a;
            for(int i = 1; i <= size; i++)
            {
                p_head[i] = aux[i-1];
            }
            delete [] aux;
        }
        void insert(int const &d, int pos)
        {
            size++;
            int * aux = new int[size+5];
            aux[size] = '\0';

            for(int i = 0; i < size; i++)
            {
                aux[i] = p_head[i];
            }
            p_head[pos] = d;

            for(int i = pos; pos <= size; pos++)
            {
                aux[pos+1] = p_head[pos];
            }
            for(int i = 0; i < size; i++)
            {
                p_head[i] = aux[i];
            }
            delete [] aux;
        }
        void remove(int pos)
        {
            if(pos < size)
            {
                if(pos == 0)
                {
                    pop_front();
                }
                else if(pos == size-1)
                {
                    pop_back();
                }
                else
                {
                    int * aux = new int[size+5];
                    aux[size] = '\0';
                    for(int i = 0; i < size; i++)
                    {
                        aux[i] = p_head[i];
                    }
                    for(int i = pos; i < size; i++)
                    {
                        p_head[pos] = aux[pos+1];
                    }
                    size--;
                    delete [] aux;
                }
            }
        }
        void pop_back()
        {
            size--;
            p_head[size-1] = '\0';
        }
        void pop_front()
        {
            int * aux = new int[size+5];

            for(int i = 0; i < size; i++)
            {
                aux[i] = p_head[i];
            }
            size--;
            for(int i = 0; i < size; i++)
            {
                p_head[i] = aux[i+1];
            }
            delete [] aux;
        }
        int find(int data)
        {
            for(int i = 0; i < size; i++)
            {
                if(data == p_head[i])
                {
                    return i;
                }
            }
            return -1;
        }
};
class linked_list_1
{
public:
    struct node
    {
        int d;
        node * p_next;
        node(const int & D, node *n)
        {
            d = D;
            p_next = n;
        }
    };
private:
    node * p_head;
    size_t size_ = 0;
public:

linked_list_1(): p_head(nullptr){}
~linked_list_1()
{
    node * del = p_head;
    while(del)
    {
        p_head = del -> p_next;
        delete del;
        del = p_head;
    }
}
void push_back(const int &data)
{
	insert(data,size_);
}
void push_front(const int&data)
{
	insert(data,0);
}
void insert (const int &data,int pos)
{
    int cont = 0;
    node * it = p_head;
    if(!p_head)
    {
		p_head = new node (data,nullptr);
    }
    else
    {
	if(pos == 0)
	{
	   node* new_node = new node(data, p_head);
	   p_head = new_node;
	}
	else if(pos+1 == size_ || pos >= size_)
	{
	node* aux = p_head;
	   for(int i = 1; i < size_; i++)
	   {
	   	aux = aux -> p_next;
	   }
	   node* new_node = new node(data, nullptr);
	   aux -> p_next  = new_node;
	}

	else
	{
	   node * aux = p_head;
	   for(int i = 1; i < pos; i++)
	   {
	   	aux = aux -> p_next;
	   }
	   node * new_node = new node(data,nullptr);
	   node * aux2 = aux -> p_next;
	   aux -> p_next = new_node;
	   new_node -> p_next = aux2;
	}
    }
	size_++;
}
int & operator []( int i)
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
    return back->d;
}

void remove(int pos)
{
    int cont = 0;
    node * del = p_head;
    if(pos == 0)
    {
    	node * aux = p_head;
    	if(p_head -> p_next)
    	{
    		p_head = aux -> p_next;
    	}
    	else
    		p_head = nullptr;
    }
    else if (pos + 1 == size_)
    {
    	for(int i = 1; i < pos; i++)
    	{
    		del = del -> p_next;
    	}
    	node * aux = del;
    	del = del -> p_next;
    	aux -> p_next = nullptr;
    	delete del;
    }
    else if (pos >= size_)
    {
    	//no hacer nada
    }
    else
    {
    	for(int i = 1; i < pos; i++)
    	{
    		del = del -> p_next;
    	}
    	node * aux = del;
    	del = del -> p_next;
    	aux -> p_next = del -> p_next;
    	delete del;
    }
    size_--;
}
int size_p()
{
	return size_;
}
int find (int D)
{
    node * aux = p_head;
    int cont = 0;
    for(cont=0; cont < size_;cont++)
    {
	if(aux->d == D)
	{
		break;
	}
	else if(aux->p_next)
		aux = aux -> p_next;
    }
    if(cont == size_)
    	cont = -1;

return cont;
}
};
class linked_list_2
{
public:
    struct node
    {
        int d;
        node * p_next;
        node * p_prev;
        node(const int & D,node *p, node *n)
        {
            p_prev = p;
            d = D;
            p_next = n;
        }
    };
private:
    node * p_head;
    size_t size_ = 0;
public:

linked_list_2(): p_head(nullptr){}
~linked_list_2()
{
    node * del = p_head;
    while(del)
    {
        p_head = del -> p_next;
        delete del;
        del = p_head;
    }
}
int size_p()
{
	return size_;
}
int & operator []( int i)
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
    return back->d;
}
void push_front(const int & d)
{
    p_head = new node (d,nullptr ,p_head);
    node * aux = p_head;
    if(aux -> p_next)
    {
        aux = aux -> p_next;
        aux->p_prev = p_head;
    }
    size_++;
}
void push_back(const int & d)
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
	size_++;
    }
    else
    {
        push_front(d);
    }
}
void insert (const int &d,int pos)
{
    if(pos == 0)
    {
        push_front(d);
    }
    else if (pos == size_)
    {
        push_back(d);
    }
    else
    {
        int cont = 0;
	node * aux = p_head;
        while(cont <= pos)
        {
            //cuando es excedente
            if(cont == size_)
            {
                push_back(d);
                break;
            }
	    if(cont == pos)
	    {
		node * new_node = new node (d,aux->p_prev,aux);
		node * aux2 = aux;
		aux = aux -> p_prev;
		aux -> p_next = new_node;
		aux2 -> p_prev = new_node;
	    }
            cont++;
	    aux = aux -> p_next;
        }
	size_++;
    }
}
int find (int D)
{
    node * aux = p_head;
    int cont = 0;
    for(cont=0; cont < size_;cont++)
    {
	if(aux->d == D)
	{
		break;
	}
	else if(aux->p_next)
		aux = aux -> p_next;
    }
    if(cont == size_)
    	cont = -1;

return cont;
}
void remove(int pos)
{
    int cont = 0;
    node * del = p_head;
    while(del)
    {
        if(pos == cont)
        {
	    if(del -> p_next && del -> p_prev)
	    {
		node * aux1 = del->p_prev;
		node * aux2 = del -> p_next;
		aux1 -> p_next = aux2;
		aux2 -> p_prev = aux1;
		delete del;
		break;
	    }
	    else if(del -> p_prev && ! del -> p_next)
	    {
		node * aux = del->p_prev;
		delete del;
		aux -> p_next = nullptr;
		break;
            }
	    else if(!del -> p_prev && del -> p_next)
	    {
		p_head = p_head -> p_next;
		p_head -> p_prev = nullptr;
		delete del;
		break;
	    }
        }
        else
        {
	    if(del -> p_next)
	    {
		del = del->p_next;
		cont++;
	    }
	    else
		break;
        }
    }
    size_--;
}
};
void tempo(int m)
{
    int stop;
	cin >> stop;
	srand(time(NULL));

	Linked_list_array s;
	linked_list_1 b;
	linked_list_2 c;

	cout<<m<<")   ---------------------------"<<endl;

	for(int i = 0; i < stop; i++)
	{
		int a = rand()%51;
		s.push_back(a);
		b.push_back(a);
		c.push_back(a);
	}
	cout<<"------------------front------------------"<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	clock_t t = clock();
	s.push_front(1);
	float time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de array: "<<time<<" "<<endl;
	t = clock();
	b.push_front(1);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de simple: "<<time<<" "<<endl;
	t = clock();
	c.push_front(1);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de doble: "<<time<<" "<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	cout<<"------------------back------------------"<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	t = clock();
	s.push_back(1);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de array: "<<time<<" "<<endl;
	t = clock();
	b.push_back(1);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de simple: "<<time<<" "<<endl;
	t = clock();
	c.push_back(1);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de doble: "<<time<<" "<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	cout<<"------------------insert------------------"<<endl;

	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	t = clock();
	for(int i = 0; i < 10; i++)
	{
		int a = rand()%51;
		s.insert(a,a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de array: "<<time<<" "<<endl;
	t = clock();
	for(int i = 0; i < 10; i++)
	{
		int a = rand()%51;
		b.insert(a,a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de simple: "<<time<<" "<<endl;
	t = clock();
	for(int i = 0; i < 10; i++)
	{
		int a = rand()%51;
		c.insert(a,a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de doble: "<<time<<" "<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	cout<<"------------------remove_front------------------"<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	t = clock();
	s.remove(0);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de array: "<<time<<" "<<endl;
	t = clock();
	b.remove(0);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de simple: "<<time<<" "<<endl;
	t = clock();
	c.remove(0);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de doble: "<<time<<" "<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	cout<<"------------------remove_back------------------"<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	t = clock();
	s.remove(s.size_p()-1);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de array: "<<time<<" "<<endl;
	t = clock();
	b.remove(s.size_p()-1);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de simple: "<<time<<" "<<endl;
	t = clock();
	c.remove(s.size_p()-1);
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de doble: "<<time<<" "<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	cout<<"------------------remove_srand------------------"<<endl;

	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	t = clock();
	for(int i = 0; i < 10; i++)
	{
		int a = rand()%stop-1;
		s.remove(a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de array: "<<time<<" "<<endl;
	t = clock();
	for(int i = 0; i < 10; i++)
	{
		int a = rand()%stop-1;
		b.remove(a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de simple: "<<time<<" "<<endl;
	t = clock();
	for(int i = 0; i < 10; i++)
	{
		int a = rand()%stop-1;
		c.remove(a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de doble: "<<time<<" "<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	cout<<"------------------find_srand------------------"<<endl;

	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;
	t = clock();
	for(int i = 0; i < 100; i++)
	{
		int a = rand()%stop-1;
		s.find(a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de array: "<<time<<" "<<endl;
	t = clock();
	for(int i = 0; i < 100; i++)
	{
		int a = rand()%stop-1;
		b.find(a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de simple: "<<time<<" "<<endl;
	t = clock();
	for(int i = 0; i < 100; i++)
	{
		int a = rand()%stop-1;
		c.find(a);
	}
	time = float(clock()-t)/CLOCKS_PER_SEC;
	cout<<"time de doble: "<<time<<" "<<endl;
	cout<<s.size_p()<<endl;
	cout<<b.size_p()<<endl;
	cout<<c.size_p()<<endl;

}
int main()
{
    while (true)
    {
	int m=1;
        tempo(m);
	m++;
    }
    system("pause>nul");
	return 0;
}

