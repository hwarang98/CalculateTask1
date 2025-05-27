#include <iostream>
#include <array>

using namespace std;

/**
 * @brief 주어진 정수 배열의 모든 원소들의 합을 계산합니다.
 * 
 * @param numbers 5개의 정수를 담고 있는 std::array<int, 5> 타입의 배열 (상수 참조)
 * @return int 배열 원소들의 합계
 */
int calculateSum(const array<int, 5>& numbers) {
	int sum = 0;
	for (int i = 0; i < numbers.size(); ++i) {
		sum += numbers[i];
	}
	return sum;
}

/**
 * @brief 주어진 정수 배열의 원소들의 평균값을 계산합니다.
 * 
 * @param numbers 5개의 정수를 담고 있는 std::array<int, 5> 타입의 배열 (상수 참조)
 * @return double 배열 원소들의 평균값
 */
double calculateAverage(const array<int, 5>& numbers) {
	// 배열 전체를 복사하기엔 메모리 낭비 즉, numbers를 참조후 원본내용을 변경못하게 들고오자
	int sum = calculateSum(numbers);
	return static_cast<double>(sum) / static_cast<double>(numbers.size());
}

/**
 * @brief 삽입 정렬(Insertion Sort) 알고리즘을 이용하여 주어진 배열을 오름차순 또는 내림차순으로 정렬합니다.
 *
 * 이 함수는 삽입 정렬 알고리즘을 사용하여 정렬을 수행합니다. 삽입 정렬은 작은 배열에서 효율적이며 구현이 간단한 장점이 있습니다.
 * 
 * @param numbers 정렬할 5개의 정수를 담은 std::array<int, 5> 타입의 배열 (상수 참조)
 * @param choiceSortNumber 정렬 방향을 지정하는 값
 *        - 1: 오름차순 정렬
 *        - 2: 내림차순 정렬
 * @return array<int, 5> 정렬된 결과를 담은 새 배열
 *
 * @note choiceSortNumber가 1이나 2가 아닌 경우에도 기본적으로 정렬 조건에 따라 동작하므로,
 *       올바른 값을 전달하는 것이 중요합니다.
 */
array<int, 5> insertionSort(const array<int, 5>& numbers, int choiceSortNumber)
{
	/* TODO: choiceSortNumber == 1 오름차순 정렬 choiceSortNumber == 2 내림차순 정렬
		1. 삽입정렬 구현 (배열의 크기가 작을때 효율적, 구현도 간단)
			참고: 다른 알고리즘은?
			버블 정렬: 구현 간단하지만 삽입 정렬보다 조금 느림
			선택 정렬: 구현 간단하나 교환 횟수가 많음
			퀵 정렬, 병합 정렬: 큰 배열에 적합, 5개 정도엔 오히려 오버헤드 발생
	*/
	array<int, 5> sortNumberList = numbers;  // 원본 배열 복사

 
	if (choiceSortNumber == 1) // 오름차순
	{
		for (int i = 1; i < sortNumberList.size(); ++i)
		{
			int key = sortNumberList[i];
			int j = i - 1;

			// key보다 큰 원소들을 오른쪽으로 한 칸씩 이동
			while (j >= 0 && sortNumberList[j] > key)
			{
				sortNumberList[j + 1] = sortNumberList[j];
				--j;
			}
			sortNumberList[j + 1] = key; // 배열 첫번쨰 요소에 sortNumberList[i] 할당
		}
	}
	else if (choiceSortNumber == 2) // 내림차순
	{
		for (int i = 1; i < sortNumberList.size(); ++i)
		{
			int key = sortNumberList[i];
			int j = i - 1;

			// key보다 작은 원소들을 오른쪽으로 한 칸씩 이동
			while (j >= 0 && sortNumberList[j] < key)
			{
				sortNumberList[j + 1] = sortNumberList[j];
				--j;
			}
			sortNumberList[j + 1] = key;
		}
	}
	return sortNumberList;
}


void printArray(const array<int, 5>& arr) {
	cout << arr[0] << ", " << arr[1] << ", " << arr[2] << ", " << arr[3];
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i];
		if (i != arr.size() - 1) cout << ", ";
	}
	cout << endl;
}

int main() {

	int a, b, c, d, e; // 배열 인풋
	int choiceSortNumber; // 정렬 알고리즘 선택

	cout << "input 5 Numbers:\n";
	cin >> a >> b >> c >> d >> e;

	cout << "Please enter 1 or 2.\n1 is for ascending order sort\n2 is for descending order sort.\ninput here: ";
	cin >> choiceSortNumber;

	array<int, 5> numbers = {a, b, c, d, e};
	array<int, 5> sortNumberList = insertionSort(numbers, choiceSortNumber);

	int sumResult = calculateSum(sortNumberList);
	double averageResult = calculateAverage(sortNumberList);
	
	cout << "sum result: " << sumResult << endl;
	cout << "average result: " << averageResult << endl;
	cout << sortNumberList[0] << "," << sortNumberList[1] << "," << sortNumberList[2] << "," << sortNumberList[3] << "," << sortNumberList[4] << endl;

	return 0;
}