#include "Solution.h"

/**
 * String
 * No.28 Implement strStr()
 */
int strStr(char *haystack, char *needle) 
{
    string str1(haystack);
    string str2(needle);
    return str1.find(str2);
}