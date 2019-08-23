#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> visit;

void reculsive(vector<vector<int>> computers, int index) {

	for (int i = 1; i < computers.size(); i++) {
		if ((computers[index][i] == 1) && visit[i] == false) {
			visit[i] = true;
			reculsive(computers, i);
		}
	}
}

int main() {
	int n = 3;
	vector<vector<int>> computers;

	vector<int> tmp1;
	tmp1.push_back(1);
	tmp1.push_back(1);
	tmp1.push_back(0);
	computers.push_back(tmp1);

	vector<int> tmp2;
	tmp2.push_back(1);
	tmp2.push_back(1);
	tmp2.push_back(1);
	computers.push_back(tmp2);

	vector<int> tmp3;
	tmp3.push_back(0);
	tmp3.push_back(1);
	tmp3.push_back(1);
	computers.push_back(tmp3);

	int answer = 0;
	vector<bool> visit;
	for (int i = 0; i < n; i++) {
		visit.push_back(false);
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			reculsive(computers, i);
			answer++;
		}
		int cnt = 0;
		for (int j = 0; j < visit.size(); j++) {
			if (visit[i]) {
				cnt++;
			}
		}
		if (cnt == n) {
			cout << to_string(answer) << endl;
		}
	}
}