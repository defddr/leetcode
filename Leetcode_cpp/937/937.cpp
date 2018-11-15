// 937.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*
你有一个日志数组 logs。每条日志都是以空格分隔的字串。

对于每条日志，其第一个字为字母数字标识符。然后，要么：

标识符后面的每个字将仅由小写字母组成，或；
标识符后面的每个字将仅由数字组成。
我们将这两种日志分别称为字母日志和数字日志。保证每个日志在其标识符后面至少有一个字。

将日志重新排序，使得所有字母日志都排在数字日志之前。字母日志按字母顺序排序，忽略标识符，标识符仅用于表示关系。数字日志应该按原来的顺序排列。

返回日志的最终顺序。
*/


bool Greater(const string &a, const string &b)
{
	size_t posa = a.find(" ");
	size_t posb = b.find(" ");

	return a.substr(posa + 1) < b.substr(posb + 1);
}


class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> str;
		vector<string> num;
		for (auto& e : logs) {
			size_t pos = e.find(" ");
			if (isdigit(e[pos + 1])) {
				num.push_back(e);
			}
			else {
				str.push_back(e);
			}
		}
		std::sort(str.begin(), str.end(), Greater);
		logs.clear();
		for (auto& e : str) {
			logs.push_back(e);
		}

		for (auto& e : num) {
			logs.push_back(e);
		}

		return logs;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

