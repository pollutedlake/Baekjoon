/*
파일 : 1137 다리 놓기
작성자 : 박상현
작성일 :2020.07.01
*/
#include<iostream>
using namespace std;

int tall[10];		// 키 순서대로 자기보다 키가 큰 사람이 왼쪽에 있는 수를 저장하는 배열
int order[10];		// 줄을 선 순서대로 키를 저장하는 배열

int main() {
	int N;		// 사람의 수
	cin >> N;
	for (int i = 0; i < N; i++) {		// 키 순서대로 자기보다 키가 큰 사람이 왼쪽에 있는 수를 입력받는다.
		cin >> tall[i];
	}
	for (int i = 0; i < N; i++) {		// 사람의 수만큼 반복
		int count = 0;		// 자신보다 왼쪽에 있을 수 있는 사람 수
		for (int j = 0; j < N; j++) {		// 줄을 탐색
			if (order[j] == 0) {		// 아직 줄을 서지 않은 공간이라면
				if (count == tall[i]) {		// 자신보다 왼족에 있을 수 있는 사람 수가 자기보다 키가 큰 사람이 왼쪽에 있는 수와 같다면
					order[j] = i + 1;		// 그 자리에 자신의 키를 저장하고 반복문을 빠져나간다.
					break;
				}
				else {		// 같지 않다면 count증가
					count++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {		// 줄을 선 순서대로 키를 출력
		cout << order[i] << " ";
	}
	cout << endl;
}