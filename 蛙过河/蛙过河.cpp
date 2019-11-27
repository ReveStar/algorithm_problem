// 蛙过河.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;

struct locate {
	int num;
	int flag;//1 右 2 左 0 空

	locate(int n, int f) {
		num = n;
		flag = f;
	}
};

void swapl(vector<struct locate>& locs,int i, int j) {
	struct locate l = locate(locs[i].num, locs[i].flag);
	locs[i].num = locs[j].num;
	locs[i].flag = locs[j].flag;
	locs[j].num = l.num;
	locs[j].flag = l.flag;
}

int find(vector<struct locate> locs) {
	int re = -1;
	if (locs[1].flag == 2 && locs[0].flag == 2 && locs[2].flag == 2 && locs[4].flag == 1 && locs[5].flag == 1 && locs[6].flag == 1)return 0;
	for (int i = 0; i < locs.size(); i++) {
		if (locs[i].flag == 0) {
			if (i - 1 >= 0 && locs[i - 1].flag == 1) {
				swapl(locs, i, i - 1);
				int tmp = find(locs);
				if (tmp >= 0)re = re == -1 ? tmp : re < tmp ? re : tmp;
				swapl(locs, i, i - 1);
			}
			if (i - 2 >= 0 && locs[i - 2].flag == 1) {
				swapl(locs, i, i - 2);
				int tmp = find(locs);
				if (tmp >= 0)re = re == -1 ? tmp : re < tmp ? re : tmp;
				swapl(locs, i, i - 2);
			}
			if (i + 1 < locs.size() && locs[i + 1].flag == 2) {
				swapl(locs, i, i + 1);
				int tmp = find(locs);
				if (tmp >= 0)re = re == -1 ? tmp : re < tmp ? re : tmp;
				swapl(locs, i, i + 1);
			}
			if (i + 2 < locs.size() && locs[i + 2].flag == 2) {
				swapl(locs, i, i +2);
				int tmp = find(locs);
				if (tmp >= 0)re = re == -1 ? tmp : re < tmp ? re : tmp;
				swapl(locs, i, i + 2);
			}
			if (re == -1) {
				return -1;
			}
			return re + 1;
		}
	}
	return re;
}

int main()
{
	vector<struct locate> locs;
	locs.push_back(locate(1, 1));
	locs.push_back(locate(2, 1));
	locs.push_back(locate(3, 1));
	locs.push_back(locate(0, 0));
	locs.push_back(locate(4, 2));
	locs.push_back(locate(5, 2));
	locs.push_back(locate(6, 2));
	int re = find(locs);
	cout << re;
	return re;
	
}


