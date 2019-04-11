// 有超能力的纸牌玩家131.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
string Output[] = {
	"highest-card","one-pair","two-pairs","three-of-a-kind","straight","flush","full-house","four-of-a-kind","straight-flush"
};
int suit[4];
int hand[15];
int card[10][2];
int cToInt(char c) {
	switch (c)
	{
	case 'A':
		return 1;
	case 'T':
		return 10;
	case 'J':
		return 11;
	case 'Q':
		return 12;
	case 'K':
		return 13;
	case 'C':
		return 0;
	case 'D':
		return 1;
	case 'H':
		return 2;
	case 'S':
		return 3;
	default:
		return c - '0';
	}
}
int judge(int h[15], int s[4],int pro) {
	
	int count = 0;
	int cnum = *max_element(h, h + 15);
	int snum = *max_element(s, s + 4);
	if (cnum == 2) {
		count = 1 < pro ? 1:pro;
		
	}
	int number = 0,number3 = 0;
	for (int i = 0; i < 15; i++) {
		if (h[i] == 2)number++;
		if (h[i] == 3)number3++;
	}
	if (number == 2)count = 2 < pro ? 2 : pro;
	if (cnum == 3)count = 3 < pro ? 3 : pro;
	int flag = 0;

	for (int i = 0; i < 15; i++) {
		if (h[i] == 1)flag++;
		else flag = 0;
	}
	if (flag == 5 && snum != 5)count = 4 < pro ? 4 : pro;
	
	if (flag != 5 && snum == 5)count = 5 < pro ? 5 : pro;
	if (number == 1 && number3 == 1)count = 6 < pro ?6 : pro;
	if (cnum == 4)count = 7 < pro ? 7 : pro;
	
	

	if (snum == 5 && flag == 5)count = 8 < pro ? 8 : pro;
	return count;

}

int meiju(int pro) {
	int result = 0;
	int begin = pow(2, 9) + pow(2, 8) + pow(2, 7) + pow(2, 6) + pow(2, 5);
	int loc[10];
	for (int i = begin; i >= pow(2, 5) - 1; i--) {
		memset(suit, 0, sizeof(suit));
		memset(hand, 0, sizeof(hand));
		memset(loc, 0, sizeof(loc));
		for (int j = i,m = 0; j; j = j/2,m++)
		{
			loc[m] = j % 2;
		}
		int num = 0;
		for (int k = 0; k < 10; k++)
		{

			if (loc[k] == 1) {
				num++;
				hand[card[k][0]]++;
				suit[card[k][1]]++;
			}
		}
		if (num != 5)continue;
		hand[14] = hand[1];
		int temp = judge(hand, suit,pro);
		result = temp > result ? temp:result;

	}
	
	return result;
}


int main()
{
	string I[10];
	int pro = 8;
	while (cin >> I[0]) {
		for (int i = 1; i < 10; i++)
		{
			cin >> I[i];
		}
		
		memset(card, 0, sizeof(card));
		
		for (int i = 0; i < 10; i++)
		{	
				card[i][0]= cToInt(I[i][0]);
				card[i][1] = cToInt(I[i][1]);	
		}
		
		
		cout << "Hand: ";
		for (int i = 0; i < 5; i++) {
			cout << I[i] << " ";
		}
		cout << "Deck: ";
		for (int i = 5; i < 10; i++)
		{
			cout << I[i] << " ";
		}
		cout << "Best hand: ";
		int t = meiju(pro);
		cout << Output[t]<<"\n";
		if (t == 0)pro = 8;
		else pro = pro - 1;


	}
    return 0;
}

