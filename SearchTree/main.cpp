#include"SearchTree.h"
#include<iostream>
using namespace std;
int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7};
    SearchTree mSt(data, 7);
    mSt.InOrder();
    mSt.PreOrder();
    TreeNode *p = mSt.Search(10);
    if(p)
    {
        cout<<p->getValue()<<endl;
    }else{
        cout<<"unexisted\n";
    }
    //左旋的测试
    cout<<mSt.depath();
    mSt.leftRotate();
    cout<<mSt.depath();
    mSt.leftRotate();
    mSt.leftRotate();
    mSt.leftRotate();
    mSt.leftRotate();
    mSt.leftRotate();
    mSt.leftRotate();
    cout<<mSt.depath();
    mSt.rightRotate();
    mSt.leftRotate();
    mSt.rightRotate();
    cout<<mSt.depath()<<endl;
    mSt.leftRotate();
    cout<<mSt.depath()<<endl;
    mSt.rightRotate();
    cout<<mSt.depath()<<endl;
    return 0;
}