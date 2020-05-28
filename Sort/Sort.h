#ifndef __SORT_H__
#define __SORT_H__
#include<ctime>
class Sort
{
typedef void(*sortFun)(int *data, int len);
public:
    //测试是否为排序好的序列
    static bool IsSorted(int *data, int len);
    //测试排序算法的性能
    //sf 排序算法的地址
    //len 测试的序列的长度
    //seed 随机种子
    static void testSort(sortFun sf, int len=10000, int seed=time(0));
    static void show(int *data, int len);
    static void BubbleSort(int *data, int len);//冒泡排序
    static void InsertSort(int *data, int len);//插入排序
    static void SelectSort(int *data, int len);//选择排序
    static void QuickSort(int *data, int len); //快速排序
    static void MergeSort(int *data, int len); //归并排序
    static void HeapSort(int *data, int len);  //堆排序
    static void ShellSort(int *data, int len); //希尔排序
    static void RadixSort(int *data, int len); //基数排序
    static void BucketSort(int *data, int len); //桶排序
protected:
    //生成随机的序列
    static void quicksort(int *data, int l, int r);
    static void mergesort(int *src, int *dsc, int step, int n);
    static void Merge(int *src, int *dsc, int l, int m, int r);
    static void randList(int *data, int len, int seed);  
    static int maxdigit(int *data, int len); //得到最大的位数
    static void get_max_min(int *data, int n, int *pa);//得到一组数据中最大最小值，pa传入传出参数
    static int BucketIndex(int value, int min, int width=100);//得到元素在桶中的下标
};
#endif