// Wonder Team, Tehran 2007, LA 4094.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n) {
		int ans;
		if (n >= 5)ans = n;
		else ans = (n == 4 ? 2 : 1);
		printf("%d\n", ans);
	}
	return 0;
}

