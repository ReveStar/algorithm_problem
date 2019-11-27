#include<iostream>
#include<queue>
#include <vector>
#include<algorithm>
#include <string.h>
using namespace std;
#define _for(i,a,b) for(int i = (a); i< (b);i++)

const int maxn = 101;
vector<vector<char>>num;
bool judge(vector<vector<char>>& num, int n) {
	bool re = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (num[i][j] == '.') {
				re = false;
				return re;
			}
		}
	}
	return true;
}
struct node {
	vector<vector<char>>xy;
	int move;
};
int main() {
	int c;
	cin >> c;
	int round = 1;
	while (round <= c) {
		int N;
		cin >> N;
		
		char ctr = getchar();
		while (ctr != '\n') {
			ctr = getchar();
		}
		for (int i = 0; i < N; i++) {
			vector<char>tmp;
			_for(j, 0, N) {
				char t;
				cin >> t;
				tmp.push_back(t);
			}
			num.push_back(tmp);
		}
		cout << "Case #" << round << ": ";
		int result = 0;
		if (judge(num, N) == true) {
			cout << result << endl;
			round++;
			continue;
		}
		queue<struct node*> q;
		struct node* start = new node();
		start->xy.assign(num.begin(),num.end());
		start->move = 0;
		q.push(start);
		bool result = false;
		while (!q.empty()) {
			struct node* u = q.front(); q.pop();
			_for(i, 0, 5) {
				struct node* t = new node();
				t->xy.assign(u->xy.begin(), u->xy.end());
				t->move = u->move + 1;
				_for(j, 0, N) {
					_for(k, 0, N) {
						if (j + k == i) {
							t->xy[j][k] = t->xy[j][k] == '.' ? '#' : '.';
						}
					}
				}
				if (judge(t->xy, N) == true) {
					cout << t->move << endl;
					result = true;
					break;
				}
				else {
					q.push(t);
				}
			}
			if (result)break;
			_for(i,-2, 2) {
				struct node* t = new node();
				t->xy.assign(u->xy.begin(), u->xy.end());
				t->move = u->move + 1;
				_for(j, 0, N) {
					_for(k, 0, N) {
						if (j - k == i) {
							t->xy[j][k] = t->xy[j][k] == '.' ? '#' : '.';
						}
					}
				}
				if (judge(t->xy, N) == true) {
					cout << t->move << endl;
					result = true;
					break;
				}
				else {
					q.push(t);
				}
			}
			if (result)break;
		}
		round++;

	}
	return 0;

}