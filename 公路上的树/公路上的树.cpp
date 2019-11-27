// 公路上的树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
typedef struct {
	int data;
	int flag;
}loc;

int main()
{
	int L, M;
	cin >> L >> M;
	vector<loc>area;
	while (M--) {
		loc tmp1, tmp2;
		cin >> tmp1.data >> tmp2.data;
		tmp1.flag = 0;
		tmp2.flag = 1;
		area.push_back(tmp1);
		area.push_back(tmp2);

	}
	//cout << area.size();
	sort(area.begin(), area.end(), [](loc a, loc b) {return a.data <= b.data;});
	int result = 0;
	int num = 0;
	int start = -1, end = -1;
	for (int i = 0; i< area.size(); i++) {
		if (area[i].flag == 0) {
			if (num == 0 ) {
				start = area[i].data;
				num++;
			}
			else if(num != 0) {
				num++;
			}
		}
		else if (area[i].flag == 1) {
			num--;
			if (num == 0) {
				end = area[i].data;
				cout << end - start + 1 << "\n";
				result += (end - start + 1);
			}
		}

	}
    cout << L-result<<"\n"; 
}

