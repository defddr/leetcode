// 079.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

bool Search(vector<vector<char>>& board, vector<vector<bool>>& traveled_record, const string& word, int idx, int x, int y) {
	if (idx == word.size())
		return true;
	if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
		return false;
	bool res = false;
	if (board[x][y] == word[idx] && traveled_record[x][y] == false) {
		traveled_record[x][y] = true;
		res = Search(board, traveled_record, word, idx+1, x + 1, y) || Search(board, traveled_record, word, idx+1, x - 1, y) ||
			Search(board, traveled_record, word, idx+1, x, y + 1) || Search(board, traveled_record, word, idx+1, x, y - 1);
		traveled_record[x][y] = false;

		if (res == true)
			return res;
	}

	return false;
}


bool exist(vector<vector<char>>& board, string word) {
	int m = board.size(); int n = board[0].size();
	vector<vector<bool>> traveled_record(m, vector<bool>(n, false));

	bool res = false;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int idx = 0;
			res = Search(board , traveled_record, word,idx,i,j);
			if (true == res)
				return res;
		}
	}

	return false;
}


/*
[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
"ABCCED"
*/

int main()
{
	vector<vector<char>> board;
	vector<char> v1{ 'A', 'B', 'C', 'E' };
	board.push_back(v1);

	vector<char> v2{ 'S', 'F', 'C', 'S' };
	board.push_back(v2);

	vector<char> v3{ 'A', 'D', 'E', 'E' };
	board.push_back(v3);


	string s = "ABCCED";

    std::cout << exist(board,s) << std::endl;
}

