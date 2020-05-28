#include"Search.h"

bool BinarySearch::Search(int *data, int target, int len)
{
    if(data == nullptr || len <=0)
        return false;
    int i = 0;
    int j = len-1;
    while(i<=j)
    {
        int index = (i + j)/2;
        if(data[index] > target)
            j = index-1;
        if(data[index] < target)
            i = index+1;
        if(data[index] == target)
            return true;
    }
    return false;
}