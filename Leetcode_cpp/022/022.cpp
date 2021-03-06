// 022.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/*
	"((()))",
	"(()())",
	"(())()",
	"()(())",
	"()()()"
*/

// 仅有两种情况的分叉 直接递归中分叉 不用 for循环

vector<string> g_str;

void generateParenthesisInner(int left, int right,string str,int n) {
	if (str.size() == n * 2) {
		g_str.push_back(str);
		return;
	}

	if (left < n) {
		string copystr = str; int copyleft = left; int copyright = right;
		copystr += "(";
		copyleft++;
		generateParenthesisInner(copyleft, copyright, copystr, n);
	}

	if (left > right && right < n) {
		str += ")";
		right++;;
		generateParenthesisInner(left, right, str, n);
	}

}

vector<string> generateParenthesis(int n) {
	string str;
	generateParenthesisInner(0,0,str,n);

	return g_str;
}




int main()
{
	generateParenthesis(3);
    std::cout << "Hello World!\n"; 
}

