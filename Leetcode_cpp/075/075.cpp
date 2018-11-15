// 075.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
	int front = 0; int back = nums.size() - 1;
	while (front < back) {
		if( nums[front] == 0)
			front++;
		if( nums[back] != 0)
			back--;
		if (nums[front] != 0 && nums[back] == 0 && front < back ) {
			std::swap(nums[front], nums[back]);
			front++;
			back--;
		}
	}


	back = nums.size() - 1;
	while (front < back) {
		if (nums[front] <= 1)
			front++;
		if (nums[back] != 1)
			back--;
		if (nums[front] != 1 && nums[back] == 1 && front < back) {
			std::swap(nums[front], nums[back]);
			front++;
			back--;
		}
	}

	return;
}


int main()
{
	//vector<int> v{ 2,2 };
	vector<int> v{ 1,2};
	sortColors(v);
}

