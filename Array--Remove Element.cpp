#include "Solution.h"
#include <math.h>
using namespace std;

/**
 * NO. 27 Remove Element
 * 采用位法，将符合条件的元素对位，抛弃不符合条件的元素
 */
int removeElement(int A[], int n, int elem)
{
    int index = 0;
    for(int i = 0; i < n; ++i)
    {
        if(A[i] != elem)
            A[index++] = A[i];
    }
    return index;
}

