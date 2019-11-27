// 题三.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int judge(int x, int y, float m, float n, int a, int b) {
	float re = (x - m) * (x - m) / (a * a) + (y - n) * (y - n) / (b * b);
	if (re <= 1)return 1;
	else return 0;
}


int main()
{
	int n, a, b;
	vector<pair<int, int>> locate;
	cin >> n >> a >> b;
	int x,y;
	while (n--)
	{
		cin >> x >> y;
		locate.push_back(make_pair(x,y));
	}
	int result = 0;
	for (int i = 0; i < locate.size(); i++) {
		int num = 0;
		for (int j = 0; j < locate.size() && i!= j; j++)
		{
			int re = judge(locate[j].first, locate[j].second, locate[i].first, locate[i].second, a, b);
			if (re == 1)num++;
			
		}
		if (result < num) result == num;


		num = 0;
		for (int j = 0; j < locate.size() && i != j; j++)
		{
			int re = judge(locate[j].first, locate[j].second, (float)locate[i].first + (float)a / 2, (float)locate[i].second + (float)b / 2, a, b);
			if (re == 1)num++;

		}
		if (result < num) result == num;

		num = 0;
		for (int j = 0; j < locate.size() && i != j; j++)
		{
			int re = judge(locate[j].first, locate[j].second, (float)locate[i].first + (float)a / 2, (float)locate[i].second - (float)b / 2, a, b);
			if (re == 1)num++;

		}
		if (result < num) result == num;

		num = 0;
		for (int j = 0; j < locate.size() && i != j; j++)
		{
			int re = judge(locate[j].first, locate[j].second, (float)locate[i].first - (float)a / 2, (float)locate[i].second + (float)b / 2, a, b);
			if (re == 1)num++;

		}
		if (result < num) result == num;

		num = 0;
		for (int j = 0; j < locate.size() && i != j; j++)
		{
			int re = judge(locate[j].first, locate[j].second, (float)locate[i].first - (float)a / 2, (float)locate[i].second - (float)b / 2, a, b);
			if (re == 1)num++;

		}
		if (result < num) result == num;
		
		
		num = 0;
		for (int k = 0; k < locate.size() && i != k; k++)
		{
			int re = judge(locate[k].first, locate[k].second, locate[i].first, locate[i].second, b, a);
			if (re == 1)num++;
			
		}
		if (result < num) result == num;

		num = 0;
		for (int k = 0; k < locate.size() && i != k; k++)
		{
			int re = judge(locate[k].first, locate[k].second, (float)locate[i].first + (float)a / 2, locate[i].second + b / 2, a, b);
			if (re == 1)num++;

		}
		if (result < num) result == num;

		num = 0;
		for (int k = 0; k < locate.size() && i != k; k++)
		{
			int re = judge(locate[k].first, locate[k].second, (float)locate[i].first + (float)a / 2, (float)locate[i].second - (float)b / 2, a, b);
			if (re == 1)num++;

		}
		if (result < num) result == num;

		num = 0;
		for (int k = 0; k < locate.size() && i != k; k++)
		{
			int re = judge(locate[k].first, locate[k].second, (float)locate[i].first - (float)a / 2, (float)locate[i].second + (float)b / 2, a, b);
			if (re == 1)num++;

		}
		if (result < num) result == num;


		num = 0;
		for (int k = 0; k < locate.size() && i != k; k++)
		{
			int re = judge(locate[k].first, locate[k].second, (float)locate[i].first - (float)a / 2, (float)locate[i].second - (float)b / 2, a, b);
			if (re == 1)num++;

		}
		if (result < num) result == num;
	
	}
	cout << result;
    return result; 
}



