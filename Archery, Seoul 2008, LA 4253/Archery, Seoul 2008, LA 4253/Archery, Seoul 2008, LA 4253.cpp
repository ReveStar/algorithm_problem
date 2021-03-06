// Archery, Seoul 2008, LA 4253.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define esp 1e-6
#define maxn 5010

using namespace std;
//angel = Math.atan2(y, x)
struct Area
{
	double d, xl, xr;
}line[maxn];
double w;
int n;
int judge(double pos) {
	double sangle = atan2(line[0].d, line[0].xr - pos);
	double bangle = atan2(line[0].d, line[0].xl - pos);
	for (int i = 1; i < n; i++)
	{
		double sangle2 = atan2(line[i].d, line[i].xr - pos);
		double bangle2 = atan2(line[i].d, line[i].xl - pos);
		if (sangle > bangle2 ) {
			return -1;//点往右移
		}
		else if (bangle < sangle2 ) {
			return 0;//点往左移
		}
		else {
			sangle = max(sangle, sangle2);
			bangle = min(bangle, bangle2);
		}
	}
	return 1;
}

bool cmp(Area &a, Area &b) {
	return a.d < b.d;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		
		scanf("%lf", &w);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf", &line[i].d, &line[i].xl, &line[i].xr);
		}
		//sort(line, line + (int)n, cmp);
		double left = 0, right = w;
		int flag = false;
		while (right - left > esp)
		{
			double mid = (left + right) / 2;
			int tmp = judge(mid);
			if (tmp == -1) {
				left = mid;
			}
			else if (tmp == 0) {
				right = mid;
			}
			else {
				flag = true;
				break;
			}
		}
		flag ? printf("YES\n"):printf("NO\n");

	}
	return 0;
}


