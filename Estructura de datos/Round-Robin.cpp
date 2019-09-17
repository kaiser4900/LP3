#include<iostream>
#include"queue.h"
#include <fstream>

using namespace std;
class proceso
{
private:
    string name;
    int time;
public:
    proceso(string name_ = "none", int time_ = 0)
    {
        name = name_;
        time = time_;
    }
    string get_n()
    {
        return name;
    }
    int get_t()
    {
        return time;
    }
    void set_t(int time2)
    {
        time = time2;
    }
    template<class A>
    friend ostream & operator << (ostream & os, A &s)
    {
        return os << s.name<< " " <<s.time;
    }
    template<class A>
    friend istream & operator>> (istream & is, A &s)
    {
        return is >> s.name>>s.time;
    }
};
template<class A>
void save_queue(Queue<A>vs)
{
    ofstream ficheroSalida;
    ficheroSalida.open ("procesos.txt");
    for(int i = 0; i < vs.size(); i++)
    {
        ficheroSalida << vs[i]<<endl;
    }
    ficheroSalida.close();
}
template<class A>
void load_queue(Queue<A>&va)
{
    ifstream ficheroEntrada;
    A num;
    ficheroEntrada.open("procesos.txt");
    while (ficheroEntrada >> num)
    {
    	va.push_back(num);
    }
    ficheroEntrada.close();
}
template<class A>
void Robin(Queue<A>&ip, int time)
{
    Queue<int> bv;
    bv.push_back(1);
    bv.push_back(2);
    bv.push_back(3);
    bv.push_back(4);
    bv.push_back(5);
    bv.push_back(6);

    for(int i = 0; i < 5; i++)
    {
        cout<<bv.pop_front()<<endl;
    }
}
int main()
{
    int k = 0, t = 0;
    string input;
    cout<<"cant: ";
    cin>>k;
    Queue<proceso> ip;
    for(int i = 0; i < k; i++)
    {
        cin>>input;
        cin>>t;
        proceso a(input,t);
        ip.push_back(a);
    }
    load_queue(ip);


    int time;
    cout<<"Valor de Quantum: ";
    cin>>time;
    Robin(ip,time);
    return 0;
}
