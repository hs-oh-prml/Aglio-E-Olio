#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers, int target) {
	int answer = 0;
	for (int i = 0; i <= numbers.size(); i++) {
		vector<int> temp;
		int index = i;
		for (int j = 0; j < index; j++) {
			temp.push_back(1);
		}
		for (int j = 0; j < numbers.size() - index; j++) {
			temp.push_back(0);
		}

		sort(temp.begin(), temp.end());

		do {
			int sum = 0;
			for (int j = 0; j < temp.size(); j++) {
				if (temp[j] == 1) {
					sum += numbers[j] * (-1);
				}
				else {
					sum += numbers[j];
				}
			}

			if (sum == target) {
				answer++;
			}

		} while (next_permutation(temp.begin(), temp.end()));
	}
	return answer;
}