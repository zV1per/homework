#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:10000000000")
#include <iostream>
#include "sort.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main(void)
{
	freopen("≤‚ ‘Ω·π˚.txt", "w", stdout);
	int a[10000]{ 0 };
	int b[50000]{ 0 };
	int c[200000]{ 0 };
	int d[100000][100]{ 0 };
	int temp1[200000]{ 0 }, temp2[100]{ 0 };
	
	clock_t begin = clock();
	cout << "insertSort" << endl;
	insertSort(a, 10000);
	clock_t end = clock();
	int duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	insertSort(b, 50000);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	insertSort(c, 200000);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	for (int i = 0; i < 100000; i++)
	{
		insertSort(d[i], 100);
	}
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< endl;

	cout << "MergeSort" << endl;

	begin = clock();
	MergeSort(a, 0, 49999, temp1);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	MergeSort(b, 0, 99999, temp1);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	MergeSort(c, 0, 199999, temp1);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	for (int i = 0; i < 100000; i++)
	{
		MergeSort(d[i], 0, 99, temp2);
	}
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< endl;

	cout << "QuickSort_Recursion" << endl;

	begin = clock();
	QuickSort_Recursion(a, 0, 9999);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	QuickSort_Recursion(b, 0, 49999);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	QuickSort_Recursion(c, 0, 199999);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	for (int i = 0; i < 100000; i++)
	{
		QuickSort_Recursion(d[i], 0, 99);
	}
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< endl;

	cout << "CountSort" << endl;

	begin = clock();
	CountSort(a, 0, 9999);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	CountSort(b, 0, 49999);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	CountSort(c, 0, 199999);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	for (int i = 0; i < 100000; i++)
	{
		CountSort(d[i], 0, 99);
	}
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< endl;

	cout << "RadixCountSort" << endl;

	begin = clock();
	RadixCountSort(a, 10000);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	RadixCountSort(b, 50000);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	RadixCountSort(c,200000);
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< '\t';

	begin = clock();
	for (int i = 0; i < 100000; i++)
	{
		RadixCountSort(d[i], 100);
	}
	end = clock();
	duration = (end - begin) ;
	cout << duration <<"ms"<< endl;

	return 0;
}

int main11(void) 
{
	int cnt = 0;
	int a[1000]{ 0 };
	freopen("≈≈–Ú.txt", "r", stdin);
	while (cin.peek()!=-1)
	{
		cin >> a[cnt];
		cnt++;
	}
	RadixCountSort(a, cnt);
	freopen("≈≈–Ú.txt", "w", stdout);
	for (size_t i = 0; i < cnt; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}
