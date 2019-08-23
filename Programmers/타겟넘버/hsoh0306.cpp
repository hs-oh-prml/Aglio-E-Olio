#include<iostream>
#include<vector>

using namespace::std;

int DFS(vector<int> numbers, int i, int current, int target) {
	int result = 0;
	if (i == numbers.size()) {
		if(current == target) return 1;
		else return 0;
	}
	else {
		result += DFS(numbers, i + 1, current + numbers[i], target);
		result += DFS(numbers, i + 1, current - numbers[i], target);
		return result;
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	answer = DFS(numbers, 0, 0, target);
	return answer;
}

int main(void) {
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	int target = 3;
	cout << solution(numbers, target);
}