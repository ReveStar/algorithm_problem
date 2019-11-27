// uva122.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char s[300];
struct Node {
	int v, cnt;
	Node* Left, * Right;
	Node():v(0),cnt(0),Left(nullptr),Right(nullptr){}
};
Node* root;
Node* newnode() {
	return new Node();

}
bool failed = false;
void addnode(int v, char* s) {
	int n = strlen(s);
	Node* u = root;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			if (u->Left == NULL)u->Left = newnode();
			u = u->Left;
		}
		else if (s[i] == 'R') {
			if (u->Right == NULL)u->Right = newnode();
			u = u->Right;
		}
	}
	if (u->cnt)failed = true;
	u->v = v;
	u->cnt++;
}
void remove_tree(Node* u) {
	if (u == NULL) return;
	remove_tree(u->Left);
	remove_tree(u->Right);
	delete u;
}
bool read_input() {
	failed = false;
	remove_tree(root);
	root = newnode();
	while (1) {
		if (scanf("%s", s) != 1)return false;
		if (!strcmp(s, "()"))break;
		int v;
		sscanf(&s[1], "%d", &v);
		addnode(v, strchr(s, ',') + 1);
	}
	return true;
}
bool bfs(vector<int>& ans) {
	queue<Node*> q;
	ans.clear();
	q.push(root);
	while (!q.empty()) {
		Node* u = q.front(); q.pop();
		if (!u->cnt) return false;
		ans.push_back(u->v);
		if (u->Left != NULL) q.push(u->Left);
		if (u->Right != NULL) q.push(u->Right);
	}
	return true;
}
int main()
{
	vector<int> ans;
	while (read_input()) {
		if (!bfs(ans)) failed = 1;
		if (failed) printf("not complete\n");
		else {
			for (int i = 0; i < ans.size(); i++) {
				if (i != 0) printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}


