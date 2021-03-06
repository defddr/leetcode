// 046.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
[1,2,3]
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

//vector 转化 set 纯属 为了方便删除
vector<vector<int>> gvec_vec;

void permuteInner(vector<int>& vec,set<int> s) {
	if (s.empty()) {
		gvec_vec.push_back(vec);
		return;
	}

	set<int>::iterator it = s.begin();

	for (; it != s.end(); it++) {
		vec.push_back(*it);
		set<int >copys = s;
		copys.erase(*it);
		permuteInner(vec,copys);
		vec.pop_back();
	}

}

vector<vector<int>> permute(vector<int>& nums) {
	set<int> s(nums.begin(), nums.end());
	vector<int> vec;
	permuteInner(vec,s);

	return gvec_vec;
}



int main()
{
	vector<int> v{ 1,2,3 };
	permute(v);
    std::cout << "Hello World!\n"; 
}
