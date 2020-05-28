#ifndef __LIST_H__
#define __LIST_H__
#include<iostream>
class ListNode
{
friend class List;
private:
    int value;
    ListNode *next;
    ListNode(int v):value(v), next(nullptr){}
};
class List
{   
private:
    ListNode *m_head;
public:
    List();
    List(int *data, int len);
    ListNode * Insert(int value); //头插法
    ~List();
    void show(); //显示所有的数据
};


class BListNode
{
friend class BList;
private:
    int value;
    BListNode *next;
    BListNode *before;
    BListNode(int v):value(v), next(nullptr), before(nullptr){}
    // ~BListNode()
    // {
    //     std::cout<<"0";
    // }
};

class BList  //模仿STL里面的list制作双向环状链表
{
private:
    BListNode *node;
public:
    BList(int *data, int len);
    BListNode *Insert(int value);
    void show();
    ~BList();
};
#endif

