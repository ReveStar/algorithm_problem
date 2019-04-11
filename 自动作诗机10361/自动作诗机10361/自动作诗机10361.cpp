// 自动作诗机10361.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 100
using namespace std;


int main()
{
	int n;
	string str[MAXN];
	string s[MAXN][5];
	string::size_type position1,position2;
	cin >> n;
	for (int i = 0; i < n *2; i++)
	{
		cin >> str[i];
	}
	/*for (int j = 0; j < n * 2; j++)
	{
		if(j%2 == 0)
			position1 = str[j].find('<');
			position2 = str[j].find('>');
			s[j / 2][0] = str[j].substr(0, position1);
			s[j / 2][1] = str[j].substr(position1 + 1,position2 -1 -position1 );
			position1 = str[j].find('<', position2);
			s[j / 2][2] = str[j].substr(position2 + 1,position1 -1 - position2 );
			position2 = str[j].find('>', position1);
			s[j / 2][3] = str[j].substr(position1 + 1, position2 - 1 -position1);
			s[j / 2][4] = str[j].substr(position2 + 1);
			cout << s[j / 2][0] + s[j / 2][1] + s[j / 2][2] + s[j / 2][3] + s[j / 2][4] << "\n";
		
		
		if (j % 2 != 0) {
			str[j].replace(str[j].find('.'), 3, s[j / 2][3] + s[j / 2][2] + s[j / 2][1] + s[j / 2][4]);
			cout << str[j] << "\n";
		}
	}*/

    return 0;
}

