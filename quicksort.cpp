// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>

// 快排, 不稳定排序
// 优化前，最优和平均复杂度 nlogn，最差n^2
// 优化后，最差情况下复杂度变为 n

void printr(int a[], int l, int r){
	for (int i = l; i <= r; i++){
		printf("%d\r\n", a[i]);
	}
	printf("************");
}

int partition(int a[], int l, int r){
	int k = l;
	for (int i = l; i < r; i++){
		if (a[i] <= a[r]) std::swap(a[i], a[k++]);
	}
	std::swap(a[k], a[r]);
	printr(a, l, r);
	return k;
}

std::pair<int, int> partition2(int a[], int l, int r){
	int k = l;
	int m = r;
	int s = 0;
	for (int i = l; i < r-s;){
		if (a[i] < a[r]) std::swap(a[i++], a[k++]);
		else if (a[i] == a[r]){
			std::swap(a[i], a[--m]);
			s++;
		}
		else i++;
	}
	printr(a, l, r);
	int c = std::min(m - k, r - m + 1);
	for (int i = 0; i < c; i++){
		std::swap(a[k + i], a[r - i]);
	}
	printr(a, l, r);
	return std::make_pair(k, k+r-m);
}

void quicksort(int a[], int l, int r){
	if (l < r){
		int piv = partition(a, l, r);
		quicksort(a, l, piv - 1);
		quicksort(a, piv + 1, r);
	}
}

void quicksort2(int a[], int l, int r){
	if (l < r){
		auto piv = partition2(a, l, r);
		quicksort2(a, l, piv.first - 1);
		quicksort2(a, piv.second + 1, r);
	}
}

int _tmain0(int argc, _TCHAR* argv[])
{
	int a[10] = { 12, 3, 6, 0, 51, 9, 875, -1, 7, 6 };
	quicksort2(a, 0, 9);
	printr(a, 0, 9);
	getchar();
	int b[10] = { 12, 12, 12, 12 };
	quicksort2(b, 0, 3);
	printr(b, 0, 3);
	return 0;
}

