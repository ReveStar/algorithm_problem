// TheHorseRacingLA3266.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 1010
using namespace std;

int main()
{
	int n;
	while (scanf("%d",&n) == 1 && n)
	{
		int q[maxn];
		int t[maxn];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &t[i]);

		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &q[i]);

		}
		sort(t, t + n);
		sort(q, q + n);
		int a1 = 0, a2 = n - 1, b1 = 0, b2 = n - 1, sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (t[a1] > q[b1]) {
				a1++;
				b1++;
				sum += 1;

			}
			else if (t[a2] > q[b2]) {
				a2--;	
				b2--;
				sum += 1;
			}
			else if (t[a1] < q[b2]) {
				a1++;
				b2--;
				sum -= 1;
			}
			else {
				a1++;
				b2--;
			}
		}
		printf("%d\n", sum*200);
	}
	return 0;
}

