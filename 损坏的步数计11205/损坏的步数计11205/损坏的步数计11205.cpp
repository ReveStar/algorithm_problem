// 损坏的步数计11205.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <set>
using namespace std;
//数组为二进制求对应的10进制数
int translate(int* s, int p) {
	int result = 0;
	for (int i = p - 1; i >= 0; i--) {
		result += s[i] * pow(2, p - i - 1);
	}
	return result;
}
//10进制数中二进制1的个数
int numberOf(int s) {
	int count = 0;
	while (s !=0)
	{
		count++;
		s = s&(s - 1);
	}
	return count;
}
int main()
{
	int number;
	cin >> number;
	while (number>0)
	{
		int P, N;
		int S[100][15];
		int T[100];
		set<int> R;
		set<int> result;
		cin >> P;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < P; j++)
			{
				cin >> S[i][j];
			}
			T[i] = translate(S[i], P);
		}
		result.clear();
		for (int k = 1; k < (1 << P); k++)
		{
			R.clear();
			for (int m = 0; m < N; m++)
			{
				R.insert(T[m] & k);

			}
			if (R.size() == N)result.insert(numberOf(k));
		}
		if (N == 1)result.insert(0);
		cout << *(result.begin())<<"\n";
		number--;
	}
	system("pause");
    return 0;
}

