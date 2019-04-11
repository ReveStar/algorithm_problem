// 生日蛋糕10167.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct pnode {
	int x, y;

}point;
point P[100];

int main()
{
	int n,m;
	cin >> n;
	while (n != 0)
	{
		
	
		for (int i = 0; i < n*2; i++)
		{
			cin >> P[i].x >> P[i].y;

		}
		int flag = 0;
		for (int A = -500; flag==0 && A <= 500; A++)
		{
			
			for (int B = -500; B <= 500; B++)
			{
				flag = 1;
				int countU = 0;
				int countD = 0;
				for (int k = 0; k < n*2; k++)
				{
					int temp = P[k].x * A + P[k].y*B;
					if (temp > 0)countU++;
					else if (temp < 0)countD++;
					else {
						flag = 0;
						break;
					}
				}
				if (countD != countU)flag = 0;
				if (flag == 1) {
					cout << A << " " << B << "\n";
					break;

				}
			}

		}
		cin >> n;
	}
	system("pause");
    return 0;
}

