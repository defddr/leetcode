// 053.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//设置好初始值  遍历 比较  当前和要么是一路全加  要么就是当前数字自己  最后选出遍历中最大的current_sum
//动态规划   nums[i] = max(nums[i] + nums[i - 1], nums[i]);


int maxSubArray(vector<int>& nums) {
	if (nums.size() == 1)
		return nums[0];
	int res = INT_MIN; int current_sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		current_sum = std::max(nums[i] + current_sum, nums[i]);
		res = max(res, current_sum);
	}


	return res;
}


int main()
{
	vector<int> v{ -1,-2 };
	int i = maxSubArray(v);
}

