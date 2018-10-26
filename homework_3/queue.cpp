#include <iostream>
#include <queue>
#include <assert.h>

using namespace std;

int main()
{
queue <int> myQ;

cout<< "现在 queue 是否 empty? "<< myQ.empty() << endl; 

for(int i =0; i<10 ; i++)
{
myQ.push(i);
}
for(int i=0; i<myQ.size(); i++)
{
//printf("myQ.size():%d\n",myQ.size());
cout << myQ.front()<<endl;
myQ.pop();
}


return 0;
}
