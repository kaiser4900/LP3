#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue < int > gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);

    cout << "The queue gquiz is : " ;


    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();

    cout << "\ngquiz.pop() : " ;
    gquiz.pop();

    for(int i = 0; i < 3; i++)
    {
        cout<<i<<" = "<<gquiz.pop()<<endl;
    }

  return 0;
}
