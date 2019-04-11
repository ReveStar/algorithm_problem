// ChildrenGame10905.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define maxn 51

using namespace std;

bool comp(string a, string b) {
	return a + b > b + a;
}

//贪心法


int main()
{
	int n;
	while (scanf("%d",&n) == 1&& n)
	{
		
		string number[maxn];
		for (int i = 0; i < n; i++)
		{
			/*int tmp;
			scanf("%d", &tmp);
			number[i] = (to_string(tmp));
			*/
			cin >> number[i];
		}
		sort(number, number + n, comp);
		for (int i = 0; i < n; i++)
		{
			cout << number[i];
		}
		cout << "\n";
		
	}
    
}


