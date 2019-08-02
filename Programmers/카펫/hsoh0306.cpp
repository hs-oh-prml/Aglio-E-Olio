#include<iostream>
#include<vector>
using namespace::std;
vector<int> solution(int brown, int red){
	vector<int> answer;
	int row = 0;
	int col = 0;

	for (int i = 1; i <= red; i++) {
		if (red % i != 0) {
			continue;
		}
		row = red / i;
		col = i;
		int temp = row * 2 + col * 2 + 4;
		if (temp == brown) {
			row += 2;
			col += 2;
			break;
		}
	}
//	cout << row << " " << col << endl;
	answer.push_back(row);
	answer.push_back(col);
	return answer;
}
int main(void) {
	solution(10, 2);
	solution(8, 1);
	solution(24, 24);
}