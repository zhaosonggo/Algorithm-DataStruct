#include"BinaryTree.h"
#include<iostream>
using namespace std;
int main()
{
    int data[] = {1, 2, 3, -1, 4, 5, 6, 7, 8, -1, 9};
    BinaryTree myB(data, 11);
    myB.ProOrderRecursive();
    myB.PreOrder();
    myB.InOrderRecursive();
    myB.InOrder();
    myB.PostOrderRecursive();
    myB.PostOrder();
    myB.LayerOrder();
    cout<<"node count: "<<myB.size()<<endl;
    cout<<"leftNumber: "<<myB.LeafNumber()<<endl;
    cout<<"depath: "<<myB.depath()<<endl;
    cout<<"max: "<<myB.max()<<endl;
    cout<<"min: "<<myB.min()<<endl;
    int data2[] = {1, 2, 4, -1, -1, -1, 3, -1, -1};
    myB.PreCreate(data2, 9);
    myB.PreOrder();
    int data3[] = {-1, -1, 4, -1, 2, -1, -1, 3, 1};
    myB.PostCreate(data3, 9);
    myB.PreOrder();
    int pre[] = {1, 2, 4, 9, 8, 3, 5, 9, 6};
    int in[] = {2, 7, 4, 8, 1, 5, 9, 3, 6};
    myB.PreInCreate(pre, in, 9);
    myB.PreOrder(); 
    int post[] = {7, 8, 4, 2, 9, 5, 6, 3, 1};
    myB.PostInCreate(post, in, 9);
    myB.PreOrder();
    return 0;
}