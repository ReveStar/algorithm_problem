// BuildingDesigning11039.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#define maxn 500000
using namespace std;

bool compare(int a, int b) {
	if (abs(a) < abs(b)) {
		return true;
	}
	else {
		return false;
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		
		int num;
		scanf("%d", &num);
		int *data = (int*)calloc(num+1,sizeof(int));
		memset(data, 0, sizeof((num + 1) * sizeof(int)));
		for (int i = 0; i < num; i++)
		{
			int temp;
			scanf("%d", &temp);
			data[i] = temp;
		}
		sort(data, data + num,compare);
		int ans = 1;
		int flag = data[0] > 0 ? 1:0;
		for (int j = 1; j < num; j++)
		{
			int tmp = data[j] > 0 ? 1 : 0;
			if (tmp != flag) {
				ans++;
				flag = tmp;
			}
		}
		printf("%d\n", ans);

	}
	return 0;
    
}
