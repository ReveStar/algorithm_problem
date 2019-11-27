// uva297 quadtrees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//答案有误

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getp(string s, int index, int d) {
	int result = 0;
	int num = (32 >> d) * (32 >> d);
	int lo = index;
	for (int m = 1; m <= 4; m++) {
		if (m == 1) {
			lo++;
		}
		else {
			if (s[lo] == 'p') {
				lo = lo + 5;
			}
			else {
				lo++;
			}
		}
		if (s[lo] == 'f') {
			result += num;
		}
		else if (s[lo] == 'p') {
			result += getp(s, lo, d + 1);
		}
	}
	return result;
}
int getpixel(string s1,int index1, string s2,int index2, int d) {
	int result = 0;
	int num = (32 >> d) * (32 >> d);
	int p1 = index1 + 1, p2 = index2 + 1;
	for (int k = 0; k < 4; k++) {
		if (k != 0) {
			if (s1[p1] == 'p') {
				p1 = p1 + 5;
			}
			else {
				p1++;
			}
			if (s2[p2] == 'p') {
				p2 = p2 + 5;

			}
			else {
				p2++;
			}
		}
		if (s1[p1] == 'f' || s2[p2] == 'f') {
			result += num;
		}
		else if (s1[p1] == 'p' && s2[p2] != 'p' ) {
			result += getp(s1, p1, d + 1);
		}
		else if (s2[p2] == 'p' && s1[p1] != 'p') {
			result += getp(s2, p2, d + 1);
		}
		else if (s2[p2] == 'p' && s1[p1] == 'p') {
			result += getpixel(s1, p1, s2, p2, d + 1);
		}
	}
	return result;
}


int main()
{
	int r;
	cin >> r;
	while (r--) {
		string s1,s2;
		cin >> s1;
		cin >> s2;
		if (s1[0] == 'f' || s2[0] == 'f') {
			cout << "There are " << 32 * 32 << " black pixels." <<endl;
		}
		else if (s1[0] == 'p' && s2[0] != 'p') {
			cout << "There are " << getp(s1, 0, 1) << " black pixels." << endl;
		}
		else if (s2[0] == 'p' && s1[0] != 'p') {
			cout << "There are "  <<getp(s2, 0, 1) << " black pixels." << endl;
		}
		else if (s2[0] == 'p' && s1[0] == 'p') {
			cout << "There are " << getpixel(s1, 0, s2, 0, 1) << " black pixels." << endl;
		}

	}
	return 0;
}


