#include <iostream>
#include <vector>
#include <thread>

template <typename T>
void quickSort(std::vector<T>& vec, size_t start, size_t end) {
	size_t i = start, j = end - 1;
	T pivot = vec[end / 2];
	while (i <= j) {
		while (vec[i] < pivot)++i;
		while (vec[j] > pivot)--j;
		if (i <= j) {
			std::swap(vec[i++], vec[j--]);
		}
	};
	if (i < end)quickSort(vec, start + i, end - i);
	if (j > 0)quickSort(vec, start, j);
}
template <typename T>
void bubbleSort(std::vector<T>& vec) {
	for (size_t k = vec.size() - 1; k > 0; --k) {
		for (size_t i = 0; i < k; ++i) {
			if (vec[i] > vec[i + 1])
				std::swap(vec[i], vec[i + 1]);
		}
	}
}

template <typename T>
void evenOddSort(std::vector<T>& vec) {
	for (size_t i = 0, j = 0; i < vec.size(); ++i) {
		if (!(vec[i] & 1)) {//if ! first even, logic AND
			std::swap(vec[i], vec[j++]);
		}
	}
}
template <typename T>
void vectorShow(const std::vector<T>& vec) {
	for (auto& num : vec)
		std::cout << num << ' ';
	//copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
}

void merge(std::vector<int>& vec, int left, int middle, int right) {
	int i = left, j = middle + 1, count = right - left + 1;
	std::vector<int> tempVec;
	tempVec.reserve(count);
	for (int k = 0; k < count; ++k) {
		if (i <= middle && j <= right) {
			if (vec[i] < vec[j])
				tempVec.push_back(vec[i++]);
			else tempVec.push_back(vec[j++]);
		}
		else {
			if (i <= middle)
				tempVec.push_back(vec[i++]);
			else tempVec.push_back(vec[j++]);
		}
	}
	for (int k = left, i = 0; k <= right; ++k, ++i)
		vec[k] = tempVec[i];
}

void mergeSort(std::vector<int>& vec, int left, int right) {
	if (left >= right)return;
	int middle = left + (right - left) / 2;
	mergeSort(vec, left, middle);
	mergeSort(vec, middle + 1, right);
	merge(vec, left, middle, right);
}

void mergeThreads(std::vector <int>& vec, int left, int middle, int right) {
	int i = left, j = middle + 1, count = right - left + 1;
	std::vector<int> tempVec;
	tempVec.reserve(count);
	for (int k = 0; k < count; ++k) {
		if (i <= middle && j <= right) {
			if (vec[i] < vec[j])
				tempVec.push_back(vec[i++]);
			else tempVec.push_back(vec[j++]);
		}
		else {
			if (i <= middle)
				tempVec.push_back(vec[i++]);
			else tempVec.push_back(vec[j++]);
		}
	}
	for (int k = left, i = 0; k <= right; ++k, ++i)
		vec[k] = tempVec[i];
}

void mergeSortThreads(std::vector<int>& vec, int left, int right) {
	if (left >= right) return;
	int middle = left + (right - left) / 2;
	std::thread firstThread(mergeSortThreads, std::ref(vec), left, middle);
	std::thread secondThread(mergeSortThreads, std::ref(vec), middle + 1, right);
	firstThread.join();
	secondThread.join();
	mergeThreads(vec, left, middle, right);
}

int main() {
	std::vector<int> vec{ 5,1,4,3,2,6 };
	//bubbleSort(vec);
	//evenOddSort(vec);
	//std::cout << vec.size();
	//mergeSort(vec, 0, vec.size()-1);
	//mergeSortThreads(vec, 0, vec.size() - 1);
	quickSort(vec, 0, vec.size());
	vectorShow(vec);


}