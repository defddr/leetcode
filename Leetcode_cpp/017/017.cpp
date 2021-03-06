// 017.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例 :
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

可以任意选择答案输出的顺序。
*/

//本体函数输入起始值 后面进行递归回溯 退出条件是 拼接的字符串长度等于 digit字符串的长度

std::map<char, string> g_digit_map{
	{'2',"abc"},
	{'3',"def"},
	{'4',"ghi"},
	{'5',"jkl"},
	{'6',"mno"},
	{'7',"pqrs"},
	{'8',"tuv"},
	{'9',"wxyz"}
};

vector<string> result_vec;

void letterCombinationsInner(const string& digits ,int i,string& str) {
	if (str.size() == digits.size()) {
		result_vec.push_back(str);
		return;
	}
	string select = g_digit_map[digits[i]];
	for (int j = 0; j < select.size(); j++) {
		str += select[j];
		letterCombinationsInner(digits,i+1, str);
		str.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	if (digits.empty())
		return result_vec;
	string str;
	letterCombinationsInner(digits, 0, str);

	return result_vec;
}



int main()
{
	letterCombinations("23");
    std::cout << "Hello World!\n"; 
}

