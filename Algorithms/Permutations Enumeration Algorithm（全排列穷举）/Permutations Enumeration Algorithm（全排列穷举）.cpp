// Permutations Enumeration Algorithm（全排列穷举）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include <time.h> 
#include <windows.h>
#include <WinBase.h>
#include <vector>
#include <utility>
using namespace std;
void Permuting(int i);
static vector<int> s;
static int N;

void PermutingCaller(int n);
void Permuting(int i);
void OutputOnePermutation();
int main()
{
	clock_t start, end;
	double times = 0;
	int num[3] = { 0 };
	int n =3;
	


	while (times < 600)
	{
		start = clock();

		PermutingCaller(n);

		end = clock();
		times = (double)(end - start) / CLOCKS_PER_SEC;
		/*printf("times是：%lf s\n", times);*/
		if (times < 60) num[0] = n;
		else if (times < 300) num[1] = n;
		else num[2] = n;
		n++;
	}
	/*printf("实际运行时间是：%d ms\n", end - start);*/
	printf("结果如下\n");
	printf("运行1分钟，树的深度为n=%d\n", num[0]);
	printf("运行5分钟，树的深度为n=%d\n", num[1]);
	printf("运行10分钟，树的深度为n=%d\n", num[2]);
}
void PermutingCaller(int n)
{
	N = n;
	for (int i = 0; i < n; ++i)
		s.push_back(i + 1);
	Permuting(0);
}
void Permuting(int i)
{
	if (i < N - 1) {
		for (int j = i; j < N; ++j) {
			swap(s[i], s[j]);
			Permuting(i + 1);
			swap(s[i], s[j]);
		}
	}
	else
		OutputOnePermutation();
}
void OutputOnePermutation()
{
	static int cnt = 0;
	printf("%03d: ", ++cnt);
	for (auto x : s)
		printf("%d", x);
	printf("\n");
}
