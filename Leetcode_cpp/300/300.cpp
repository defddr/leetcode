// 300.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
*/

int lengthOfLIS(vector<int>& nums) {
	if (nums.empty())
		return 0;
	if (nums.size() == 1)
		return 1;
	vector<int> increasing_len(nums.size(), 1);
	int max = 0;
	for (int i = 1; i < nums.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (nums[i] > nums[j]) {
				increasing_len[i] = std::max(increasing_len[j] + 1, increasing_len[i]);
			}
			if (increasing_len[i] > max)
				max = increasing_len[i];
		}
	}

	return max;
}

int main()
{
    std::cout << "Hello World!\n"; 
}

