// 分解质因数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sushu(int maxn) {
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

bool isprimer(int number, vector<int>& primetable) {
	vector<int>::iterator it = find(primetable.begin(), primetable.end(), number);
	if (it != primetable.end()) {
		return true;
	}
	else {
		return false;
	}
}

vector<int> find(int num,vector<int>& primetable) {
	vector<int> result;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			int j = num / i;
			if (isprimer(j,primetable))result.push_back(j);
			else {
				vector<int> tmp = find(j, primetable);
				result.insert(result.end(),tmp.begin(),tmp.end());
			}
			if (isprimer(i, primetable))result.push_back(i);
			else {
				vector<int> tmp = find(i, primetable);
				result.insert(result.end(), tmp.begin(), tmp.end());
			}
		}
		
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	vector<int> primetable = sushu(n);
	vector<int> re = find(n, primetable);
	for (int i = 0; i < re.size(); i++) {
		cout << re[i] <<"\n";
	}
     
}

