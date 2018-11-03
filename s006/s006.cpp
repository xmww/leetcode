//
// Created by skl on 2018/9/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
};

/*
示例 1:

输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"
示例 2:

输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:

P     I    N
A   L S  I G
Y A   H R
P     I
 */

char* convert(char* s, int numRows)
{

    if(1 == numRows)
    {
        return s;
    }

    int len = strlen(s);
    char **zStr = NULL;
    zStr = (char**)malloc(sizeof(char*) * numRows);
    for(int i = 0; i < numRows; i ++)
    {
        zStr[i] = (char*)malloc(sizeof(char) * len);
        memset(zStr[i], 0, len);
    }

    int m = 0, n = 0;
    bool bDown =  true;
    bool bVertical = true;
    for(int i = 0; i < len; i++)
    {
        zStr[m][n] = s[i];
        if(bDown)
        {
            if(m == (numRows - 1))
            {
                m --;
                bDown = false;
                bVertical = false;
            }else
            {
                m ++;
            }
        }else
        {
            if(0 == m)
            {
               m ++;
               bDown = true;
               bVertical = true;
            } else
            {
                m --;
            }
        }

        if(bVertical)
        {

        }
        else
        {
            n ++;
        }
    }

    char * ret = (char*)malloc(len + 1);
    int index = 0;
    for(int i = 0; i < numRows; i ++)
    {
        for(int j = 0; j < len; j++)
        {
            //printf("%c", zStr[i][j]);
            if(zStr[i][j] != 0)
            {
                ret[index++] = zStr[i][j];
            }
        }
        //printf("\n");
    }

    for(int i = 0; i < numRows; i ++)
    {
        free(zStr[i]);
    }
    free(zStr);

    ret[len] = '\0';
    return ret;
}

int main()
{
    Solution s;

    char* test = "PAYPALISHIRING";
    char* ret = convert(test, 3);
    if(0 == strcmp(ret, "PAHNAPLSIIGYIR"))
    {
        printf("good\n");
    } else
    {
        printf("error, %s\n", ret);
    }


    char* ret2 = convert(test, 4);
    if(0 == strcmp(ret2, "PINALSIGYAHRPI"))
    {
        printf("good\n");
    } else
    {
        printf("error, %s\n", ret);
    }


    char* ret3 = convert("ab", 1);
    if(0 == strcmp(ret3, "ab"))
    {
        printf("good\n");
    } else
    {
        printf("error, %s\n", ret);
    }
    return 0;
}