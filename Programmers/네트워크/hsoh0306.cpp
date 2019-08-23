#include<iostream>
#include<vector>

using namespace::std;
vector<int> check;

int Find(int current, int n, vector<vector<int>> computers) {
	if (check[current] == 1) {
		return 1;
	}
	check[current] = 1;
	for (int i = 0; i < n; i++) {
		if (i != current && computers[current][i] == 1 && check[i] == 0) {
			Find(i, n, computers);
		}
	}
	return 1;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) check.push_back(0);
	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			answer += Find(i, n, computers);
		}
	}
	return answer;
}

int main(void) {
	int n = 3;
//	vector<vector<int>> computers = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
	vector<vector<int>> computers = { {1, 1, 0},{1, 1, 1},{0, 1, 1} };
	cout << solution(n, computers) << endl;
}