// 均分纸牌.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//贪心法。
//

#include <iostream>
#include<vector>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int tmp;
	int n = N;
	vector<int>num;
	int sum = 0;
	while (n--) {
		cin >> tmp;
		sum += tmp;
		num.push_back(tmp);
	}
	int ave = sum / N;
	int i, j;
	for (i = 0; i < N; i++) {
		num[i] -= ave;
	}
	i = 0;
	j = N - 1;
	while (num[i] == 0) {
		i++;
	}
	while (num[j] == 0){
		j--;
	}
	int total = 0;
	while (i < j) {
		num[i + 1] += num[j];
		num[i] = 0;
		total++;
		i++;
		while (num[i] == 0) {
			i++;
		}
	}

    std::cout <<total << "\n"; 
}


