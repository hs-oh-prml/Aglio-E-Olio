#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace::std;

int cmp(vector<int> arr, int h, int flag) {
	int count = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (flag == 0) {
			if (arr[i] >= h)
				count++;
		}
		if (flag == 1) {
			if (arr[i] <= h) 
				count++;
		}
	}
	return count;
}
/*
int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<int>());

	for (int i = 0; i < citations.size(); i++) {
		cout << citations[i] << " ";
	}
	cout << endl;
	int h;

	for (h = citations[0]; h > 0; h--) {
		int a = cmp(citations, h, 0); // bigger
		int b = cmp(citations, h, 1); // smaller
		if (a >= h && b <= h) {
			break;
		}
	}
	return h;
}
*/

int bigger(int key, vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		if (key <= v[i]) {
			return v.size() - i;
		}
	}
	return v[v.size() - 1];
}

int smaller(int key, vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		if (key <= v[i]) {
			return i + 1;
		}
	}
	return v[v.size() - 1];
}

int solution(vector<int> citations) {
	int answer = 0;

	//sort
	sort(citations.begin(), citations.end());

	int max = citations[citations.size() - 1];

	for (int i = max; i >= 0; --i) {
		// i보다 작거나 같은 것의 갯수
		int small = smaller(i, citations);
		//i 보다 크거나 같은 것의 갯수
		int big = bigger(i, citations);

		if ((big >= i) && (i >= small)) {
			return i;
		}
	}
}

int main(void) {
	vector<int> test;
	test.push_back(0);
	test.push_back(0);
//	test.push_back(0);
//	test.push_back(0);
//	test.push_back(5);
	cout << solution(test) << endl;
}