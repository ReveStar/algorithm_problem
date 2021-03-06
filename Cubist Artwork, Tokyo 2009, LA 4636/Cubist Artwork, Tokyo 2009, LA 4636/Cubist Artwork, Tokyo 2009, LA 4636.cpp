// Cubist Artwork, Tokyo 2009, LA 4636.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int w, d, tot, x, a[21], b[21];
int main()
{
	cin.sync_with_stdio(false);
	while (cin >> w >> d && w && d)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int ans = 0;
		for (int i = 1; i <= w; i++)
		{
			cin >> x;
			a[x]++;
		}
		for (int i = 1; i <= d; i++)
		{
			cin >> x;
			b[x]++;
		}
		for (int i = 1; i <= 20; i++) ans += i * max(a[i], b[i]);
		cout << ans << endl;
	}

}

