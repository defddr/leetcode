

// 312.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。每当你戳破一个气球 i 时，
你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 
这里的 left 和 right 代表和 i 相邻的两个气球的序号。
注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。
说明:
你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
示例:
输入: [3,1,5,8]
输出: 167
解释: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
	 coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
// Non-recursion

int maxCoins(vector<int>& nums) {
	int n = nums.size();
	nums.insert(nums.begin(), 1);
	nums.push_back(1);
	vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
	for (int len = 1; len <= n; ++len) {
		for (int left = 1; left <= n - len + 1; ++left) {
			int right = left + len - 1;
			for (int k = left; k <= right; ++k) {
				dp[left][right] = std::max(dp[left][right], nums[left - 1] * nums[k] * nums[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
			}
		}
	}
	return dp[1][n];
}
	


int main()
{
	vector<int> v{3,1,5,8};
	std::cout << maxCoins(v) << std::endl;
    std::cout << "Hello World!\n"; 
}
