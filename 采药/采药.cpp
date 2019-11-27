// 采药.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int time;
	int profit;
}med;
int getProfit(vector<med>& m, int t, int i) {
	if (i == m.size() - 1) {
		if (t >= m[i].time) {
			return m[i].profit;
		}
		return 0;
	}
	if (m[i].time > t) {
		return getProfit(m, t, i + 1);
	}
	return max(getProfit(m, t, i + 1),m[i].profit + getProfit(m, t - m[i].time, i + 1));
}
int main()
{

	int T, M;
	cin >> T >> M;
	vector<med> pro;
	while (M--) {
		med tmp1;
		cin >> tmp1.time >> tmp1.profit;
		pro.push_back(tmp1);
	}
	int result = getProfit(pro, T, 0);

    std::cout << result <<"\n"; 
}

