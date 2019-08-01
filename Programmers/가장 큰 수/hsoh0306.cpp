#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

bool compare(const int & a, const int & b) {
	string A = to_string(a);
	string B = to_string(b);
	int i = 0;
	int j = 0;

	if (A.size() == B.size()) {
		return a > b;
	}
	while (i < A.size() && j < B.size()){
		if (A[i] > B[j]) {
			return true;
		}
		else if (B[j] > A[i]) {
			return false;
		}
		else {
			if (i < A.size() - 1) {
				i++;
			}
			if (j < B.size() - 1) {
				j++;
			}
			if (j == B.size() - 1 && i == A.size() - 1) {
				if (B.size() > A.size()) {
					return A[0] > B[A.size()];
				}
				else {
					return B[0] < A[B.size()];
				}
			}

		}
	}
}

void merge(int *arr, int size, int start, int mid, int end) {
	int *temp = new int[size];

	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i <= mid && j <= end) {
		if (compare(arr[i], arr[j])) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	for (int index = start; index <= end; index++) {
		arr[index] = temp[index];
	}
}
void merge_sort(int *arr, int size, int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		merge_sort(arr, size, start, mid);
		merge_sort(arr, size, mid + 1, end);

		merge(arr, size, start, mid, end);
		for (int i = 0; i < size; i++) {
//			cout << arr[i] << " ";
		}
//		cout << endl;
	}
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);
	int size = numbers.size();
	int *arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = numbers[i];
	}

//	merge_sort(arr, size, 0, size - 1);
//	sort(numbers.begin(), numbers.end(), compare);
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0 && answer != "") {
			if (answer[0] == '0') {
				continue;
			}
			else {
				answer += to_string(numbers[i]);
			}
		}
		else {
			answer += to_string(numbers[i]);
		}
	}
	return answer;
}

int main(void) {
	vector<int> test1;
	vector<int> test2;

	/*
	test1.push_back(6);
	test1.push_back(10);
	test1.push_back(2);

	cout << solution(test1) << endl;
	*/
	test2.push_back(3);
	test2.push_back(30);
	test2.push_back(34);
	test2.push_back(5);
	test2.push_back(9);

	vector<int> test3;
	test3.push_back(403);
	test3.push_back(40);
//	test3.push_back(1000);
//	test3.push_back(0);
	cout << solution(test3) << endl;
//	compare1(3, 30);
//	compare(40, 403);
}