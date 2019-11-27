#include<iostream>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

const int maxn = 100001;
int num[10];

bool judge(int* n, int re, int flag) {
	int f = 0;
	int ret = re;
	bool result = false;
	for (int i = 1; i < 10; i++) {
		if (n[i] == 0)continue;
		else {
			f = 1;
			n[i]--;
			if (flag == 0) {
				re = re - i;
			}
			else {
				re = re + i;
			}
			if (judge(n, re, flag == 0 ? 1 : 0) == true)result = true;
			n[i]++;
			re = ret;
		}
	}
	if (f == 0) {
		if (re % 11 == 0)return true;
		else return false;
	}
	return result;
}

int main() {
	int c;
	cin >> c;
	int round = 1;
	while (round <= c) {
		memset(num, 0, sizeof(num));
		for (int i = 1; i < 10; i++) {
			cin >> num[i];
		}
		cout << "Case #" << round << ": ";

		if (judge(num, 0, 1) == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		round++;
	}
	return 0;

}


