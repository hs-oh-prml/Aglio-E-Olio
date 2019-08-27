#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;
bool compare(vector<string> a, vector<string> b) {				// sort()의  custom compare 함수
	if (a[0] == "ICN" && b[0] == "ICN") return a[1] < b[1];		// 시작점이 ICN이므로 ICN의 순서가 앞으로 와야함
	else if (a[0] == "ICN" && b[0] != "ICN") return true;		// 출발지가 ICN인 티켓이 여러개일 경우 
	else if (a[0] != "ICN" && b[0] == "ICN") return false;		// 사전 순으로 정렬
	else return a < b;											// 나머지는 사전 순으로 정렬
}
int Find(vector<string> *answer, vector<vector<string>> tickets, vector<int> check) {	// DFS
	for (int i = 0; i < tickets.size(); i++) {											// 갈 수 있는 티켓 찾기
		if ((*answer)[(*answer).size() - 1] == tickets[i][0] && check[i] == 0) {		// 현재 경로의 맨 마지막이 출발지인 티켓 찾기
			check[i] = 1;																// 찾을 경우 티켓의 도착지를 경로에 추가
			(*answer).push_back(tickets[i][1]);											// 재귀호출
			if (Find(answer, tickets, check) == -1) {									// 함수의 값이 Fail Code일 경우
				(*answer).pop_back();													// 방문 플래그를 내리고, 마지막에 추가한 경로 제거
				check[i] = 0;
			}
		}
	}
	if ((*answer).size() == tickets.size() + 1) return 0;								// 모든 티켓을 사용했을 경우, 경로의 길이는 티켓의 수 + 1
	else return -1;		// Fail															// 티켓을 모두 사용하지 않았을 경우, Fail Code(-1) return
}
vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end(), compare);					// 티켓 정렬
	vector<string> answer;											// 정답 벡터
	vector<int> check;												// 방문 체크 벡터 & 초기화
	for (int i = 0; i < tickets.size(); i++) check.push_back(0);	
	answer.push_back("ICN");										// 첫출발지 설정("ICN")
	Find(&answer, tickets, check);									// DFS
	return answer;
}
int main(void) {
	/*
	vector<vector<string>> tickets = {
	{ "ICN", "JFK" },
	{ "HND", "IAD" },
	{ "JFK", "HND" }
	};
	vector<vector<string>> tickets = {
		{ "ICN", "ATL" },
		{ "ICN", "SFO" },
		{ "SFO", "ATL" },
		{ "ATL", "ICN" },
		{ "ATL", "SFO" }
	};
	*/
	vector<vector<string>> tickets = 
	{ 
		{ "ICN", "BOO" }, 
		{ "ICN", "COO" }, 
		{ "COO", "DOO" }, 
		{ "DOO", "COO" }, 
		{ "BOO", "DOO" },
		{ "DOO", "BOO" }, 
		{ "BOO", "ICN" }, 
		{ "COO", "BOO" } 
	};

	vector<string> answer = solution(tickets);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}