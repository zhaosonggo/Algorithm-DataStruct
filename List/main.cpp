#include"List.h"
int main()
{
    int data[] = {5, 4, 3, 2, 1};
    List mL(data, 5);
    mL.show();
    BList bL(data, 5);
    bL.show();
    return 0;
}