#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace::std;
// Enable Word Check
bool isEnable(string s, string word) {
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != word[i]) {
			count++;
		}
		if (count > 1) {
			return false;
		}
	}
	return true;
}

int BFS(string begin, string target, vector<string> words, vector<int> check) {
	int answer = 0;
	queue<string> q;
	queue<int> index;

	// 가능한 후보들 큐에 저장 -> 너비 탐색
	for (int i = 0; i < words.size(); i++) {

		if (isEnable(begin, words[i]) && check[i] == 0) {

			if (words[i] == target) {
				return 1;
			}
			q.push(words[i]);
			index.push(i);
		}
	}

	// 재귀 호출 깊이 탐색
	for (int i = 0; i < q.size(); i++) {

		check[index.front()] = 1;

		answer = BFS(q.front(), target, words, check);
		if (answer != 0) {
			return ++answer;
		}
		check[index.front()] = 0;

		q.pop();
		index.pop();
	}

	return 0;		// Fail

}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	vector<int> check;
	for (int i = 0; i < words.size(); i++) check.push_back(0);
	answer = BFS(begin, target, words, check);
	return answer;
}

int main(void) {
	string begin = "hit";
	string target = "cog";

//	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	vector<string> words = { "hot", "dot", "dog", "lot", "log"};
	cout << solution(begin, target, words) << endl;
}