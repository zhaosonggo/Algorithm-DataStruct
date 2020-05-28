#include"Heap.h"
#include<iostream>
using namespace std;

int main()
{
    int data[] = {3, 4, 1, 0, 9, -1, 2, 3};
    SequenceHeap mSh;
    for(int i=0;i<8;i++)
        cout<<data[i]<<",";
    cout<<endl;
    mSh.Sort(data, 8);
    for(int i=0;i<8;i++)
        cout<<data[i]<<",";
    cout<<endl;
    return 0;
}