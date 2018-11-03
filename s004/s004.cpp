//
// Created by skl on 2018/9/16.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
    {
        printf("1:%d, 2:%d\n", nums1Size, nums2Size);
        if(0 == nums1Size)
        {
            if(nums2Size % 2)
            {
                return nums2[nums2Size / 2];
            }else
            {
                return (nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2.0;
            }
        }
        if(0 == nums2Size)
        {
            if(nums1Size % 2)
            {
                return nums1[nums1Size / 2];
            }else
            {
                return (nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) / 2.0;
            }
        }
        if(1 == nums1Size && 1 == nums2Size)
        {
            return (nums1[0] + nums2[0]) / 2.0;
        }


        if(nums1[0] < nums2[0])
        {
            nums1 ++;
            nums1Size --;
        }else
        {
            nums2 ++;
            nums2Size --;
        }

        if(nums1[nums1Size - 1] < nums2[nums2Size - 1])
        {
            nums2Size --;
        }else
        {
            nums1Size --;
        }

        return findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    }

    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
    {
        auto getMedian = [](vector<int>& num)
        {
            if(1 == num.size())
            {
                return num[0] * 1.0;
            }
            if(num.size() % 2)
            {
                return num[num.size() / 2] * 1.0;
            }
            return (num[num.size() / 2] + num[num.size() / 2 - 1]) / 2.0;
        };

        if(0 == nums1.size())
        {
            return getMedian(nums2);
        }
        if(0 == nums2.size())
        {
            return getMedian(nums1);
        }

        if(1 == nums1.size() && 1 == nums2.size())
        {
            return (*(nums1.begin()) + *(nums2.begin())) / 2.0;
        }

        if(*(nums1.begin()) < *(nums2.begin()))
        {
            nums1.erase(nums1.begin());
        }else
        {
            nums2.erase(nums2.begin());
        }

        if(*(nums1.end() - 1) < *(nums2.end() - 1))
        {
            nums2.pop_back();
        }
        else
        {
            nums1.pop_back();
        }
        return findMedianSortedArrays2(nums1, nums2);

    }
};

/*
 * nums1 = [1, 2]
   nums2 = [3, 4]
 */

int main()
{
    Solution s;
    {

        int nums1[] = {1, 2};
        int nums2[] = {3, 4};
        vector<int> num11{1, 2};
        vector<int> num22{3, 4};
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 2, nums2, 2));
        printf("ret2:%f\n", s.findMedianSortedArrays2(num11, num22));
    }

    {
        int nums1[] = {1};
        int nums2[] = {3, 4};

        vector<int> num11{1};
        vector<int> num22{3, 4};

        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 1, nums2, 2));
        printf("ret2:%f\n", s.findMedianSortedArrays2(num11, num22));

    }

    {
        int nums1[] = {1};
        int nums2[] = {3};

        vector<int> num11{1};
        vector<int> num22{3};
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 1, nums2, 1));
        printf("ret2:%f\n", s.findMedianSortedArrays2(num11, num22));

    }

    {
        int nums1[] = {1, 2, 3};
        int nums2[] = {4};

        vector<int> num11{1, 2, 3};
        vector<int> num22{4};
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 3, nums2, 1));
        printf("ret2:%f\n", s.findMedianSortedArrays2(num11, num22));

    }

    {
        int nums1[] = {1, 3};
        int nums2[] = {2};

        vector<int> num11{1, 3};
        vector<int> num22{2};
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 1, nums2, 2));
        printf("ret2:%f\n", s.findMedianSortedArrays2(num11, num22));

    }

    {

        int nums1[] = {};
        int nums2[] = {1, 2, 3, 4, 5};

        vector<int> num11{};
        vector<int> num22{1, 2, 3, 4, 5};
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 0, nums2, 5));
        printf("ret2:%f\n", s.findMedianSortedArrays2(num11, num22));
    }

    vector<int> test{1, 2, 3, 4};
    test.erase(test.begin());
    test.pop_back();
    printf("test:%d\n", *test.begin());
    return 0;
}