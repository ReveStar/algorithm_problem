// AllInAll10340.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
	string str,substr;
	while (cin>>substr>>str)
	{
		int substrlen = substr.length();
		int strlen = str.length();
		int j = 0;
		int i = 0;
		while (i < substrlen && j < strlen) {
			if (substr[i] == str[j]) {
				++i;
				++j;
			}
			else {
				++j;
			}
		}
		(i==substrlen) ? printf("YES\n") : printf("NO\n");
	}
	return 0;

}


