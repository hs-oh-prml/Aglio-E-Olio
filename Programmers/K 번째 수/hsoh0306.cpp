#include<iostream>
#include<vector>
#include<string>
using namespace::std;

int findK(vector<int> array, int K);

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		int start = commands[i][0] - 1;
		int end = commands[i][1] - 1;
		int K = commands[i][2];
		int temp = 0;
		vector<int> sub;
		if (start == end) {
			temp = array[start];
		}
		else {
			for (int j = start; j <= end; j++) {
				sub.push_back(array[j]);
			}
			temp = findK(sub, K);
		}
//		cout << temp << endl;
		answer.push_back(temp);
	}

	return answer;
}

int findK(vector<int> array, int K) {
	int result;
	int count = 0;
	int temp = array[0];
	for (int i = 0; i < K; i++) {

		temp = array[i];

		for (int j = i; j < array.size(); j++) {
			if (array[j] < temp) {
				array[i] = array[j];
				array[j] = temp;
				temp = array[i];
			}
		}
//		cout << array[i] << " ";
	}
//	cout << endl;
	result = array[K - 1];
	return result;
}

int main(void) {
	vector<int> array;
	vector<vector<int>> commands;
	array.push_back(1);
	array.push_back(5);
	array.push_back(2);
	array.push_back(6);
	array.push_back(3);
	array.push_back(7);
	array.push_back(4);

	vector<int> temp1;
	temp1.push_back(2);
	temp1.push_back(5);
	temp1.push_back(3);

	vector<int> temp2;
	temp2.push_back(4);
	temp2.push_back(4);
	temp2.push_back(1);
	vector<int> temp3;
	temp3.push_back(1);
	temp3.push_back(7);
	temp3.push_back(3);

	commands.push_back(temp1);
	commands.push_back(temp2);
	commands.push_back(temp3);

	solution(array, commands);
}