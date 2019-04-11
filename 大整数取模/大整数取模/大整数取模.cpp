// 大整数取模.cpp: 定义控制台应用程序的入口点。
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
int main()
{
	char n[MAX];
	int m;
	scanf("%s %d", n, &m);
	int ans = 0;
	int len = strlen(n);
	for (int i = 0; i < len; i++)
	{
		
		ans = (int)(((long long)ans * 10 + (n[i] - '0')) % m);
	}
	printf("%d\n", ans);
	system("pause");
	return 0;
}

