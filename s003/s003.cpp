//
// Created by skl on 2018/9/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if(0 == s.size()) return 0;
        int maxLen = 1;
        for(int i = 0; i < s.size(); i++)
        {
            bool checkRepeat[256] = {false};
            for(int j = i; j < s.size(); j++)
            {
                if(checkRepeat[s[j]] == true)
                {
                    if((j - i) > maxLen)
                    {
                        maxLen = j - i;
                    }
                    break;
                }
                if(j == (s.size() - 1))
                {
                    if((j - i + 1) > maxLen)
                    {
                        maxLen = j - i + 1;
                    }
                    break;
                }
                checkRepeat[s[j]] = true;
            }

        }
        return maxLen;
    }

     int lengthOfLongestSubstring2(string s)
    {
        if(0 == s.size()) return 0;
        int maxLen = 1;
        int pos[256] = {0}, left = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(pos[s[i]] != 0)
            {
                left = i + 1;
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("") << endl;
    cout << s.lengthOfLongestSubstring(" ") << endl;
    cout << s.lengthOfLongestSubstring("av") << endl;
    return 0;
}