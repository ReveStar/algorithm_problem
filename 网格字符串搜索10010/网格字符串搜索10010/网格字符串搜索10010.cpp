// 网格字符串搜索10010.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
	int n, m, num;
	cin >> n >> m;
	string str[50];
	string word[20];
	for(int i = 0;i<n;i++)
	{
		cin >> str[i];
		transform(str[i].begin(), str[i].end(), str[i].begin(),tolower);
	}
	cin >> num;
	for (int j = 0; j < num; j++) {
		cin >> word[j];
		transform(word[j].begin(), word[j].end(), word[j].begin(), tolower);
	}
	int count = 0;
	int row = 0, col = 0;
	for (int k = 0; k < n; k++)
	{
		for (int l = 0; l < m; l++) {
			if (str[k][l] == word[count][0]) {

			}
		}

	}
    return 0;
}
int judge(string s, int row, int col,int m,int n,int dir) {
	int r = row;
	int c = col;
	r = r - 1;


}



