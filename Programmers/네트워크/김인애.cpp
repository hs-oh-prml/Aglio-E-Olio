#include <string>
#include <vector>

using namespace std;

vector<bool> visit;

void reculsive(vector<vector<int>> computers, int index) {

	for (int i = 1; i < computers.size(); i++) {
		if ((computers[index][i] == 1) && !visit[i]) {
			visit[i] = true;
			reculsive(computers, i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		visit.push_back(false);
	}

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			reculsive(computers, i);
			answer++;
		}
	}
	return answer;
}