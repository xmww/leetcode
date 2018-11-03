//
// Created by skl on 2018/9/16.
//

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 */

char *intToRoman(int num)
{
    char* ret = (char *) malloc(64);
    int index = 0;
    if (num >= 3000)
    {
        ret[index++] = 'M';
        ret[index++] = 'M';
        ret[index++] = 'M';
        num = num % 3000;
    } else if (num >= 2000)
    {
        ret[index++] = 'M';
        ret[index++] = 'M';
        num = num % 2000;
    } else if (num >= 1000)
    {
        ret[index++] = 'M';
        num = num % 1000;
    }

    if (num >= 900)
    {
        ret[index++] = 'C';
        ret[index++] = 'M';
        num -= 900;
    } else if (num >= 500)
    {
        if (num >= 800)
        {
            ret[index++] = 'D';
            ret[index++] = 'C';
            ret[index++] = 'C';
            ret[index++] = 'C';
            num -= 800;
        } else if (num >= 700)
        {
            ret[index++] = 'D';
            ret[index++] = 'C';
            ret[index++] = 'C';
            num -= 700;
        } else if (num >= 600)
        {
            ret[index++] = 'D';
            ret[index++] = 'C';
            num -= 600;
        } else
        {
            ret[index++] = 'D';
            num -= 500;
        }
    } else if (num >= 400)
    {
        ret[index++] = 'C';
        ret[index++] = 'D';
        num -= 400;
    } else if (num >= 100)
    {
        if (num >= 300)
        {
            ret[index++] = 'C';
            ret[index++] = 'C';
            ret[index++] = 'C';
            num -= 300;
        } else if (num >= 200)
        {
            ret[index++] = 'C';
            ret[index++] = 'C';
            num -= 200;
        } else
        {
            ret[index++] = 'C';
            num -= 100;
        }
    }

    if (num >= 90)
    {
        ret[index++] = 'X';
        ret[index++] = 'C';
        num -= 90;
    } else if (num >= 50)
    {
        ret[index++] = 'L';
        if (num >= 80)
        {
            ret[index++] = 'X';
            ret[index++] = 'X';
            ret[index++] = 'X';
            num -= 80;
        } else if (num >= 70)
        {
            ret[index++] = 'X';
            ret[index++] = 'X';
            num -= 70;
        } else if (num >= 60)
        {
            ret[index++] = 'X';
            num -= 60;
        } else
        {
            num -= 50;
        }
    } else if (num >= 40)
    {
        ret[index++] = 'X';
        ret[index++] = 'L';
        num -= 40;
    } else if (num >= 10)
    {
        if (num >= 30)
        {
            ret[index++] = 'X';
            ret[index++] = 'X';
            ret[index++] = 'X';

            num -= 30;
        } else if (num >= 20)
        {
            ret[index++] = 'X';
            ret[index++] = 'X';
            num -= 20;
        } else
        {
            ret[index++] = 'X';
            num -= 10;
        }
    }

    if (num >= 9)
    {
        ret[index++] = 'I';
        ret[index++] = 'X';
    } else if (num >= 5)
    {
        if (num == 8)
        {
            ret[index++] = 'V';
            ret[index++] = 'I';
            ret[index++] = 'I';
            ret[index++] = 'I';
        } else if (num == 7)
        {
            ret[index++] = 'V';
            ret[index++] = 'I';
            ret[index++] = 'I';
        } else if (num == 6)
        {
            ret[index++] = 'V';
            ret[index++] = 'I';
        } else
        {
            ret[index++] = 'V';
        }
    } else if (num >= 4)
    {
        ret[index++] = 'I';
        ret[index++] = 'V';
    } else
    {
        if(num == 3)
        {
            ret[index++] = 'I';
            ret[index++] = 'I';
            ret[index++] = 'I';

        }else if(num == 2)
        {
            ret[index++] = 'I';
            ret[index++] = 'I';

        }else if(num == 1)
        {
            ret[index++] = 'I';
        }

    }
    ret[index] = '\0';
    return ret;
}

int main()
{
    printf("3 :III  , %s\n", intToRoman(3));
    printf("4 :IV,    %s\n", intToRoman(4));
    printf("9 :IX  ,  %s\n", intToRoman(9));
    printf("58 : LVIII , %s\n", intToRoman(58));
    printf("1994 : MCMXCIV  , %s\n", intToRoman(1994));
    printf("40 : XL  , %s\n", intToRoman(40));
    printf("100 : C  , %s\n", intToRoman(100));
    printf("1000 : M  , %s\n", intToRoman(1000));

    return 0;
}

