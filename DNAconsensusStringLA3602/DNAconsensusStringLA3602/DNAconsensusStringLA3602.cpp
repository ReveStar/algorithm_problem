// DNAconsensusStringLA3602.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#define maxm 51
#define maxn 1001
using namespace std;

int main()
{
	
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int row, col;
		scanf("%d %d", &row, &col);
		char* str[maxm];
		for (int i = 0; i < row; i++)
		{
			str[i] = (char *)malloc(sizeof(char)*col);
			scanf("%s", str[i]);

		}
		
		int ans[maxn];
		int sum = 0;
		for (int j = 0; j < col; j++)
		{
			int num[26];
			memset(num, 0, sizeof(num));
			for (int t = 0; t < row; t++)
			{
				num[str[t][j] - 'A']++;
			}
			int loc = 0;
			if (num['C' - 'A'] > num[loc]) {
				loc = 'C' - 'A';
			}
			if(num['G'-'A'] > num[loc]) {
				loc = 'G' - 'A';
			}
			if(num['T' - 'A'] > num[loc]) {
				loc = 'T' - 'A';
			}
			//int loc = *max_element(num,num+26);
			ans[j] = loc;
			sum += (row - num[loc]);

		}
		for (int i = 0; i < col; i++)
		{
			printf("%c", (ans[i] + 'A'));
		}
		printf("\n");
		printf("%d\n", sum);

	}
	return 0;
}


