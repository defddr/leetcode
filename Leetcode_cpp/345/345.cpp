// 345.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

bool isVowels(char c) {
	string  Vowels = "aeiouAEIOU";
	for (int i = 0; i < Vowels.size(); ++i) {
		if (c == Vowels[i]) return true;
	}
	return false;
}


string reverseVowels(string s) {
	int i = 0; int j = s.size() - 1;
	while (i < j) {
		if (!isVowels(s[i])) i++;
		if (!isVowels(s[j])) j--;
		if (isVowels(s[i]) && isVowels(s[j])) {
			std::swap(s[i], s[j]);
			++i, --j;
		}
	}
	return s;
}

int main()
{
	reverseVowels("de");
    std::cout << "Hello World!\n"; 
}


