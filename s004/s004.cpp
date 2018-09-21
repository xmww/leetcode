//
// Created by skl on 2018/9/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
        {
           for(int j = i + 1; j < nums.size(); j++)
           {
               if((nums[i] + nums[j]) == target)
               {

                   ret.push_back(i);
                   ret.push_back(j);
                   return ret;
               }
           }
        }
        return ret;
    }

    vector<int> twoSum2(vector<int>& nums, int target)
    {
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                bool success = [](int a, int b, int target) { return (( a + b ) == target) ? true : false; }(nums[i], nums[j], target);
                if(success)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main()
{
    //2, 7, 11, 15
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    auto ret = s.twoSum2(nums, 9);
    for(auto it = ret.begin(); it !=  ret.end(); it ++)
    {
        cout << *it << endl;
    }

    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(4);
    auto ret2 = s.twoSum2(nums2, 6);
    for(auto it = ret2.begin(); it !=  ret2.end(); it ++)
    {
        cout << *it << endl;
    }
    return 0;
}