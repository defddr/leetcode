// 026.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

int removeDuplicates(vector<int>& nums) {
	int idx = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == nums[i - 1]) {
			while (idx < nums.size()) {
				if (nums[idx] > nums[i])
					break;
				else
					idx++;
			}
			if (idx < nums.size())
				nums[i] = nums[idx];
			else
				return i;
		}
		if (nums[i] < nums[i - 1]) {
			int current_num = nums[idx];
			while (idx < nums.size()) {
				if (nums[idx] > current_num)
					break;
				else
					idx++;
			}
			if (idx < nums.size())
				nums[i] = nums[idx];
			else
				return i;
		}
	}

	return nums.size();
}
//[0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

int main()
{
	vector<int> v{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int i = removeDuplicates(v);
}

