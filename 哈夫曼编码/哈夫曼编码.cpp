// 哈夫曼编码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int weight;
	int parent;
	int left;
	int right;

}HuffmanTree;
typedef char* HuffmanCode;

void selentNode(HuffmanTree* ht, int n, int* bt1, int* bt2) {
	int i;
	HuffmanTree* ht1, * ht2,*t;
	ht1 = ht2 = NULL;
	for (i = 1; i <= n; i++) {
		if (!ht[i].parent) {
			if (ht1 == NULL) {
				ht1 = ht + i;
				continue;
			}
			if (ht2 == NULL) {
				ht2 = ht + i;
				if (ht1->weight >= ht2->weight) {
					t = ht2;
					ht2 = ht1;
					ht1 = t;
					continue;
				}
			}
			if (ht1 && ht2) {
				if (ht1->weight >= ht[i].weight) {
					ht2 = ht1;
					ht1 = ht + 1;

				}
				else {
					if (ht[i].weight < ht2->weight) {
						ht2 = ht + i;
					}
				}
			}
		}

	}
	if (ht1 > ht2) {
		*bt2 = ht1 - ht;
		*bt1 = ht2 - ht;
	}
	else {
		*bt1 = ht1 - ht;
		*bt2 = ht2 - ht;
	}

}

void CreatTree(HuffmanTree* ht, int n, int* w) {
	int i, m = 2 * n - 1;
	int bt1, bt2;

	if (n <= 1)return;
	for (i = 1; i <= n; i++) {
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].left = 0;
		ht[i].right = 0;
	}
	for (; i <= m; i++) {
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].left = 0;
		ht[i].right = 0;
	}
	for (i = n + 1; i <= m; i++) {
		selectNode(ht, i - 1, &bt1, &bt2);
		ht[bt1].parent = i;
		ht[bt2].parent = i;
		ht[i].left = bt1;
		ht[i].right = bt2;
		ht[i].weight = ht[bt2].weight + ht[bt1].weight;
	}
}

int main()
{
    std::cout << "Hello World!\n"; 
}

