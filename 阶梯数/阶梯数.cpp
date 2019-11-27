// 阶梯数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;



int main()
{
	int start = 1;
	while (true) {
		cout << "当前值：" << start << "\n";
		if (start % 7 != 0) {
			start++;
		}
		else {
			if (start % 2 == 1 && start % 3 == 2 && start % 5 == 4 && start % 6 == 5) {
				cout << "结果" <<  start;
				break;
			}
			else {
				start++;
			}
		}
	}
    
}
