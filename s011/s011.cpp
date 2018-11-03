//
// Created by skl on 2018/9/16.
//

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;


//示例:
//
//输入: [1,8,6,2,5,4,8,3,7]
//输出: 49


int maxArea(int* height, int heightSize)
{
    int max = 0;
    for(int i = 0; i < heightSize; i ++)
    {
        for(int j = i + 1; j < heightSize; j ++)
        {
            int w = height[i] > height[j] ? height[j] : height[i];
            int cur = (j - i) * w;
            max = max < cur ? cur : max;
        }
    }
    return max;
}


int maxArea2(int* height, int heightSize)
{
    int max = 0;
    int start = 0, end = heightSize - 1;
    while(start != end)
    {
        int w = height[start] > height[end] ? height[end] : height[start];
        int cur = (end - start) * w;
        max = max > cur ? max : cur;

        if(height[start] > height[end])
        {
            end --;
        }
        else
        {
            start ++;
        }
    }
    return max;

}

int main()
{
    int h[] = {1,8,6,2,5,4,8,3,7};
    printf("max:%d = 49\n", maxArea2(h, 9));
    return 0;
}