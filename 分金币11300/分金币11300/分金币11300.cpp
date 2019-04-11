// 分金币11300.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#define maxn 1000001
#include <iostream>
using namespace std;

int main()
{
	int n;
	long long num,tot,M;
	long long * C;
	while (scanf("%d",&n) == 1)
	{
		C = (long long *)malloc(maxn * sizeof(long long));
		C[0] = 0;
		tot = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &num);
			tot += num;
			
			C[i] = C[i - 1] + num;
		}
		M = tot / n;
		
		for (int i = 1; i <= n; i++)
		{
			C[i] = C[i] - M * i;
		}
		sort(C, C + n);
		long long x1 = C[n / 2];
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += abs(x1 - C[i]);
			
		}
		//printf("%lld\n", ans);
		cout << ans << endl;
	}
    return 0;
}

