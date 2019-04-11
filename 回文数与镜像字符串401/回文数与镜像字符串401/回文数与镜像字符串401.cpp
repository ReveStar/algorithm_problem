#include"stdio.h"
#include"string.h"
#include"ctype.h"

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";  //定义镜像串有关的常量数组
const char* output[] = { " -- is not a palindrome."," -- is a mirrored string."," -- is a regular palindrome."," -- is a mirrored palindrome." }; //输出有关的常量数组

char jud(char x)
{
	if (isalpha(x)) //判断是否为字母，如果是字母的情况下
		return rev[x - 'A'];
	else           //如果是数字的情况下
		return rev[x - '0' + 25];
}

int main()
{
	int i, p, m, l;
	char s[20];      //由题目给出的范围可知
	while (scanf("%s", s) == 1)   //这里注意不要用"&s"
	{
		l = strlen(s);
		p = 1;
		m = 1;
		for (i = 0; i<(l + 1) / 2; i++)
		{
			if (s[i] != s[l - i - 1]) p = 0;    //判断是否回文
			if (s[i] != jud(s[l - i - 1])) m = 0;  //判断是否镜像
		}
		printf("%s%s\n\n", s, output[p * 2 + m]);
	}
	return 0;
}