#include<iostream>
#include"Heap.h"
SequenceHeap::SequenceHeap()
{
    m_data = nullptr;
    m_size = 0;
}
void SequenceHeap::Sort(int *data, int len)
{
    if(m_data != nullptr)
    {
        delete [] m_data;
        m_size = 0;
    }   
    m_data = new int[len+1];  //0为空位
    for(int i=0;i<len;i++)
    {
        Push(data[i]);
    }
    // for(int i=1;i<=m_size;i++)
    // {
    //     std::cout<<m_data[i]<<"|";
    // }
    // std::cout<<std::endl;
    for(int i=0;i<len;i++)
    {
        data[i] = top();
        Pop();
    }
}
void SequenceHeap::Push(int value)
{
    ++m_size; //元素的个数加一
    int i = m_size; //同时size+1后也是本次最后一个插入后元素的下标（从下标1开始插入）
    for(;i/2>0;i/=2) //如果没有父节点就停止， 且每一次都变为其父节点
    {
        if(value < m_data[i/2])
        {
            m_data[i] = m_data[i/2]; //下移父节点的值
        }else{
            break;
        }
    }
    m_data[i] = value;
}

int SequenceHeap::top()
{
    return m_data[1]; //返回树根的元素
}

void SequenceHeap::Pop()
{
    // m_data[1] = m_data[m_size--];  //将最后一个元素移动到头部
    // int tmp = m_data[1];
    int value = m_data[m_size--];
    int i=1;
    for(;i<=m_size/2;)  //i<=m_size/2 代表至少该节点要存在一个子节点
    {
        if(2*i == m_size) //如果只有左节点
        {
            if(value > m_data[2*i])
            {
                m_data[i] = m_data[2*i];
                i = 2*i;
            }else{
                break;
            }
        }else{ //既有左节点，也有右节点
            int index = m_data[2*i]<m_data[2*i+1]? 2*i:2*i+1; //得到子节点中比较大的节点的下标
            if(value > m_data[index])
            {
                m_data[i] = m_data[index];
                i = index;
            }else{
                break;
            }
        }
    }
    m_data[i] = value;
}