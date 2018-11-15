// 590.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;
	Node() {}
	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


vector<int> g_v;
void preorderInner(Node* root) {
	if (NULL == root)
		return;
	for (const auto& e : root->children) {
		preorderInner(e);
	}
	g_v.push_back(root->val);
}


vector<int> postorder(Node* root) {
	preorderInner(root);
	return g_v;
}


int main()
{
    std::cout << "Hello World!\n"; 
}

