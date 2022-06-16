#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

extern int count;

int partition(std::vector<int>&, const int, const int);

int partition2(std::vector<int>&, const int, const int);

int partition3(std::vector<int>&, const int, const int);

void quick_sort(std::vector<int>&, const int, const int);


#endif
