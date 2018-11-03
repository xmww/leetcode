//
// Created by skl on 2018/9/16.
//

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
 */
//****************************** 超出时间限制 ****************************
bool isMatch(char* s, char* p)
{
    if(0 == strlen(s))
    {
        if(strlen(p) > 1 && p[1] == '*')
        {
            return isMatch(s, p + 2);
        }

        return 0 == strlen(p);
    }

    if(0 == strlen(p))
    {
        return false;
    }

    int ret = 0;

    if(strlen(p) > 1 && p[1] == '*')
    {
        if(s[0] == p[0] || p[0] == '.')
        {
            ret += (isMatch(s + 1, p) || isMatch(s + 1, p + 2));
        }
        if(!ret)
        {
            return isMatch(s, p + 2);
        }

    }else if(p[0] == '.' || p[0] == s[0])
    {
        return isMatch(s + 1, p + 1);
    }
    return ret;
}

bool isMatch2(char* s, char* p)
{
    if(0 == strlen(p))
    {
        return 0 == strlen(s);
    } else if(1 == strlen(p))
    {
        return strlen(s) == 1 ? (s[0] == p[0] || p[0] == '.') : false;
    } else
    {
        if(p[1] != '*')
        {
            return (strlen(s) > 0 && (s[0] == p[0] || p[0] == '.')) ? isMatch2(s + 1, p + 1) : false;
        }

        while(strlen(s) > 0 && ( s[0] == p[0] || p[0] == '.'))
        {
            if(isMatch2(s, p + 2))
            {
                return true;
            }
            s ++;
        }
        return isMatch2(s, p + 2);
    }
}


int main()
{
    printf("%d = 1\n", isMatch("bbbba", ".*a*a"));
    printf("%d = 1\n", isMatch("aa", "a*"));
    printf("%d = 0\n", isMatch("aa", "a"));
    printf("%d = 1\n", isMatch("aab", "c*a*b"));
    printf("%d = 1\n", isMatch("ab", ".*"));
    printf("%d = 0\n", isMatch("mississippi", "mis*is*p*."));
    printf("%d = 1\n", isMatch("", ""));
    printf("%d = 0\n", isMatch("", "mis*is*p*."));
    printf("%d = 0\n", isMatch("111", ""));
    printf("%d = 0\n", isMatch("ab", ".*c"));
    printf("%d = 1\n", isMatch("aaa", "ab*a*c*a"));
    printf("%d = 1\n", isMatch("a", "ab*"));

    printf("****************\n");
    printf("%d = 1\n", isMatch2("bbbba", ".*a*a"));
    printf("%d = 1\n", isMatch2("aa", "a*"));
    printf("%d = 0\n", isMatch2("aa", "a"));
    printf("%d = 1\n", isMatch2("aab", "c*a*b"));
    printf("%d = 1\n", isMatch2("ab", ".*"));
    printf("%d = 0\n", isMatch2("mississippi", "mis*is*p*."));
    printf("%d = 1\n", isMatch2("", ""));
    printf("%d = 0\n", isMatch2("", "mis*is*p*."));
    printf("%d = 0\n", isMatch2("111", ""));
    printf("%d = 0\n", isMatch2("ab", ".*c"));
    printf("%d = 1\n", isMatch2("aaa", "ab*a*c*a"));
    printf("%d = 1\n", isMatch2("a", "ab*"));
    return 0;
}