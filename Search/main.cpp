#include"Search.h"
#include<iostream>
using namespace std;

int main()
{
    int data[10];
    for(int i =0;i<10;i++)
        data[i] = i+1;
    for(int i =0;i<10;i++)
        cout<<data[i]<<", ";
    cout<<endl;

    BinarySearch bs;
    for(int i = -5; i<15;i++)
        cout<<"search "<<i+1<<" result: "<<bs.Search(data, i+1, 10)<<"\n";
    return 0;
}