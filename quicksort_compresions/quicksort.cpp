#include "quicksort.h"
#include <iostream>

int count = 0;

//First element as pivot
int partition(std::vector<int>& arr, const int start, const int end)
{	
	count += (end - start);
	int pivot = arr[start];
	int i = start;
	for (int j = i + 1; j <= end; ++j) {
		if (arr[j] <= pivot) {
			std::swap(arr[++i], arr[j]);
		}
	}
	std::swap(arr[start], arr[i]);
	return i;
}

// Last element as pivot
int partition2(std::vector<int>& arr, const int start, const int end)
{
	std::swap(arr[end], arr[start]);
	return partition(arr, start, end);
}

//Median of tree as pivot 
int partition3(std::vector<int>& arr, const int start, const int end)
{
	int mid = (start + end) / 2;
	int median = std::max(std::min(arr[start], arr[mid]), std::min(std::max(arr[start], arr[mid]), arr[end]));
	int pivot_index = arr[start] == median ? start : arr[end] == median ? end : mid;
	std::swap(arr[pivot_index], arr[start]);
	return partition(arr, start, end);
}

void quick_sort(std::vector<int>& arr, const int start, const int end)
{
	if (start >= end) {
		return;
	}
	int pos = partition(arr, start, end);
	quick_sort(arr, start, pos - 1);
	quick_sort(arr, pos + 1, end);
}
