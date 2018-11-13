// 055.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;




bool canJump(vector<int>& nums) {
	vector<bool> idxbool(nums.size(), false);
	idxbool[nums.size() - 1] = true;

	for (int i = nums.size() - 1; i >= 0; i--) {
		if (idxbool[i] == true)
			continue;
		for (int j = 0; j <= nums[i]; j++) {
			if (idxbool[i + j] == true) {
				idxbool[i] = true;
				break;
			}
		}
	}

	return idxbool[0];
}


int main()
{
	vector<int> v{ 2,3,1,1,4 };
	canJump(v);

}

