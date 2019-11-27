#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 100001;

int main() {
	int c;
	cin >> c;
	int round = 1;
	while (round <= c) {
		int papernum;
		cin >> papernum;
		int cite[maxn];
		for (int i = 0; i < papernum; i++) {
			int tmp;
			cin >> tmp;
			cite[i] = (tmp);
		}

		int re = 0;
		cout << "Case #" << round << ": ";
		for (int j = 0; j < papernum; j++) {
			
			sort(cite, cite + j + 1,greater<int>());
			
			int flag = 0;
			for (int k = 0; k <= j; k++) {
				if (cite[k] >= k + 1) {
					re = k + 1;
				}
				if (cite[k] < k + 1) {
					cout << re << " ";
					flag = 1;
					break;
				}

			}
			if (flag == 0) {
				cout << re << " ";
			}

		}
		cout << endl;
		round++;
	}
	return 0;
}