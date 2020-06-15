/*
파일 : 1021 회전하는 큐
작성자 : 박상현
작성일 :2020.06.15
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> queue;		// 양방향 순환 큐
	int queueSize;		// 큐의 크기
	int selectN;		// 뽑을 원소 개수
	int minCalc = 0;		// 최소한의 연산 횟수
	cin >> queueSize >> selectN;
	for (int i = 1; i <= queueSize; i++) {		// 양방향 순환 큐에 1부터 큐의 크기까지 넣는다.
		queue.push_back(i);
	}
	for (int i = 0; i < selectN; i++) {
		int select;		// 뽑을 원소
		int at;		// 뽑을 원소가 있는 위치
		bool right = true;		// 오른쪽으로 이동시킬지 bool 변수
		cin >> select;
		while (queue.front() != select) {		// 큐의 첫 번째 원소가 뽑을 원소가 될때까지 반복
			for (int j = 0; j < queue.size(); j++) {		// 뽑을 원소가 있는 위치 알아내기
				if (queue.at(j) == select) {
					at = j;
				}
			}
			if (at < queue.size() - at + 1) {		// 뽑을 원소가 어느 쪽으로 이동시켜야 빠른지 검사하고 이동 방향 결정
				right = false;
			}
			if (right) {		// 오른쪽이 빠르다면 오른쪽으로 이동
				queue.insert(queue.begin(), queue.back());
				queue.pop_back();
			}
			else {		// 왼쪽이 빠르다면 왼쪽으로 이동
				queue.push_back(queue.front());
				queue.erase(queue.begin());
			}
			minCalc++;		// 연산 횟수 증가
		}
		queue.erase(queue.begin());		// 뽑는다.
	}
	cout << minCalc << endl;		// 최소 연산 횟수 출력
}