// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

typedef int DATA;
typedef struct ChainTree {
	DATA data;
	struct ChainTree* left;
	struct ChainTree* right;
} BinChainTree;


//二叉树初始化
BinChainTree* BinTreeInit(BinChainTree* node) {
	if (node != NULL) {
		return node;
	}
	else {
		return NULL;
	}
}

int BinChainTreeAdd(BinChainTree* parent, BinChainTree* node, int loc) {
	//parent 父节点，node插入的节点，loc 插入的位置，1表示左子树，2表示右子树
	if (parent == NULL) {
		cout << "父节点不存在";
		return 0;
	}
	switch (loc) {
	case 1:
		if (parent->left) {
			cout << "左子树不为空，无法插入";
			return 0;
		}
		parent->left = node;
		break;
	
	case 2:
		if (parent->right) {
			cout < "右子树不为空，无法插入";
			return 0;
		}
		parent->right = node;
		break;
	default:
		cout << "loc参数有误";
		return 0;
	}
	return 1;
}

//获取左子树
BinChainTree* BinTreeLeft(BinChainTree* parent) {
	if (parent == NULL) {
		cout << "父节点不存在";
		return NULL;
	}
	return parent->left;
}
//获取右子树
BinChainTree* BinTreeLeft(BinChainTree* parent) {
	if (parent == NULL) {
		cout << "父节点不存在";
		return NULL;
	}
	return parent->right;
}

//检查二叉树是否为空
int BinTreeEmpty(BinChainTree* root) {
//0为空，1非空
	if (root == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

//求二叉树深度
int BinTreeDepth(BinChainTree* root) {
	int depth1, depth2;
	if (root == NULL) {
		return 0;
	}
	else {
		depth1 = BinTreeDepth(root->left);
		depth2 = BinTreeDepth(root->right);
	}
	return min(depth1, depth2) + 1;
}
//在二叉树中查找一个节点
BinChainTree* BinTreeFind(BinChainTree* root, DATA node) {
	BinChainTree* result;
	if (root == NULL) {
		return NULL;
	}
	else {
		if (root->data == node) {
			return root;
		}
		else {
			result = BinTreeFind(root->left, node);
			if (result != NULL) {
				return result;
			}
			result = BinTreeFind(root->right, node);
			return NULL;
		}
	}
}
//二叉树清空
void BinTreeClear(BinChainTree* root) {
	if (root) {
		BinTreeClear(root->left);
		BinTreeClear(root->right);
		free(root);
	}
}

//先序遍历二叉树
void BinTreeDLR(BinChainTree* root) {
	if (root) {
		BinTreeDLR(root->left);
		BinTreeDLR(root->right);
	}
}
//按层遍历
void BinTreeLevel(BinChainTree* root) {
	queue<BinChainTree*> q;
	if (root) {
		q.push(root);
		while (q.size() != 0) {
			BinChainTree* tmp = q.front();
			q.pop();
			if (tmp->left != NULL) {
				q.push(root->left);
			}
			if (tmp->right != NULL) {
				q.push(root->right);
			}
		}
	}
}







int main()
{
    std::cout << "Hello World!\n"; 
}


