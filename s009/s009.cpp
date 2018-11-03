//
// Created by skl on 2018/9/16.
//

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
 */

bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    if(x == 0)
        return true;
    char str[16];
    memset(str, 0, 16);
    int index = 0;
    while(x > 0)
    {
        str[index++] = x % 10;
        x = x / 10;
    }
    for(int t = 0; t < index / 2; t ++)
    {
        if(str[t] != str[index - t -1 ])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    printf("%d\n", isPalindrome(121));
    printf("%d\n", isPalindrome(1221));
    printf("%d\n", isPalindrome(-121));
    printf("%d\n", isPalindrome(10));
    printf("%d\n", isPalindrome(0));
    return 0;
}