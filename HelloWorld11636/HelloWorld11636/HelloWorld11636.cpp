// HelloWorld11636.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	int ncase = 0;
	while (scanf("%d", &n) == 1 && n > 0) {
		ncase++;
		int count = 0;
		int temp = n;
		int sum = 1;
		while (temp / 2 != 0) {
			count++;
			sum = sum * 2;
			temp = temp / 2;
		}
		if (n - sum != 0) {
			count++;
		}
		printf("Case %d: %d\n", ncase, count);
	}
	return 0;
}
