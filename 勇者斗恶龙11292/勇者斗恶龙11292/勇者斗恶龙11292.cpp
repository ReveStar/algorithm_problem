// 勇者斗恶龙11292.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define maxn 20001
using namespace std;

int main() {
	int n, m;
	int dir[maxn], man[maxn];
	while (scanf("%d %d", &n, &m) != 0) {
		if (n == 0 && m ==0) {
			return 0;
		}
		
		for (int l = 0; l < n; ++l) {
			scanf("%d", &dir[l]);
		}
		for (int j = 0; j < m; ++j) {
			scanf("%d", &man[j]);
		}
		sort(dir, dir + n);
		sort(man, man + m);
		int sum = 0;
		int i = 0, k = 0;
		while (i < n&&k<m)
		{

			if (man[k] >= dir[i]) {
				sum += man[k];
				i++; k++;
			}
			else {
				k++;
			}
		}
		if (i == n)printf("%d\n", sum);
		else printf("Loowater is doomed!\n"); 

	}
	return 0;
}
