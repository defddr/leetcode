// 062.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
动态规划 转移方程  vv[i][j] = std::max(vv[i - 1][j] + vv[i][j - 1], vv[i][j]);
注意 只有1行或者1排的情况
*/

int uniquePaths(int m, int n) {
	if (m < 2 || n < 2)
		return 1;
	vector<vector<int>> vv(m + 1, vector<int>(n + 1, 0));
	vv[1][1] = 0; 
	vv[1][2] = 1; 
	vv[2][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			vv[i][j] = std::max(vv[i - 1][j] + vv[i][j - 1], vv[i][j]);
		}
	}

	return vv[m][n];
}

int main()
{
	uniquePaths(1,100);

}

