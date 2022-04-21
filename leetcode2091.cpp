// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <tgmath.h>
int minimumDeletions(int* nums, int numsSize){
    int max = INT_MIN;
    int maxIndex = 0;
    int min = INT_MAX;
    int minIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
            maxIndex = i;
        }
        if (nums[i] < min) {
            min = nums[i];
            minIndex = i;
        }
    }
    int left;
    int right;
    if (maxIndex > minIndex) {
        left = minIndex;
        right = maxIndex;
    } else {
        left = maxIndex;
        right = minIndex;
    }
    int firstStep = right + 1;
    int secondStep = numsSize - left;
    int thirdStep = (left + 1) + (numsSize - right);
    min = fmin(firstStep, secondStep);
    min = fmin(min, thirdStep);
    return min;
}



int main(int argc, char* argv[])
{
	int a[]={-1,-53,93,-42,37,94,97,82,46,42,-99,56,-76,-66,-67,-13,10,66,85,-28};
	int b = sizeof(a)/sizeof(int);
	printf("%d\n",b);
	printf("%d",minimumDeletions(a,b));
}
