#include"Sort.h"
#include<cstdlib>
#include<iostream>
using namespace std;
bool Sort::IsSorted(int *data, int len)
{   
    int i = 0;
    for(;i+1<len;i++)
    {
        if(data[i] > data[i+1])
            return false;
    }
    return true;
}
void Sort::testSort(sortFun sf, int len, int seed)
{
    if(sf == nullptr || len<=0)
        return;
    int *data = new int[len];
    randList(data, len, seed);
    clock_t t_start = clock();  //ms级别
    sf(data, len);
    clock_t t_end = clock();
    cout<<"________________\n";
    cout<<"|Test Result:\n";
    cout<<"|---->sorted: "<<(IsSorted(data, len)?"Yes":"NO")<<endl;
    cout<<"|---->time: "<<t_end - t_start<<endl;
    cout<<"________________\n";
    delete[] data;
}

void Sort::randList(int *data, int len, int seed)
{
    int start = 0;
    int end = len;
    srand(seed);  //设置随机种子
    for(int i=0;i<len;i++)
    {
        data[i] = rand() % (end - start + 1) + start;
    }
}

void Sort::show(int *data, int len)
{
    for(int i=0;i<len;i++)
        cout<<data[i]<<", ";
    cout<<endl;
}
//冒泡排序
void Sort::BubbleSort(int *data, int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=1;j<len-i;j++)
        {
            if(data[j-1] > data[j])
            {
                int tmp = data[j-1];
                data[j-1] = data[j];
                data[j] = tmp;
            }
        }
    }
}
//插入排序
void Sort::InsertSort(int *data, int len)
{
    for(int i=1;i<len;i++)
    {
        int tmp = data[i];
        int j = i;
        for(;j>0;j--)
        {
            if(data[j-1]>tmp)
            {
                data[j] = data[j-1];
            }else{
                break;
            }
        }
        data[j] = tmp;
    }
}
//选择排序
void Sort::SelectSort(int *data, int len)
{
    for(int i=0;i<len-1;i++)
    {
        int index = i;
        for(int j=i+1;j<len;j++)
        {
            if(data[index] > data[j])
                index = j;
        }
        int tmp = data[i];
        data[i] = data[index];
        data[index] = tmp;
    }
}
//快速排序
void Sort::QuickSort(int *data, int len)
{
    quicksort(data, 0, len-1);
}

void Sort::quicksort(int *data, int l, int r)
{
    if(l<r)
    {
        int i = l, j = r, x = data[l];
        while(i<j)
        {
            while(i<j && data[j] >= x)
                j--;
            if(i < j)
                data[i++] = data[j];
            while(i<j && data[i] <= x)
                i++;
            if(i < j)
                data[j--] = data[i];
        }
        data[i] = x;
        quicksort(data, l, i-1);
        quicksort(data, i+1, r);
    }   
}

//归并排序
void Sort::MergeSort(int *data, int len)
{
    int *tmp = new int[len];
    for(int step=1;step<len;step*=2)
    {
        mergesort(data, tmp, step, len);
        step*=2;
        mergesort(tmp, data, step, len);
    }
    delete [] tmp;
}
#include<algorithm>
void Sort::mergesort(int *src, int *dsc, int step, int n)
{
    int i=0;
    for(i;i<n-2*step;i+=2*step)
    {
        Merge(src, dsc, i, i+step-1, i+2*step-1);
    }
    if((i+step-1)<(n-1))
    {
        Merge(src, dsc, i, i+step-1, n-1);
    }else{
        std::copy(src+i, src+n, dsc+i);
    }
}
void Sort::Merge(int *src, int *dsc, int l, int m, int r)
{
    int i = l;
    int j = m+1;
    int index = l;
    for(;i<=m&&j<=r;)
    {
        if(src[i]<src[j])
            dsc[index++] = src[i++];
        else
            dsc[index++] = src[j++];
    }
    std::copy(src+i, src+m+1, dsc+index);
    std::copy(src+j, src+r+1, dsc+index);
}

//希尔排序
void Sort::ShellSort(int *data, int len)
{
    int gap = 1;
    while(gap<len/2)
    {
        gap *= 2;
    }
    for(;gap!=0;gap/=2)
    {
        for(int i=gap;i<len;i+=gap)
        {
            int j = i;
            int tmp = data[i];
            for(;j>0;j-=gap)
            {
                if(data[j-gap] > tmp)
                {
                    data[j] = data[j-gap];
                }else break;
            }
            data[j] = tmp;
        }
    }
}
//堆排序
#include "Heap.h"  //调用Heap
void Sort::HeapSort(int *data, int len)
{
    SequenceHeap myHeap;
    myHeap.Sort(data, len);
}

//基数排序
#include<list>
using namespace std;
void Sort::RadixSort(int *data, int len)
{
    int digits = maxdigit(data, len);
    list<int> lists[10]; //十进制嘛
    int d, j, k, factor;
    for(d = 1, factor = 1;d<=digits;factor*=10, d++)
    {
        for(j=0;j<len;j++)
        {
            lists[(data[j]/factor)%10].push_back(data[j]);
            //取到某一位的数字
        }
        for(j=k=0;j<10;j++)
        {
            while(!lists[j].empty())
            {
                data[k++] = lists[j].front();
                lists[j].pop_front();
            }
        }
    }
}
int Sort::maxdigit(int *data, int len)
{
    int d = 1;
    int p = 10;
    for(int i = 0;i<len;i++)
    {
        if(data[i] >= p)
        {
            d++;
            p *= 10;
        }
    }
    return d;
}
//桶排序
void Sort::BucketSort(int *data, int len)
{
    int pa[2]; //pa[0] == min ;pa[1] == max
    get_max_min(data, len, pa);
    int num = BucketIndex(pa[1], pa[0]) + 1;  //最大元素在桶中的下标+1就是桶的个数
    list<int> lists[num];
    for(int i=0;i<len;i++)  // 将映射关系满足的数据放到对应的桶里边
        lists[BucketIndex(data[i], pa[0])].push_back(data[i]);
    for(int i=0;i<num;i++) //每个桶用对应的排序算法
        lists[i].sort(); //由于list是单项迭代器，不可以使用algorithm下的sort
    for(int j=0, i=0;j<num;j++)
        for(auto p:lists[j])
            data[i++] = p;
}

void Sort::get_max_min(int *data, int len, int *pa)
{
    int max = data[0];
    int min = data[0];
    for(int i=1;i<len;i++)
    {
        if(data[i] > max)
            max = data[i];
        if(data[i] < min)
            min = data[i];
    }
    pa[0] = min;
    pa[1] = max;
}

int Sort::BucketIndex(int value, int min, int width)
{
    return (value - min)/width;
}