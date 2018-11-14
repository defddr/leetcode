// 009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/


bool CheckPalindrome(std::string s) {
	int begin = 0; int end = s.size()-1;

	while (end > begin) {
		if (s[begin] == s[end]) {
			begin++; end--;
		}
		else {
			return false;
		}
	}


	return true;
}

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	string s = to_string(x);
	return CheckPalindrome(s);
}




int main()
{
	isPalindrome(10);
    std::cout << "Hello World!\n"; 
}
