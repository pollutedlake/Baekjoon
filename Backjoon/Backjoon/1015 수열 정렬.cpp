/*
파일 : 1015 수열 정렬.cpp
작성자 : 박상현
작성일 : 2020.07.12
*/
#include <iostream>
using namespace std;

int A[50];		// 배열 A
int B[50];		// 배열 B(비내림차순으로 정렬된 A)

int compare(const void* a, const void* b) {		// qsort 정렬 비교 함수
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	return num1 > num2;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int length;		// 배열의 크기
	cin >> length;
	for (int i = 0; i < length; i++) {		// A를 입력받고 그래도 B에도 넣어준다.
		cin >> A[i];
		B[i] = A[i];
	}
	qsort(B, length, sizeof(int), compare);		// B 비내림차순으로 정렬
	for (int i = 0; i < length; i++) {		// 탐색은 이진탐색이 빠를 것이나 같은 결과가 나오는 P가 여러개일 경우 사전순으로 앞서는 것을 찾아야 하기에 앞에서부터 탐색한다.
		for (int j = 0; j < length; j++) {
			if (A[i] == B[j]) {		// 같은 값을 찾으면 중복해서 찾지 않게 -1로 바꿔주고 인덱스 출력
				B[j] = -1;
				if (i != length - 1) {
					cout << j << " ";
				}
				else {
					cout << j << endl;
				}
				break;
			}
		}
	}
}