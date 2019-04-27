// Subsets Enumeration Algorithm.cpp（子集树穷举算法）
//

#include <iostream>
#include <time.h> 
#include <windows.h>
#include <WinBase.h>
#include <vector>
using namespace std;
void OutputOneSubsetBinary();
void OutputOneSubset();
void Subsetting(int n);
static vector<int> x;

int main()
{
	DWORD start = 0;
	DWORD end = 0;
	int num[3] = { 0 };
	int n = 1;
	double times = 0;


	while (times < 300000)
	{
		start = GetTickCount();
		Subsetting(n);
		end = GetTickCount();
		times = (double)(end - start);
		printf("times是：%f ms\n", times);
		if (times < 60000) num[0] = n;
		else if (times < 300000) num[1] = n;
		else num[2] = n;
		n++;
	}
	/*printf("实际运行时间是：%d ms\n", end - start);*/
	printf("结果如下\n");
	printf("运行1分钟，树的深度为n=%d\n", num[0]);
	printf("运行5分钟，树的深度为n=%d\n", num[1]);
	printf("运行10分钟，树的深度为n=%d\n", num[2]);
}

void Subsetting(int n)
{
	if (n > 0) {
		x.push_back(0);
		Subsetting(n - 1);
		x.pop_back();
		x.push_back(1);
		Subsetting(n - 1);
		x.pop_back();
	}
	else {
		//OutputOneSubsetBinary();
		//OutputOneSubset();
		//printf("\n");
	}
}
static void OutputOneSubsetBinary()
{
	static int cnt = 0;
	printf("%03d: ", ++cnt);
	for (int i = x.size() - 1; i >= 0; i--)
		printf("%d", x[i]);
}
static void OutputOneSubset()
{
	printf("; {");
	int k = 0;
	for (int i = x.size() - 1; i >= 0; i--) {
		if (x[i] == 1) {
			if (k > 0)
				printf(",");
			printf("%d", x.size() - i);
			k++;
		}
	}
	printf("}");
}
