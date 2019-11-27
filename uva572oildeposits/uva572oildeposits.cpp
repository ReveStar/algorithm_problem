// uva572oildeposits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
#define _for(i,a,b) for(int i = (a); i<(b);i++)
const int maxn = 101;
char input[maxn][maxn];
int idx[maxn][maxn];
int m, n;
void dfs(int r, int c, int id) {
	if (r < 0 || r >= m || c < 0 || c >= n)return;
	if (idx[r][c] > 0 || input[r][c] != '@')return;
	idx[r][c] = id;
	_for(dr, -1, 2) {
		_for(dc, -1, 2) {
			if (dr != 0 || dc != 0)dfs(r + dr, c + dc, id);
		}
	}
}
int main()
{
	
	while (cin >> m >> n && m && n) {
		_for(i, 0, m) {
			scanf("%s", input[i]);
		}
		memset(idx, 0, sizeof(idx));
		int cnt = 0;
		_for(i, 0, m) {
			_for(j, 0, n) {
				if (idx[i][j] == 0 && input[i][j] == '@') {
					
					dfs(i, j, ++cnt);
				}
				
			}
		}
		cout << cnt << endl;

	}
	return 0;
}


