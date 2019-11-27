// 数字金字塔.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int R;
	cin >> R;
	vector<vector<int>> Row;
	int rtmp = R;
	int tmp;
	while (rtmp--) {
		vector<int> num;
		while (cin >> tmp) {
			
			num.push_back(tmp);
			char ch = getchar();
			if (ch == '\n') {
				Row.push_back(num);
				break;
			}
		}
	}
	vector<vector<int>> flag;
	vector<int> n(1, Row[0][0]);
	flag.push_back(n);
	int r = 1;
	while (r < R) {
		vector<int>t;

		for (int i = 0; i < Row[r].size(); i++) {
			if (i == 0) {
				t.push_back(flag[r - 1][i] + Row[r][i]);
			}
			else if (i == Row[r].size() - 1) {
				t.push_back(flag[r - 1][i - 1] + Row[r][i]);
			}
			else {
				t.push_back(max(flag[r - 1][i], flag[r - 1][i - 1]) + Row[r][i]);
			}

		}
		flag.push_back(t);
		r++;
	}

	int end = flag.size() - 1;
	int result = 0;
	for (int j = 0; j < flag[end].size(); j++)
	{
		result = max(flag[end][j], result);
	}

    cout <<result << "\n"; 
}

