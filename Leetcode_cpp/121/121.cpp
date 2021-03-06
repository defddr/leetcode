// 121.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//记录历来最小值与今天的差价 得到最大差价

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int min = INT_MAX;
		int income = 0;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < min)
				min = prices[i];
			if (income < (prices[i] - min))
				income = prices[i] - min;
		}

		return income;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

