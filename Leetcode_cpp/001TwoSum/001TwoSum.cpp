// 001TwoSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
// Leetcode_cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static const auto io_speed_up = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

/*
方法二：两遍哈希表
为了对运行时间复杂度进行优化，我们需要一种更有效的方法来检查数组中是否存在目标元素。
如果存在，我们需要找出它的索引。保持数组中的每个元素与其索引相互对应的最好方法是什么？哈希表。

通过以空间换取速度的方式，我们可以将查找时间从 O(n)O(n) 降低到 O(1)O(1)。
哈希表正是为此目的而构建的，它支持以 近似 恒定的时间进行快速查找。
我用“近似”来描述，是因为一旦出现冲突，查找用时可能会退化到 O(n)O(n)。
但只要你仔细地挑选哈希函数，在哈希表中进行查找的用时应当被摊销为 O(1)O(1)。
一个简单的实现使用了两次迭代。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。
然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]target−nums[i]）是否存在于表中。
注意，该目标元素不能是 nums[i]nums[i] 本身！
*/


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++) {
			int n = target - nums[i];
			if (m.find(n) != m.end()) {
				if (i != m[n])
					return vector<int>{i, m[n]};
			}
		}
		return vector<int>();
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
