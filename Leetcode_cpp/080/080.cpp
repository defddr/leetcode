// 080.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。
说明:

为什么返回数值是整数，但输出的答案是数组呢?
*/


int removeDuplicates(vector<int>& nums) {
	if (nums.size() < 2)
		return nums.size();
	const int compare_limit = 2;
	int comp_count = 0;
	int comp_num = nums[0];
	int idx = 0;
	for (int i = 0; i < nums.size(); i++) {
	
	}



	return ;

}


//[1,1,1,2,2,3]


int main()
{
	vector<int> v{ 0,0,1,1,1,1,2,3,3 };
	int i = removeDuplicates(v);
}

