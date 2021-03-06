// 004MedianOfTwoSortedArrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums3(nums1);
		for (int i = 0; i < nums2.size(); i++) {
			nums3.push_back(nums2[i]);
		}
		std::sort(nums3.begin(), nums3.end());
		int n = nums3.size();
		if (n % 2 == 0) {
			float f = nums3[n / 2];
			f += nums3[(n / 2) - 1];
			f = f/ 2;
			return f;
		}
		else {
			return nums3[n / 2];
		}
	}
};

int main()
{
	Solution s;
	vector<int> v1{ 1, 2 };
	vector<int> v2{ 3, 4 };
	double f = s.findMedianSortedArrays(v1, v2);
}

