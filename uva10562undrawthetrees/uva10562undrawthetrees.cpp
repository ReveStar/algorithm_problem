// uva10562undrawthetrees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include<string.h>
using namespace std;

#define _for(i,a,b) for(int i = (a); i< (b);i++)

const int maxn = 205;
char input[maxn][maxn];
int T;

string gettree(char c, int i, int j) {
	
	string result = "";
	if (input[i + 1][j] == '|') {
		int start = 0,end = -1;
		for (int m = j; m >= 0; m--) {	
			if (input[i + 2][m] == ' ') {
				start = m;
				break;
			}
	
		}
		/*_for(n, j, maxn) {
			if (input[i + 2][n] == ' '|| input[i + 2][n] == '\0' || input[i + 2][n] == '\n') {
				end = n;
				break;
			}
		}*/
		_for(k, start, maxn) {
			if (input[i + 2][k] == ' ' || input[i + 2][k] == '\0' || input[i + 2][k] == '\n' || input[i + 3][k] == '\n')break;
			if (isalpha(input[i + 3][k]))result += gettree(input[i + 3][k], i + 3, k);
		}
		return string(1,c) + "(" + result + ")";

	}
	else {
		return result + c + "()";
	}
}

int main()
{
	cin >> T;
	while (T--) {
		
		char c = getchar();
		while (c != '\n') {
			c = getchar();
		}
		int i = 0;
		while (1) {
			fgets(input[i], 200, stdin);
			if (input[i][0] == '#')break;
			i++;
		}
		string re = "";
		_for(a, 0, maxn) {
			
			if (isalpha(input[0][a])) {
				re += gettree(input[0][a], 0, a);
				break;
			}
		}
		cout << "(" << re << ")" << endl;
	}
	return 0;
}


