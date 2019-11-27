// 砝码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int f[6] = { 1,2,3,5,10,20 };
	vector<int>w(1001, 0);
	vector<int>num;
	int n = 6;
	int sum = 0;
	while (n--) {
		int tmp;
		sum += tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	int total = 0;
	w[0] = 1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < num[i]; j++) {
			for (int k = 1000; k >= f[i]; k--) {
				if (w[k - f[i]] == 1 && w[k] == 0) {
					w[k] = 1;
					total++;
				}
			}
		}
	}
    std::cout << "Hello World!\n"; 
}

