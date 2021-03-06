// 070ClimbingStairs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//中规中矩的做法 状态转移分析 使用vector记忆之前的结果  速度较慢 可优化


class Solution {
public:
	int climbStairs(int n) {
		vector<int> v(n + 1, 0);
		v[1] = 1;
		v[2] = v[1] + 1;
		if (n < 3)
			return v[n];
		for (int i = 3; i <= n; i++) {
			v[i] = v[i - 1] + v[i - 2];
		}

		return v[n];
	}
};


class Solution1 {
public:
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		int *arr = new int[n + 1];
		arr[1] = 1; arr[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[n];
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
