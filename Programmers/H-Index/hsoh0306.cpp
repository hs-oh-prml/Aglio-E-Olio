#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace::std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), greater<int>());
	int h = 0;

	for (int i = 0; i < citations.size(); i++) {
		cout << citations[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < citations.size(); i++) {
		h = citations[i];
		answer++;
		if (answer >= h) {
			break;
		}
	}
	return h;
}

int main(void) {
	vector<int> test;
	test.push_back(3);
	test.push_back(0);
	test.push_back(6);
	test.push_back(1);
	test.push_back(5);
	cout << solution(test) << endl;
}