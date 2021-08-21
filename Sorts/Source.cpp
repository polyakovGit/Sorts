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

void merge(std::vector<int>& vec, int left, int right, int middle) {
	int j = left, k = middle + 1, count = right - left + 1;
	std::vector<int> vecTemp;
	vecTemp.reserve(count);
	for (int i = 0; i < count; ++i) {
		if (j <= middle && k <= right) {
			if (vec[j] < vec[k])
				vecTemp.push_back(vec[j++]);
			else vecTemp.push_back(vec[k++]);
		}
		else {
			if (j <= middle)
				vecTemp.push_back(vec[j++]);
			else vecTemp.push_back(vec[k++]);
		}
	}
	for (int i = left, j = 0; i <= right; ++i, ++j)
		vec[i] = vecTemp[j];
}

void mergeSort(std::vector<int> &vec, int left, int right) {
	if (left >= right)return;
	int middle = left + (right - left) / 2;
	mergeSort(vec, left, middle);
	mergeSort(vec, middle + 1, right);
	merge(vec, left, right, middle);
}

int main() {
	std::vector<int> vec{ 5,1,4,3,2,6 };
	//bubbleSort(vec);
	//evenOddSort(vec);
	std::cout << vec.size();
	//mergeSort(vec, 0, vec.size()-1);
	//quickSort(vec, 0,vec.size()-1);
	vectorShow(vec);


}