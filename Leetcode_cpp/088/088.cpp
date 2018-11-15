// 088.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;



void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = nums1.size() - 1;
	while (m > 0 && n > 0) {
		if (nums1[m - 1] >= nums2[n - 1]) {
			nums1[i] = nums1[m - 1];
			i--; m--;
		}
		else {
			nums1[i] = nums2[n - 1];
			i--; n--;
		}
	}

	if ( 0 == m ) {
		while (n >= 0) {
			nums1[i] = nums2[n - 1];
			i--; n--;
		}
	}

}

int main()
{
	vector<int> v1{ 1,2,3,0,0,0 };
	vector<int> v2{ 3,5,6 };
	merge(v1,3,v2,3);
}

