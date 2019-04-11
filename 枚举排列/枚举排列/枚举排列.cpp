// 枚举排列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

#define MAXN 1000
using namespace std;

//生成1-n的排列
void print_permutation(int n, int* A, int cur) {
	int i, j;
	if (cur == n) {
		for (i = 0; i < n; i++)
		{
			cout<< A[i];
			
		}
		cout << "\n";
	}
	else for ( i = 1; i <= n; i++)
	{
		int ok = 1;
		for (j = 0; j < cur; j++)
		{
			if (A[j] == i)ok = 0;
		}
		if (ok) {
			A[cur] = i;
			print_permutation(n, A, cur + 1);
		}
	}
}




int main()
{
	int num;
	int A[MAXN];
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> A[i];
	}
	sort(A, A + num);
	do {
		for (int i = 0; i < num; i++) {
			cout << A[i];
		}
		cout << "\n";
	} while (next_permutation(A, A + num));
	
    return 0;
}

