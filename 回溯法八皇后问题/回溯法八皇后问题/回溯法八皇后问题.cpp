// 回溯法八皇后问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<algorithm>
using namespace std;


void search(int cur,int n) {
	int i, j;
	if (cur == n)tot++;
	else for (i = 0; i < n; i++) {
		int ok = 1;
		C[cur] = i;
		for (j = 0; j < cur; j++) {
			if (C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j]) {
				ok = 0;
				break;
			}
		}
		if (ok)search(cur + 1, n);
	}
}
int tot = 0;
int C[100];
int main()
{
    return 0;
}

