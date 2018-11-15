// 125.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
*/

bool isPalindrome(string s) {
	for (auto& e : s) {
		if (isalpha(e)) {
			e = tolower(e);
		}
	}

	int i = 0; int j = s.size() - 1;

	while (i < j) {
		while (i < s.size() && !isalpha(s[i]) && !isdigit(s[i]))
			i++;

		while (j >= 0 && !isalpha(s[j]) && !isdigit(s[j]))
			j--;

		if (i < j) {
			if (s[i] != s[j])
				return false;
			i++; j--;
		}
		if (i >= j)
			return true;
	}


	return true;
}

int main()
{
    std::cout << "Hello World!\n"; 
}

