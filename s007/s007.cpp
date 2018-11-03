//
// Created by skl on 2018/9/16.
//

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
};

/*
 * 示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
 */
int reverse(int x)
{
    const int maxIntValue = pow(2, 31) - 1;
    const int minIntValue = -pow(2, 31);
    if(minIntValue == x)
    {
        return 0;
    }

    bool bNegativeNum = x < 0 ? true : false;
    if(bNegativeNum)
    {
        x *= -1;
    }

    int ret = 0;
    while(x > 0)
    {
        int temp = x % 10;
        x = x /10;
        if(((ret == maxIntValue / 10) && temp > maxIntValue % 10))
        {
            if(0 == x && bNegativeNum && (temp == (maxIntValue % 10 + 1)))
            {
                return minIntValue;
            }
            return 0;

        }
        if(ret > (maxIntValue / 10))
        {
           return 0;
        }
        ret  = ret * 10 + temp;
    }
    return bNegativeNum ? -1 * ret : ret;
}

int main()
{
    const int maxIntValue = pow(2, 31) - 1;
    const int minIntValue = -pow(2, 31);
    printf("max:%d, min:%d\n", maxIntValue, minIntValue);
    printf("%d\n", reverse(maxIntValue));
    printf("%d\n", reverse(123));
    printf("%d\n", reverse(-123));
    printf("%d\n", reverse(0));
    printf("%d\n", reverse(minIntValue));
    printf("%d\n", reverse(12334556));


    return 0;
}