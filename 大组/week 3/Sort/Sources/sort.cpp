#include "sort.h"
#include "cstdlib"
#include <iostream>
using namespace std;

void insertSort(int* a, int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] <= a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void MergeArray(int* a, int begin, int mid, int end, int* temp)
{
	int ptr1 = begin, ptr2 = mid, ptrt = begin;
	while (ptr1 <= mid-1  && ptr2 <= end)
	{
		if (a[ptr1] <= a[ptr2])
		{
			temp[ptrt++] = a[ptr1++];
		}
		else
		{
			temp[ptrt++] = a[ptr2++];
		}
	}
	if (ptr1> mid-1 )
	{
		while (ptr2 <= end)
		{
			temp[ptrt++] = a[ptr2++];
		}	
	}
	else
	{
		while (ptr1 <= mid-1 )
		{
			temp[ptrt++] = a[ptr1++];
		}
	}
	for (int i = begin; i <= end; i++)
	{
		a[i] = temp[i];
	}
}

void MergeSort(int* a, int begin, int end, int* temp)
{
	if ((end - begin)  > 0)
	{
		MergeSort(a, begin, begin + (end - begin) / 2 , temp);
		MergeSort(a, begin + (end - begin) / 2 +1, end, temp);
	}
	MergeArray(a, begin, begin + (end - begin) / 2 +1, end, temp);
}

void QuickSort_Recursion(int* a, int begin, int end)
{
	if (end > begin)
	{
		int low = begin, high = end, temp = 0;
		int i = a[begin];
		while (low < high)
		{
			while (low < high && i <= a[high])
			{
				high--;
			}
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
			while (low < high && i >= a[low])
			{
				low++;
			}
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
		QuickSort_Recursion(a, begin, low);
		QuickSort_Recursion(a, low + 1, end);
	}
}

void QuickSort(int* a, int size)
{
}

int Partition(int* a, int begin, int end)
{
	int low = begin, high = end, i = a[begin], temp = 0;
	while (low < high)
	{
		while (low < high && i <= a[high])
		{
			high--;
		}
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
		while (low < high && i >= a[low])
		{
			low++;
		}
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
	}
	return low;
}

void CountSort(int* a, int size, int max)
{
	int maxx = a[0], minn = a[0],cnt=0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] > maxx)
		{
			maxx = a[i];
		}
		if (a[i] < minn)
		{
			minn = a[i];
		}
	}
	int* temp = (int*)malloc(sizeof(int) * (maxx - minn + 1));
	if (temp==nullptr)
	{
		return;
	}
	for (int i = 0; i < maxx-minn+1; i++)
	{
		temp[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		temp[a[i] - minn]++;
	}
	for (int i = 0; i < maxx - minn + 1; i++)
	{
		while (temp[i]--)
		{
			a[cnt++] = i + minn;
		}
	}
	free(temp);
}

void RadixCountSort(int* a, int size)
{
	int* temp = (int*)malloc(sizeof(int) * 10), div = 10;
	int* t = (int*)malloc(sizeof(int) * size);
	if (temp == nullptr&&t == nullptr)
	{
		return;
	}
	while (true)
	{
		for (int i = 0; i < 10; i++)
		{
			temp[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			t[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			temp[(a[i] / (div / 10)) % 10]++;
		}
		if (temp[0]==size)
		{
			break;
		}
		for (int i = 1; i < 10; i++)
		{
			temp[i] += temp[i - 1];
		}
		
		for (int i = size - 1; i >= 0; i--)
		{
			t[--temp[(a[i] / (div / 10)) % 10]] = a[i];
		}
		for (int i = 0; i < size; i++)
		{
			a[i] = t[i];
		}
		div *= 10;
	}
	free(temp);
	free(t);
}

void ColorSort(int* a, int size)
{
	int low = 0, high = size - 1, cur = 0;
	int temp = 0;
	while (high >= cur)
	{
		if (a[cur] == 0)
		{
			temp = a[cur];
			a[cur] = a[low];
			a[low++] = temp;

		}
		if (a[cur] == 2)
		{
			temp = a[cur];
			a[cur] = a[high];
			a[high--] = temp;
		}
		else
		{
			cur++;
		}
	}
}

int Find(int* a, int begin, int end, int k)
{
	int i = 0;
	i = Partition(a, begin, end);
	if (i == k - 1)
	{
		return a[k - 1];
	}
	else if(i==begin)
	{
		return Find(a, begin+1, end, k);
	}
	else if (i > k - 1)
	{
		return Find(a, begin, i, k);
	}
	else
	{
		return Find(a, i, end, k);
	}
	cout << "11";
}
