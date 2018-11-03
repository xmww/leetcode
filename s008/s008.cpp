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

输入: "42"
输出: 42
示例 2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
示例 3:

输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
示例 4:

输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
示例 5:

输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−2^31) 。
 */

int myAtoi(char *str)
{
    const int maxIntValue = pow(2, 31) - 1;
    const int minIntValue = -1 * pow(2, 31);
    int ret = 0;
    bool bNegativeNum = false;
    bool bStart = false;
    for (int i = 0; i < strlen(str); i++)
    {

        if (((str[i] >= '0') && (str[i] <= '9')) || (str[i] == '-') || (str[i] == '+'))
        {

            if ((str[i] == '-') || str[i] == '+')
            {
                if (!bStart)
                {
                    bNegativeNum = (str[i] == '-') ? true : false;
                    bStart = true;
                    continue;
                } else
                {
                    return bNegativeNum ? -1 * ret : ret;
                }
            }

            int temp = str[i] - '0';
            if (ret == maxIntValue / 10 && temp >= (maxIntValue % 10))
            {
                if(bNegativeNum && temp == (maxIntValue % 10))
                {

                }else
                {
                    return bNegativeNum ? minIntValue : maxIntValue;
                }
            }

            if((ret > maxIntValue / 10))
            {
                return bNegativeNum ? minIntValue : maxIntValue;
            }

            ret = ret * 10 + temp;
            bStart = true;
        } else
        {
            if (!bStart)
            {
                if (str[i] != ' ')
                {
                    return 0;
                }
            } else
            {
                return bNegativeNum ? -1 * ret : ret;
            }
        }


    }
    return bNegativeNum ? -1 * ret : ret;
}


int main()
{
    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("   -42"));
    printf("%d\n", myAtoi("4193 with words"));
    printf("%d\n", myAtoi("-91283472332"));
    printf("%d\n", myAtoi("    91283472332"));
    printf("%d\n", myAtoi("words and 987"));
    printf("%d\n", myAtoi("0"));
    printf("%d\n", myAtoi("2147483648"));
    printf("%d\n", myAtoi("-2147483649"));
    printf("%d\n", myAtoi("-2147483647"));

    printf("%d\n", myAtoi("-1"));

    return 0;
}