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
事实证明，我们可以一次完成。在进行迭代并将元素插入到表中的同时，
我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。
如果它存在，那我们已经找到了对应解，并立即将其返回。
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> record;
		for (int i = 0; i < nums.size(); i++) {
			int com = target - nums[i];
			if (record.find(com) != record.end()) {
				int res[2] = { i,record[com] };
				return vector<int>(res, res + 2);
			}
			record[nums[i]] = i;
		}
		return vector<int>();
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
