// 003LongestSubString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
使用map 记录字母出现字数 by def
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ret = 0;

		do {
			if (s.size() <= 1) {
				ret = s.size();
				break;
			}

			map<char, int> mapChars;
			for (int i = 0; i < s.size(); i++) {
				for (int j = i; j < s.size(); j++) {
					if (mapChars[s[j]] != 0) {
						break;
					}
					else {
						mapChars[s[j]]++;
					}
				}

				if (mapChars.size() > ret) {
					ret = mapChars.size();
				}
				mapChars.clear();
			}
		} while (false);
		std::cout << ret << "\n";
		return ret;

	}
};
int main()
{
    std::cout << "Hello World!\n"; 
}

