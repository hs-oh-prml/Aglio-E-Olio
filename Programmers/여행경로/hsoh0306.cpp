#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;
bool compare(vector<string> a, vector<string> b) {				// sort()��  custom compare �Լ�
	if (a[0] == "ICN" && b[0] == "ICN") return a[1] < b[1];		// �������� ICN�̹Ƿ� ICN�� ������ ������ �;���
	else if (a[0] == "ICN" && b[0] != "ICN") return true;		// ������� ICN�� Ƽ���� �������� ��� 
	else if (a[0] != "ICN" && b[0] == "ICN") return false;		// ���� ������ ����
	else return a < b;											// �������� ���� ������ ����
}
int Find(vector<string> *answer, vector<vector<string>> tickets, vector<int> check) {	// DFS
	for (int i = 0; i < tickets.size(); i++) {											// �� �� �ִ� Ƽ�� ã��
		if ((*answer)[(*answer).size() - 1] == tickets[i][0] && check[i] == 0) {		// ���� ����� �� �������� ������� Ƽ�� ã��
			check[i] = 1;																// ã�� ��� Ƽ���� �������� ��ο� �߰�
			(*answer).push_back(tickets[i][1]);											// ���ȣ��
			if (Find(answer, tickets, check) == -1) {									// �Լ��� ���� Fail Code�� ���
				(*answer).pop_back();													// �湮 �÷��׸� ������, �������� �߰��� ��� ����
				check[i] = 0;
			}
		}
	}
	if ((*answer).size() == tickets.size() + 1) return 0;								// ��� Ƽ���� ������� ���, ����� ���̴� Ƽ���� �� + 1
	else return -1;		// Fail															// Ƽ���� ��� ������� �ʾ��� ���, Fail Code(-1) return
}
vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end(), compare);					// Ƽ�� ����
	vector<string> answer;											// ���� ����
	vector<int> check;												// �湮 üũ ���� & �ʱ�ȭ
	for (int i = 0; i < tickets.size(); i++) check.push_back(0);	
	answer.push_back("ICN");										// ù����� ����("ICN")
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