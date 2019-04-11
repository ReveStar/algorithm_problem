// TheBus Driver Problem, UVa 11389.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 101
using namespace std;

int main()
{
	int n, d, r;
	while (cin >> n >> d >> r && n) {
		int a[maxn];
		int w[maxn];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);

		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &w[i]);

		}
		sort(a, a + n);
		sort(w, w + n);
		int sum = 0;
		for (int i = 0, j = n - 1; i < n; i++,j--)
		{
			if(a[i] + w[j] > d)
				sum += (a[i] + w[j] - d)*r;
		
		}
		cout << sum << endl;
	}
	return 0;
}

