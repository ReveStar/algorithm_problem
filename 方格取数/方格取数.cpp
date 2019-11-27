// 方格取数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//多进程动态规划问题
//

#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> path;
int getNum(vector<vector<int>>& t, int i, int j) {

}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> table(N, vector<int>(N,0));
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == b == c == 0) {
			break;
		}
		table[a][b] = c;

	}

    std::cout << "Hello World!\n"; 
}

