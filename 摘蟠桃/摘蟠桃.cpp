// 摘蟠桃.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;



int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	vector<vector<int>>p(M, vector<int>(N, 0));
	int result = 0;
	int loci = 0, locj = 0;
	int Max = 0;
	for (int m = 0; m < M;m++) {
		for (int i = 0; i < N;i++) {
			cin >> p[m][i];
		}
	}
	int time = 0;
	int prei = 0, prej = 0;
	while (1) {
		int m, i;
		for (m= 0; m < M; m++) {
			for (i = 0; i < N; i++) {
				if (p[m][i] > Max) {
					loci = m;
					locj = i;
					Max = p[m][i];
				
				}
			}
		}
		if (Max == 0)break;
		int tmp = 0;
		if (prei == 0 && prej == 0) {
			tmp = loci + 1;
		}
		else {
			tmp = abs(loci - prei) + abs(locj - prej);
		}

		if (time + 1 + tmp + loci + 1 > K) {
			break;
		}
		else {
			result += Max;
			prei = loci;
			prej = locj;
			time += tmp;
			time++;
			p[loci][locj] = 0;
			Max = 0;
		}

	}
	
	


    cout << result <<"\n"; 
}


