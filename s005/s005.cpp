//
// Created by skl on 2018/9/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ret;
        int max = 0;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i + 1; j < s.size(); j++)
            {

            }
        }
    }

    char* longestPalindrome2(char* s)
    {

    }
};

/*
 * 示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：
输入: "cbbd"
输出: "bb"
 */

int main()
{
    Solution s;

    char test[] = "testtest";
    string str;
    str.copy(test, 3);
    cout << str << endl;
    return 0;
}