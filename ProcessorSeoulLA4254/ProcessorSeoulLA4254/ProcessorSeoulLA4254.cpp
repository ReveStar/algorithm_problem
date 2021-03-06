// ProcessorSeoulLA4254.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
#define maxn 10010

struct Task
{
	int r;
	int d;
	int w;
	bool operator <(const Task& t)const {
		return d > t.d;
	}

}P[maxn];
priority_queue<Task> q;
int n;
int cmp(const Task a, const Task b) {
	return a.r < b.r;
}
bool check(int speed) {
	while (!q.empty())
		q.pop();
	int start = 0, time = 1;
	while (1) {
		while (start < n&&P[start].r<time)
		{
			q.push(P[start++]);
		}
		int tmp = speed;
		while (tmp && !q.empty()) {
			Task t = q.top();
			q.pop();
			int MIN = min(t.w, tmp);
			tmp -= MIN;
			t.w -= MIN;
			if (t.w > 0) {
				q.push(t);
			}
		}
		time++;
		if (!q.empty() && q.top().d < time) {
			return false;
		}
		if (q.empty() && start == n) {
			return true;
		}
	}
}

int main()
{
	int num;
	cin >> num;
	while (num--)
	{
		int sum = 0;
		cin >> n;
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																														
		for (int i = 0; i < n; i++)
		{
			cin >> P[i].r >> P[i].d >> P[i].w;
			sum += P[i].w;
		}
		sort(P, P + n,cmp);
		int left = 0, right = sum;
		while (left < right) {
			int mid = (left + right) / 2;
			if (check(mid)) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		printf("%d\n", left);

	}
}
