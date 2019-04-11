// 程序库.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define MAXN 1000



int main()
{
    return 0;
}

//拓扑排序
int c[MAXN];
int topo[MAXN], t;
bool dfs(int u) {
	c[u] = -1;
	for (int v = 0; v < n; v++)if (G[u][v]) {
		if (c[v] < 0)return false;
		else if (!c[v] && !dfs(v))return false;


	}
	c[u] = 1; topo[--t] = u;
	return true;
}
bool toposort() {
	t = n;
	memset(c, 0, sizeof(c));
	for (int u = 0; u < n; u++)if (!c[u]) {
		if (!dfs(u))return false;

	}
	return true;
}


