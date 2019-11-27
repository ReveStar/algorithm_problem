// 万圣节后的早晨.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
using namespace std;

#define _for(i,a,b) for(int i = (a); i < (b);i++)

const int maxn = 100;
const int maxs = 20;
char input[maxn][maxn];
int id[maxs][maxs];
int st[3];
int ed[3];
int dx[] = {1,-1,0,0,0};
int dy[] = {0,0,0,1,-1};
int deg[maxn];
int G[maxn][5];
int D1[maxn][maxn][maxn];//正向搜索
int D2[maxn][maxn][maxn];//反向搜索
deque<int> q1, q2;
int ID(int a, int b, int c) {
	return (a << 16) | (b << 8) | c;
}
bool conflict(int a, int b, int a2, int b2) {
	return (a2 == b2) || (a2 == b && b2 == a);
}
int isintersect(deque<int> q, int n) {

	_for(i, 0, q.size()) {
		if (q[i] == n) {
			return i;
		}
	}
	return -1;
}
int expand(deque<int>& q, int dir) {
	int u = q.front(); q.pop_front();
	int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;
	_for(i, 0, deg[a]) {
		int a2 = G[a][i];
		_for(j, 0, deg[b]) {
			int b2 = G[b][j];
			_for(k, 0, deg[c]) {
				int c2 = G[c][k];
				if (dir == 1) {
					if (D1[a2][b2][c2] != -1)continue;
					D1[a2][b2][c2] = D1[a][b][c] + 1;
					q.push_back(ID(a2, b2, c2));
					int index = isintersect(q2, ID(a2, b2, c2));

					if (index != -1) {
						int af = (q2[index] >> 16) & 0xff, bf = (q2[index] >> 8) & 0xff, cf = q2[index] & 0xff;
						int result = D2[af][bf][cf] + D1[a2][b2][c2];
						return result;
					}
				}
				else if (dir == 2) {
					if (D2[a2][b2][c2] != -1)continue;
					D2[a2][b2][c2] = D2[a][b][c] + 1;
					q.push_back(ID(a2, b2, c2));
					int index = isintersect(q1, ID(a2, b2, c2));

					if (index != -1) {
						int af = (q1[index] >> 16) & 0xff, bf = (q1[index] >> 8) & 0xff, cf = q1[index] & 0xff;
						int result = D1[af][bf][cf] + D2[a2][b2][c2];
						return result;
					}
				}

			}
		}
	}
	return -1;
}

int bfs() {
	
	memset(D1, -1, sizeof(D1));
	memset(D2, -1, sizeof(D2));
	q1.push_back(ID(st[0], st[1], st[2]));
	D1[st[0]][st[1]][st[2]] = 0;
	q2.push_back(ID(ed[0], ed[1], ed[2]));
	D2[ed[0]][ed[1]][ed[2]] = 0;
	int re = 0;
	while (!q1.empty() && !q2.empty()) {
		if (q1.size() < q2.size()) {
			re = expand(q1, 1);
		}
		else {
			re = expand(q2, 2);
		}
		if (re != -1)return re;
		

	}
	while (!q1.empty()) {
		re = expand(q1, 1); 
		if (re != -1)return re;
	}
	while (!q2.empty()) {
		re = expand(q2, 2);
		if (re != -1)return re;
	}
	return -1;
}


int main()
{
	int n,w,h;
	while (cin >>w>>h>>n && n) {
		int cnt = 0, x[maxn], y[maxn];
		char c = getchar();
		while (c != '\n')
			c = getchar();
		_for(i, 0, h) {
			fgets(input[i], 20, stdin);
		}

		_for(i, 0, h) {
			_for(j, 0, w) {
				if (input[i][j] != '#') {
					id[i][j] = cnt;
					x[cnt] = i; y[cnt] = j;
					if (islower(input[i][j])) {
						st[input[i][j] - 'a'] = cnt;
					}
					if (isupper(input[i][j])) {
						ed[input[i][j] - 'A'] = cnt;
					}
					cnt++;
				}
			}
		}
		_for(i, 0, cnt) {
			deg[i] = 0;
			_for(j, 0, 5) {
				int tx = dx[j] + x[i]; int ty = dy[j] + y[i];
				if (tx < 0 || tx >= h || ty < 0 || ty >= w || input[tx][ty] == '#')continue;
				G[i][deg[i]++] = id[tx][ty];

			}
		}

		if (n <= 2) {
			deg[cnt] = 1; G[cnt][0] = cnt; st[2] = ed[2] = cnt++;
		}
		if (n <= 1) {
			deg[cnt] = 1; G[cnt][0] = cnt; st[1] = ed[1] = cnt++;
		}
		cout << bfs();
	}
	
    return 0; 
}


