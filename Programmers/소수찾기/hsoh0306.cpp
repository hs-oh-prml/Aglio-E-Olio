#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace::std;

// 완전 탐색 객체
class Brute_Force {
public:
	vector<string> s;								// 모든 순열을 저장하는 vector

	// 완전 탐색 함수(재귀 함수)
	void search(vector<int> arr, vector<int> check, int dept, string str) {
		if (dept == 0) {
			//		cout << "\tThis is Leaf: " << str << endl;
			return;									// 재귀호출이 깊이만큼 반복하면 반환
		}
		// 반복문은 너비 탐색을 의미함
		for (int i = 0; i < arr.size(); i++) {
			if (check[i] == 0) {					// 방문여부 체크
				check[i] = 1;						// 방문 flag를 올림

				string tmp = str;					// 작업
				tmp += to_string(arr[i]);			// 인자로 받은 문자열과 방문한 문자열을 합하여 
													// 새로운 문자열 생성
				s.push_back(tmp);					// 순열 vector에 추가
				/*
				for (int k = dept; k < arr.size(); k++) {
					cout << "\t";
				}
				cout << tmp << endl;
				*/
				search(arr, check, dept - 1, tmp);	// 재귀호출은 깊이 탐색을 의미
													// 재귀호출을 할 때마다 깊이 변수 차감
													// 깊이 변수가 0이 되면 돌아옴
				check[i] = 0;						// 깊이 탐색이 끝나고 돌아온 후 방문 flag 복구
			}

		}
		return;
	}

};

// 소수 검사 함수
bool find_prime_number(int x) {
	if (x < 2) {							// 자연수만 취급 && 1 예외처리
		return false;
	}
	else {
		for (int i = 2; i <= x / 2; i++) {	// 검사 범위 : [2, x/2]
			if (x % i == 0) {				// 나머지가 0이면 소수가 아니므로 false반환
				return false;
			}
		}
		return true;						// 반복문을 빠져 나온거면 약수가 없다는 의미로 true반환
	}
}

int solution(string numbers) {
	int answer = 0;								// 정답 변수
	vector<int> arr;							// 숫자 vector
	vector<int> check;							// 방문 flag vector
	vector<int> p;								// 최종 순열 vector

	// 각 변수 초기화
	for (int i = 0; i < numbers.size(); i++) {
		arr.push_back(numbers[i] - 48);			// ASCII_TO_INT
//		cout << arr[i] << " ";
	}
	for (int i = 0; i < arr.size(); i++) {
		check.push_back(0);
	}

	int dept = arr.size();
	string str = "";
	
	// 완전 탐색 객체 생성
	Brute_Force b = Brute_Force();
	b.search(arr, check, dept, str);

	// string2int
	for (int i = 0; i < b.s.size(); i++) {
		p.push_back(stoi(b.s[i]));
	}

	// 중복 확인을 위한 정렬
	sort(p.begin(), p.end());

	// 중복 체크 변수 초기화
	int before = p[0];

	// 중복 체크
	for (int i = 1; i < p.size(); i++) {
		if (before == p[i]) {		// 이전 값과 현재 값이 같을 경우 중복 플래그(-1)를 올림
			p[i] = -1;
		}
		else {
			before = p[i];			// 중복 값이 아닌 경우 중복 체크 변수 변경
		}
//		cout << p[i] << " ";
	}

	for (int i = 0; i < p.size(); i++) {
		if (p[i] != -1 && find_prime_number(p[i])) {	// 중복 플레그가 아니고 소수일 경우 
			answer++;									// 갯수 추가
		}		
	}
//	cout << endl;

	return answer;
}


int main(void) {
	cout << solution("011") << endl;
	
}