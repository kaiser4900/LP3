#include"bst.h"
#include<iostream>

using namespace std;

int main()
{
    bst<int> m;
	m.insert(11);
	m.insert(9);
	m.insert(14);
	m.insert(13);
	m.insert(12);
	m.insert(17);
	m.insert(10);
	m.insert(6);
	m.remove(14);
    return 0;
}
