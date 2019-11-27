// 题目1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//题目结论，如果上排数列中存在0，那么判断上排数列中没有0，1，2，n-4这四个数，那么下排数列无解，如果有这4个数，那么下排数列中0出现的次数为n-4；1出现的次数为2，2出现的次数为1；n-4出现的次数为1；其余为零。
//如果上排数列中不存在0，那么下排数列全为0，而且是唯一解。
#include <iostream>
#include <vector>
using namespace std;
#define _for(i,a,b) for(int i = (a); i < (b);i++)

const int maxn = 100;
int main()
{
	vector<int> input;
	
	int tmp;
	while (cin >> tmp) {
		input.push_back(tmp);
	}
	int num = input.size();
	vector<int> result(num, 0);
	int count = 0;
	if (input[0] != 0) {
		return 0;
	}
	_for(i, 0, num) {
		switch (input[i]) {
		case 1:
			count++;
			result[i] = 2;
			break;
		case 2:
			count++;
			result[i] = 1;
			break;
		case num-4:
			count++;
			result[i] = 1;
			break;
		case 0:
			count++;
			result[i] = num - 4;
			break;
		}
	}
	if (count != 4) {
		cout << "wujie";
	}
    return 0; 
}

