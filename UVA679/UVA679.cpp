// UVA679.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
#define _for(i,a,b) for(int i = (a); i< (b);i++)
int main()
{
	int l, D, I;
	cin >> l;
	while (l--) {
		cin >> D >> I;
		int k = 1;
		_for (i, 1, D) {
			if (I % 2) {
				k = 2 * k;
				I = (I + 1)/ 2;
			}
			else {
				k = 2 * k + 1;
				I = I / 2;
			}
		}
		cout << k << endl;
	}
	return 0;
}


