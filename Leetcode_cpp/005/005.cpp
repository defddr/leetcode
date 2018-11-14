// 005.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/

//dp[j][i] = 1;  if (i-j > 2 && s[j] == s[i]  && dp[j+1][i-1] == 1) 
//dp[i][i+1] =1 if(s[i]==s[i+1])
//由于dp的依赖关系 循环必须 	for (int i = 0; i < s.size(); i++) for (int j = 0; j < i; j++) dp[j][i]

string longestPalindrome(string s) {
	if (s.size() < 2)
		return s;
	int left = 0; int right = 0;
	vector<vector<int>> dp(s.size()+1, vector<int>(s.size() + 1, 0));

	for (int i = 0; i < s.size(); i++) {
		dp[i][i] = 1;
		for (int j = 0; j < i; j++) {
			if (i-j == 1 && s[i] == s[j]) {
				dp[j][i] = 1;
			}

			if (i-j > 1 && s[j] == s[i]  && dp[j+1][i-1] == 1) {
				dp[j][i] = 1;
			}
			
			if (i - j > right - left && 1 == dp[j][i]) {
				left = j; right = i;
			}
		}
	}

	return s.substr(left, right - left + 1);
}


int main()
{
	std::cout <<  longestPalindrome("babad");
}

