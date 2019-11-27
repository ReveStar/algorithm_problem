// uva1599 IdealPath.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define _for(i,a,b) for(int i = (a); i <(b);i++)
using namespace std;
const int maxn = 100000 + 1;
int n, m;
int dist[maxn];
int vis[maxn];
void ibfs(vector<vector<int>>& input) {
	queue<int>q;
	q.push(n);

	memset(dist, 0, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	vis[n] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		_for(i, 1, n + 1) {
			if (input[u][i] != 0 && vis[i] == 0) {
				q.push(i);
				vis[i] = 1;
				dist[i] = dist[u] + 1;
			}
		}
	}
	cout << dist[1] << endl;
	
	q.push(1);
	
	int l = dist[1];
	stack<int> s;
	int c;
	while (l--) {
		while (!q.empty()) {
			int u = q.front(); q.pop();
			int dmin = dist[1];
			_for(i, 1, n + 1) {
				if (input[u][i] != 0) {
					if (dist[i] < dmin) {
						c = input[u][i];
						while (!s.empty()) {
							s.pop();

						}
						s.push(i);
					}
					else if (dist[i] == dmin) {
						if (input[u][i] < c) {
							c = input[u][i];
							while (!s.empty()) {
								s.pop();

							}
							s.push(i);
						}
						else if(input[u][i] == c) {
							s.push(i);
						}
					}
				}
			}
		}
		cout << c << " ";
		while (!s.empty()) {
			int v = s.top(); s.pop();
			q.push(v);
		}
		
	}
	return;
}

int main()
{
	cin >> n >> m;
	vector<vector<int> >input(n + 1,vector<int>(n + 1,0));
	_for(i, 0, m) {
		
			int a,b,c;
			cin >> a>>b>>c;	
			if (input[a][b] != 0) {
				input[a][b] =  c < input[a][b] ? c : input[a][b];
				input[b][a] = input[a][b];
			}
			else {
				input[a][b] = input[b][a] = c;
			}
	}

	ibfs(input);

    return 0; 
}


