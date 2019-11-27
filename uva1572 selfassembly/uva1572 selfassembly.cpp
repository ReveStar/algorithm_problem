// uva1572 selfassembly.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

#define _for(i,a,b) for(int i = (a);i < (b);i++)
using namespace std;
const int maxn = 52;
int G[maxn][maxn];
int vis[maxn];
int ID(char a1, char a2) {
	return (a1 - 'A') * 2 + (a2 == '+' ? 0 : 1);
}
void connect(char a1, char a2, char b1, char b2) {
	if (a1 == '0' || b1 == '0')return;
	int u = ID(a1, a2)^1, v = ID(b1, b2);
	G[u][v] = 1;
}
bool dfs(int u) {
	vis[u] = -1;
	_for(v, 0, 52) if(G[u][v]) {
		if (vis[v] < 0)return true;
		if (!vis[v] && dfs(v))return true;
	}
	vis[u] = 1;
	return false;
}
bool find_cycle() {
	_for(i, 0, 52)if (!vis[i]) {
		if (dfs(i))return true;
	}
	return false;
}

int main()
{
	int n;
	char s[10];
	while (cin >> n && n) {
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		while (n--) {
			scanf("%s", s);
			_for(i, 0, 4) {
				_for(j, 0, 4)if (i != j) {
					connect(s[i * 2], s[i * 2 + 1], s[j * 2], s[j * 2 + 1]);
				}
			}

		}
		if (find_cycle()) {
			cout << "unbounded\n";
		}
		else {
			cout << "bounded\n";
		}
	}

    return 0; 
}


