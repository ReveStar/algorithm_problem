// 100以内素数和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

#define MAXN 100


vector<int> sum(int maxn) {
	vector<int> result;
	vector<int> number;
	for (int i = 2; i < maxn; i++) {
		number.push_back(i);
	}
	int len = number.size();
	for (int j = 0; j < len; j++) {
		if (number[j] != 0)result.push_back(number[j]);
		else continue;
		for (int k = j + 1; k < len; k++) {
			if (number[k] % number[j] == 0)number[k] = 0;

		}
	}
	return result;
}

int main()
{
	vector<int> result;
	result = sum(MAXN);
	for (int i = 0; i < result.size(); i++)
	{
		cout <<result[i] << "\n";
	}
	return 0;
}

