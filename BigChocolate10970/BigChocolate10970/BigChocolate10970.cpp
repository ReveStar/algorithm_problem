// BigChocolate10970.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int m, n;
	while (scanf("%d%d",&m,&n)==2)
	{
		int ans = (n - 1)*m + (m - 1);
		printf("%d\n", ans);
	}
	return 0;
}


