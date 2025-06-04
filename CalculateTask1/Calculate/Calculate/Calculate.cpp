#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>  // for setprecision

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::function;
using std::fixed;
using std::setprecision;

/**
 * @brief 주어진 정수 배열의 모든 원소들의 합을 계산합니다.
 * 
 * @param numbers n개의 정수를 담고 있는 백터
 * @return int 배열 원소들의 합계
 */
int calculateSum(const vector<int>& numbers) {
	int sum = 0;
	for (int num : numbers) {
		sum += num;
	}
	return sum;
}

/**
 * @brief 주어진 정수 벡터의 원소들의 평균값을 계산합니다.
 *
 * @param numbers n개의 정수를 담고 있는 백터
 * @return int 평균
 */
double calculateAverage(const vector<int>& numbers) {
	if (numbers.empty()) return 0.0;
	return static_cast<double>(calculateSum(numbers)) / numbers.size();
}

/**
 * @brief 삽입 정렬(Insertion Sort) 알고리즘을 이용하여 주어진 벡터를 정렬합니다.
 *
 * 이 함수는 삽입 정렬 알고리즘을 사용하여 정렬을 수행합니다. 삽입 정렬은 작은 데이터셋에서 효율적이며 구현이 간단한 장점이 있습니다.
 * 
 * @param numbers 정렬할 정수 벡터 (const 참조)
 * @param compare 두 원소의 대소를 비교하는 함수 객체. 예:
 *        - 오름차순: [](int a, int b) { return a < b; }
 *        - 내림차순: [](int a, int b) { return a > b; }
 * 
 * @return vector<int> 정렬된 결과를 담은 새로운 벡터
 * 
 * @note 이 함수는 원본 벡터를 수정하지 않으며, 정렬된 복사본을 반환합니다.
 */

vector<int> insertionSort(const vector<int>& numbers, function<bool(int, int)> compare) {
	vector<int> sorted = numbers;

	for (size_t i = 1; i < sorted.size(); ++i) {
		int key = sorted[i];
		size_t j = i;

		while (j > 0 && compare(key, sorted[j - 1])) {
			sorted[j] = sorted[j - 1];
			--j;
		}
		sorted[j] = key;
	}
	return sorted;
}

/**
 * @brief 벡터의 모든 요소를 출력합니다.
 */
void printArray(const vector<int>& arr) {
	for (size_t i = 0; i < arr.size(); ++i) {
		cout << arr[i];
		if (i != arr.size() - 1) cout << ", ";
	}
	cout << endl;
}

int main() {
	int n, choiceSortNumber;

	cout << "Input how many numbers: ";
	cin >> n;

	if (n <= 0) {
		cout << "Invalid number count. Must be greater than 0." << endl;
		return 1;
	}

	vector<int> numbers(n);
	cout << "Input " << n << " numbers: ";
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	cout << "\nPlease enter 1 (ascending) or 2 (descending): ";
	cin >> choiceSortNumber;

	function<bool(int, int)> comp;
	if (choiceSortNumber == 1)
		comp = [](int a, int b) { return a < b; };  // ascending
	else if (choiceSortNumber == 2)
		comp = [](int a, int b) { return a > b; };  // descending
	else {
		cout << "Invalid choice. Defaulting to ascending sort.\n";
		comp = [](int a, int b) { return a < b; };
	}

	vector<int> sorted = insertionSort(numbers, comp);
	int sum = calculateSum(sorted);
	double avg = calculateAverage(sorted);

	cout << fixed << setprecision(2); // 평균값 소수점 둘째 자리까지 출력
	cout << "\nSum: " << sum << endl;
	cout << "Average: " << avg << endl;
	cout << "Sorted numbers: ";
	printArray(sorted);

	return 0;
}
