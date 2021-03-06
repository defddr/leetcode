// 078.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
[1,2,3]
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

//递归遍历  注意的是 需要添加的数要大于 已经选择的数组中的最后一位 可以避免同样的数字选择以不同的组合多次出现
vector<vector<int>> g_vec_vec;

void subsetsInner(vector<int>& v, set<int>& s ) {
	if (s.empty()) {
		return;
	}

	set<int>::iterator it = s.begin();

	for (; it != s.end(); it++) {
		if( (v.size() >0 && (*it)>v.back()) || v.empty() )
		{
			v.push_back(*it);
			set<int> copyset = s;
			copyset.erase(*it);
			g_vec_vec.push_back(v);
			subsetsInner(v, copyset);
			v.pop_back();
		}
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	set<int> s(nums.begin(), nums.end());

	vector<int> v;
	subsetsInner(v,s);
	g_vec_vec.push_back(vector<int>());
	return g_vec_vec;
}


int main()
{
	vector<int> v{ 1,2,3 };
	subsets(v);
}

