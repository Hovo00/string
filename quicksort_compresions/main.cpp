#include "quicksort.h"
#include <fstream>
#include <vector>
#include <iostream>

int main() {
	std::ifstream rfile("input.txt");
	std::vector<int> file_content;
	int temp = 0;
	while (rfile >> temp) {
		file_content.push_back(temp);
	}
	for (auto i : file_content) {
		std::cout << i << " ";
	}
	quick_sort(file_content, 0, file_content.size() - 1);
	std::cout<<std::endl;
	for (auto i : file_content) {
		std::cout << i << " ";
	}
	std::cout<<std::endl<<"Number of compresions - "<<count<<std::endl;
}
