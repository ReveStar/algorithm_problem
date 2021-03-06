// WateringGrass10382.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct locr
{
	double begin;
	double end;
};

bool compare(struct locr a, struct locr b) {
	return a.begin < b.begin;
}

double getLen(double r, double  w) {
	return sqrt(r*r - w * w / 4);
}

int main()
{
	int n, l, w;
	while (scanf("%d %d %d", &n, &l, &w) != EOF) {
		struct locr *allp = (struct locr *)malloc(sizeof(struct locr)*n);
		int tot = 0;
		for (int i = 0; i < n; i++)
		{
			int p, r;
			double b, d;
			scanf("%d%d", &p, &r);
			if (r <= w / 2)continue;
			double temp = getLen((double)r,(double)w);
			b = (double)p - temp;
			allp[tot].begin = b > 0 ? b : 0;
			allp[tot].end = p + temp;
			tot++;
		}
		sort(allp, allp + tot, compare);
		double origin = 0;
		double tar = 0;
		int sum = 0;
		int flag = true;
		if (allp[0].begin > 0) {
			printf("-1\n");
			flag = false;
		}
		else {

			for (int i = 0; i < n; i++)
			{
				if (allp[i].begin <= origin) {
					if (allp[i].end > tar) {
						tar = allp[i].end;
					}
				}
				else {
					origin = tar;
					sum++;
					if (origin >= l) {
						printf("%d\n", sum);
						flag = false;
						break;
					}
					if (allp[i].begin <= origin) {
						if (allp[i].end > tar) {
							tar = allp[i].end;
						}
					}
					else {
						printf("-1\n");
						flag = false;
						break;
					}
				}
			}
		}
		if (!flag)continue;
		if (tar < l) {
			printf("-1\n");
		}
		else {
			printf("%d\n", ++sum);
		}
	}

	return 0;
}


