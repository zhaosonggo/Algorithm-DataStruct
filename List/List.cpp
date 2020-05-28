#include"List.h"
#include<iostream>
using namespace std;

List::List()
{
    m_head = nullptr;
}
List::List(int *data, int len)
{
    m_head = nullptr;
    for(int i = 0;i<len;i++)
        m_head = Insert(data[i]);
}
List::~List()
{
    if(m_head)
    {
        ListNode *p;
        while(m_head)
        {
            p = m_head->next;
            delete m_head;
            m_head = p;           
        }
    }    
}
ListNode *List::Insert(int value)
{
    ListNode *p = new ListNode(value);
    p->next =  m_head;
    m_head = p;
    return p;
}

void List::show()
{
    ListNode *p = m_head;
    while(p)
    {
        cout<<p->value<<", ";
        p = p->next;
    }
    cout<<endl;
}

BList::BList(int *data, int len)
{
    node = new BListNode(0);
    node->next = node;
    node->before = node;
    for(int i = 0; i<len; i++)
    {
        Insert(data[i]);
    }
}

BListNode * BList::Insert(int value)
{
    // BListNode *p = node;  //尾插法
    // while(p->next != node)
    //     p = p->next;
    // BListNode *q = new BListNode(value);
    // p->next = q;
    // q->before = p;
    // q->next = node;
    // node->before = q;
    BListNode *p = new BListNode(value);  //头插法
    p->next = node->next;
    node->next->before = p;
    node->next = p;
    p->before = node;
}

void BList::show()
{
    BListNode *p = node->next;
    while(p!=node)
    {
        cout<<p->value<<", ";
        p = p->next;
    }
    cout<<endl;
}

BList::~BList()
{
    BListNode *q, *p = node->next;
    while(p!=node)
    {
        q = p->next;
        delete p;
        p = q;
    }
    delete node;
}