// 低价买股票.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 5001
using namespace std;

int main()
{
	int N;
	cin >> N;
	int n = N;
	vector<int> price;
	vector<int> flag(N, 1);
	vector<int> cnt(N, 1);
	int tmp;
	while (N--) {
		cin >> tmp;
		price.push_back(tmp);
	}
	int max1 = 1;
	int i,j;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (price[i] < price[j]) {
				flag[i] = max(flag[j] + 1, flag[i]);
			}
		}
		max1 = max(flag[i], max1);
	}
	int last;
	for (i = 1; i < n; i++) {
		last = -1;
		if (flag[i] == 1) {
			cnt[i] = 1;
			continue;
		}
		for (j = i - 1; j >= 0; j--) {
			if (flag[j] == flag[i] - 1 && price[j] > price[i] && price[j] != last) {
				cnt[i] += cnt[j];
				last = price[j];
			}
		}
	}
	int total =0;
	for (i = n - 1; i >= 0; i--) {
		if (flag[i] == max1 && price[i] != last) {
			total += cnt[i];
			last = price[i];
		}
	}

	cout << total << "\n";
}