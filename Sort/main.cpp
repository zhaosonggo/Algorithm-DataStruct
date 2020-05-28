#include<iostream>
#include"Sort.h"
using namespace std;
int main()
{   
    // Sort::testSort(Sort::InsertSort, 50000, 666);
    Sort::testSort(Sort::QuickSort, 50000, 666);
    // Sort::testSort(Sort::SelectSort, 50000, 666);  
    // Sort::testSort(Sort::MergeSort, 50000, 666);  
    // Sort::testSort(Sort::ShellSort, 50000, 666);  
    Sort::testSort(Sort::HeapSort, 50000, 666);
    Sort::testSort(Sort::RadixSort, 50000, 666);
    Sort::testSort(Sort::BucketSort, 50000, 666);
    return 0;
}