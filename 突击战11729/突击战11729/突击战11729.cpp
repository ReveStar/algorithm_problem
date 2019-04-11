// 突击战11729.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Job
{
	int j, b;
	bool operator < (const Job& x) const {
		return j > x.j;
	};
	Job(int j, int b)
	{
		this->j = j;
		this->b = b;
	};
};

int main()
{
	int n,b,j,kase = 1;
	
	while (scanf("%d",&n) == 1 && n)
	{
		vector<Job> v;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &b, &j);
			struct Job job { j, b };
			v.push_back(job);

		}
		sort(v.begin(), v.end());
		int s = 0, ans = 0;
		for (int k = 0; k < n; k++)
		{
			s += v[k].b;
			ans = max(ans, s + v[k].j);

		}
		printf("Case %d: %d\n", kase++, ans);


	}
    return 0;
}

