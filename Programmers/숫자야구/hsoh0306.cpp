#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

// ��Ʈ����ũ �˻� �Լ�
int check_strike(int strike, int query, int ans) {
	int count = 0;
	string a = to_string(query);
	string b = to_string(ans);
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) {
			count++;
		}
	}
	if (count == strike) {
		return 0;
	}
	else {
		return -1;
	}
}

// �� �˻� �Լ�
int check_ball(int ball, int query, int ans) {
	int count = 0;
	string a = to_string(query);
	string b = to_string(ans);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j] && i != j) {
				count++;
			}
		}
	}
	if (count == ball) {
		return 0;
	}
	else {
		return -1;
	}
}


int solution(vector<vector<int>> baseball) {
	int answer = 0;

	vector<int> available;					// Ȯ�ο� vector
	int flag = 0;
	for (int i = 123; i <= 987; i++) {
		flag = 0;
		string c = to_string(i);

		// �ߺ� ���� �˻� || 0 �˻�
		if (c[0] == c[1] || c[1] == c[2] || c[0] == c[2] || c[1] == '0' || c[2] == '0') {
			continue;
		}

		// �ش� ���ڰ� �־��� ���ǿ� �´��� �˻�
		for (int j = 0; j < baseball.size(); j++) {
			int query = baseball[j][0];
			int strike = baseball[j][1];
			int ball = baseball[j][2];
			if (check_strike(strike, query, i) != 0) {		// �ϳ��� ��Ʈ����ũ �Ǵ� �� ���ǿ� ���� ������
				break;										// break
			}
			if (check_ball(ball, query, i) != 0) {
				break;
			}
			flag++;											// flag�� ���� ��� �� �����ߴ��� �˻�
		}
		if (flag == baseball.size()) {						// ��� �����ߴٸ� ����++
			answer++;										// available vector�� Ȯ�ο�
			available.push_back(i);
		}
	}

	return answer;

}

int main(void) {
	vector<vector<int>> t;
	vector<int> s1;
	s1.push_back(123);
	s1.push_back(1);
	s1.push_back(1);

	vector<int> s2;
	s2.push_back(356);
	s2.push_back(1);
	s2.push_back(0);

	vector<int> s3;
	s3.push_back(327);
	s3.push_back(2);
	s3.push_back(0);
	vector<int> s4;
	s4.push_back(489);
	s4.push_back(0);
	s4.push_back(1);

	t.push_back(s1);
	t.push_back(s2);
	t.push_back(s3);
	t.push_back(s4);
	cout << solution(t);
//	check_ball(1, 123, 321);
}