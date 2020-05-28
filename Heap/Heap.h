#ifndef __HEAP_H__
#define __HEAP_H__

class SequenceHeap
{
private:
    int *m_data;
    int m_size;
public:
    SequenceHeap();
    void Sort(int *data, int len);
    ~SequenceHeap(){delete[] m_data;}
protected:
    void Push(int value);
    void Pop();
    int top();
};

// class HeapNode
// {
// friend class HeapTree;
// private:
//     int m_value;
//     HeapNode *lchild;
//     HeapNode *rchild;
//     HeapNode *parent;
// protected:
//     HeapNode(int value)
//     {
//         m_value = value;
//         lchild = rchild = parent = nullptr;
//     }
// };

// class HeapTree
// {
// private:
//     HeapNode *m_root;
// public:
//     HeapTree
// };

#endif
