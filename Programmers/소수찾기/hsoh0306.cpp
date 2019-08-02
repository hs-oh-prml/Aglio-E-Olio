#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

// ���� Ž�� ��ü
class Brute_Force {
public:
	vector<string> s;								// ��� ������ �����ϴ� vector

	// ���� Ž�� �Լ�(��� �Լ�)
	void search(vector<int> arr, vector<int> check, int dept, string str) {
		if (dept == 0) {
			//		cout << "\tThis is Leaf: " << str << endl;
			return;									// ���ȣ���� ���̸�ŭ �ݺ��ϸ� ��ȯ
		}
		// �ݺ����� �ʺ� Ž���� �ǹ���
		for (int i = 0; i < arr.size(); i++) {
			if (check[i] == 0) {					// �湮���� üũ
				check[i] = 1;						// �湮 flag�� �ø�

				string tmp = str;					// �۾�
				tmp += to_string(arr[i]);			// ���ڷ� ���� ���ڿ��� �湮�� ���ڿ��� ���Ͽ� 
													// ���ο� ���ڿ� ����
				s.push_back(tmp);					// ���� vector�� �߰�
				/*
				for (int k = dept; k < arr.size(); k++) {
					cout << "\t";
				}
				cout << tmp << endl;
				*/
				search(arr, check, dept - 1, tmp);	// ���ȣ���� ���� Ž���� �ǹ�
													// ���ȣ���� �� ������ ���� ���� ����
													// ���� ������ 0�� �Ǹ� ���ƿ�
				check[i] = 0;						// ���� Ž���� ������ ���ƿ� �� �湮 flag ����
			}

		}
		return;
	}

};

// �Ҽ� �˻� �Լ�
bool find_prime_number(int x) {
	if (x < 2) {							// �ڿ����� ��� && 1 ����ó��
		return false;
	}
	else {
		for (int i = 2; i <= x / 2; i++) {	// �˻� ���� : [2, x/2]
			if (x % i == 0) {				// �������� 0�̸� �Ҽ��� �ƴϹǷ� false��ȯ
				return false;
			}
		}
		return true;						// �ݺ����� ���� ���°Ÿ� ����� ���ٴ� �ǹ̷� true��ȯ
	}
}

int solution(string numbers) {
	int answer = 0;								// ���� ����
	vector<int> arr;							// ���� vector
	vector<int> check;							// �湮 flag vector
	vector<int> p;								// ���� ���� vector

	// �� ���� �ʱ�ȭ
	for (int i = 0; i < numbers.size(); i++) {
		arr.push_back(numbers[i] - 48);			// ASCII_TO_INT
//		cout << arr[i] << " ";
	}
	for (int i = 0; i < arr.size(); i++) {
		check.push_back(0);
	}

	int dept = arr.size();
	string str = "";
	
	// ���� Ž�� ��ü ����
	Brute_Force b = Brute_Force();
	b.search(arr, check, dept, str);

	// string2int
	for (int i = 0; i < b.s.size(); i++) {
		p.push_back(stoi(b.s[i]));
	}

	// �ߺ� Ȯ���� ���� ����
	sort(p.begin(), p.end());

	// �ߺ� üũ ���� �ʱ�ȭ
	int before = p[0];

	// �ߺ� üũ
	for (int i = 1; i < p.size(); i++) {
		if (before == p[i]) {		// ���� ���� ���� ���� ���� ��� �ߺ� �÷���(-1)�� �ø�
			p[i] = -1;
		}
		else {
			before = p[i];			// �ߺ� ���� �ƴ� ��� �ߺ� üũ ���� ����
		}
//		cout << p[i] << " ";
	}

	for (int i = 0; i < p.size(); i++) {
		if (p[i] != -1 && find_prime_number(p[i])) {	// �ߺ� �÷��װ� �ƴϰ� �Ҽ��� ��� 
			answer++;									// ���� �߰�
		}		
	}
//	cout << endl;

	return answer;
}


int main(void) {
	cout << solution("011") << endl;
	
}