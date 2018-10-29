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
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 2, nums2, 2));
    }

    {
        int nums1[] = {1};
        int nums2[] = {3, 4};
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 1, nums2, 2));
    }

    {
        int nums1[] = {1};
        int nums2[] = {3};
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 1, nums2, 1));
    }

    {
        int nums1[] = {1, 2, 3};
        int nums2[] = {4};
        printf("ret:%f\n", s.findMedianSortedArrays(nums1, 3, nums2, 1));
    }
    return 0;
}