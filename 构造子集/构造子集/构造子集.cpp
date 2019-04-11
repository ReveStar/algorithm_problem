// 构造子集.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


//增量构造子集
void print_subset(int n, int* A, int cur) {
	for (int i = 0; i < cur; i++)
	{
		cout << A[i];
	}
	cout << "\n";
	int s = cur ? A[cur - 1] + 1 : 0;
	for (int i =s; i < n; i++)
	{
		A[cur] = i;
		print_subset(n, A, cur + 1);
	}
}
//位向量法生成子集
void print_subset2(int n, int* B, int cur) {
	if (cur == n) {
		for (int i = 0; i < cur; i++) {
			if (B[i])cout << i;
		}
		cout << "\n";
		return;

	}
	B[cur] = 1;
	print_subset2(n, B, cur + 1);
	B[cur] = 0;	
	print_subset2(n, B, cur + 1);

}

//二进制表示子集
void print_subset3(int n, int s) {
	for (int i = 0; i < n; i++) {
		if (s&(1 << i))cout << i;
	}
	cout << "\n";
}

int main()
{
	cout << 1 & 2;
    return 0;
}

