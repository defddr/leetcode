// 107.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


// DeleteMe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


multimap<int, TreeNode*> mm;
vector<vector<int>> vv;
int maxlevel = 0;

void levelOrderBottomInner(TreeNode* root, int level) {
	if (NULL == root)
		return;
	if (level > maxlevel)
		maxlevel = level;
	mm.insert(std::pair<int, TreeNode*>(level, root));
	levelOrderBottomInner(root->right, level + 1);
	levelOrderBottomInner(root->left, level + 1);

}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	if (root == NULL)
		return vector<vector<int>>();
	levelOrderBottomInner(root, 0);

	int count = 0;
	int i = maxlevel;
	while (i >= 0) {
		std::pair <std::multimap<int, TreeNode*>::iterator, std::multimap<int, TreeNode*>::iterator> ret;
		ret = mm.equal_range(i);
		vector<int> v;
		for (std::multimap<int, TreeNode*>::iterator it = ret.first; it != ret.second; ++it) {
			count++;
			v.push_back(it->second->val);
		}
		std::reverse(v.begin(), v.end());
		vv.push_back(v);
		if (count == mm.size())
			break;
		i--;
	}

	return vv;
}


int main()
{
	TreeNode a(1);
	levelOrderBottom(&a);
}

