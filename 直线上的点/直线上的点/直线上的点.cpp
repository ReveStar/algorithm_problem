// 直线上的点.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
using namespace std;

void gcd(int a, int b, int& d, int& x, int& y)
{
	if (!b) { d = a; x = 1; y = 0; }
	else { gcd(b, a%b, d, y, x); y -= x* (a / b); }
	cout << x << y << endl;
}

int main()
{
	int d, x, y;
	int a = 6, b = 15;
	gcd(a, b, d, x, y);
	
	system("pause");
	return 0;
}

