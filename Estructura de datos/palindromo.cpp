#include <iostream>
#include "queue.h"
using namespace std;
int main()
{
	string palabra;
	cin>>palabra;
	Queue<char> q(palabra);
	int cont = 0;
	for(int i = 0; i < palabra.size()/2; i++)
	{
		int j = q.size()-1;
		if(q[0] == q[j])
		{
			cont++;
			q.pop_front();
			q.pop_back();
		}
	}
	if(cont >= q.size()-1/2)
	{
		cout<<"palindromo"<<endl;
	}
	else
		cout<<"no es palindromo"<<endl;
    return 0;
}
