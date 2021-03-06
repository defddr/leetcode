// 198.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//maxv[i] 就是第i个位置最大的收益   maxv[i] = std::max((maxv[i - 2] + nums[i]), maxv[i - 1]);

int rob(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return nums[0];
	}

	vector<int> maxv(n, 0);
	maxv[0] = nums[0];
	maxv[1] = std::max(nums[0], nums[1]);
	if (n == 2)
		return maxv[1];
	for (int i = 2; i < nums.size(); i++) {
		maxv[i] = std::max((maxv[i - 2] + nums[i]), maxv[i - 1]);
	}

	return maxv[nums.size() - 1];
}

int main()
{
	//vector<int> v{ 2,1,1,2 };
	vector<int> v{ 1,2,3,1 };
 	int i = rob(v);

    std::cout << "Hello World!\n"; 
}

