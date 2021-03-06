// Slalom11627.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-9, PI = 3.1415926535897932384626433832795;
const int mod = 1000000000 + 7;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const int maxn = 100000 + 10;
int T, n, m, w, v, s, b[maxn * 10];
struct node {
	double x, y;
	node(double x = 0, double y = 0) :x(x), y(y) {}
}a[maxn];
bool ok(int mid) {
	double l = a[1].x, r = a[1].x + w;
	for (int i = 2; i <= n; i++) {
		double dist = a[i].y - a[i - 1].y;
		double t = dist / mid;
		l = l - t * v;
		r = r + t * v;
		l = max(a[i].x, l);
		r = min(a[i].x + w, r);
		if (l > r && fabs(r - l) > eps) return false;
	}
	return true;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &w, &v, &n);
		for (int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
		scanf("%d", &s);
		for (int i = 1; i <= s; i++) scanf("%d", &b[i]);
		sort(b + 1, b + s + 1);
		int l = 1, r = s, mid;
		while (r > l) {
			mid = (l + r + 1) >> 1;
			if (ok(b[mid])) l = mid;
			else r = mid - 1;
		}
		if (ok(b[l])) printf("%d\n", b[l]);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}

