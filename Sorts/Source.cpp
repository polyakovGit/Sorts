#include <iostream>
#include <vector>

void quickSort(std::vector<int> &vec, int start,int end) {
	int i = start, j = end, pivot = vec[end / 2];
	do {
		while (vec[i] < pivot)++i;
		while (vec[j] > pivot)--j;
		if (i <= j) {
			std::swap(vec[i++], vec[j--]);
		}
	} while (i <= j);
	if (i < end)quickSort(vec, start+i,end-i);
	if (j > 0)quickSort(vec, 0, j);
}

void bubbleSort(std::vector<int>& vec) {
	for (size_t k = vec.size() - 1; k > 0; --k) {
		for (size_t i = 0; i < k; ++i) {
			if (vec[i] > vec[i + 1])
				std::swap(vec[i], vec[i + 1]);
		}
	}
}

void evenOddSort(std::vector<int>& vec) {
	for (size_t i = 0, j = 0; i < vec.size(); ++i){
		if (!(vec[i] & 1)){//if ! first even, logic AND
			std::swap(vec[i], vec[j++]);
		}
	}
}
void vectorShow(const std::vector<int>& vec) {
	for (auto &num : vec)
		std::cout << num << ' ';
	//copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}
int main() {
	std::vector<int> vec{ 5,1,4,3,2,6 };
	//bubbleSort(vec);
	//evenOddSort(vec);
	quickSort(vec, 0,vec.size()-1);
	vectorShow(vec);


}