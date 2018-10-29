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
        if(0 == nums1Size)
        {
            if(nums2Size % 2)
            {
                return nums2[nums2Size / 2];
            }else
            {
                return (nums2[nums2Size / 2] + nums2[nums2Size / 2 + 1]) / 2;
            }
        }
        if(0 == nums2Size)
        {
            if(nums1Size % 2)
            {
                return nums1[nums1Size / 2];
            }else
            {
                return (nums1[nums1Size / 2] + nums1[nums1Size / 2 + 1]) / 2;
            }
        }
        if(1 == nums1Size && 1 == nums2Size)
        {

        }


        if(nums1[0] < nums2[1])
        {

        }else
        {

        }

        if(nums1[nums1Size - 1] < nums2[nums2Size - 1])
        {

        }else
        {

        }
    }
};

/*
 * nums1 = [1, 2]
   nums2 = [3, 4]
 */

int main()
{
    return 0;
}