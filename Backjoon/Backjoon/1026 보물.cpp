/*
파일 : 1026 보물.cpp
작성자 : 박상현
작성일 : 2020.07.15
*/
#include<iostream>
using namespace std;

int A[50];		// 배열 A
int B[50];		// 배열 B

int asc(const void* first, const void* second) {		// 오름차순
	return *(int*)first > * (int*)second;
}

int desc(const void* first, const void* second) {		// 내림차순
	return *(int*)first < *(int*)second;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int length;		// 배열의 길이
	cin >> length;
	for (int i = 0; i < length; i++) {		// A를 입력받는다.
		cin >> A[i];
	}
	for (int i = 0; i < length; i++) {		// B를 입력받는다.
		cin >> B[i];
	}
	// A[i]*B[i]들의 합을 최소로 하려면 A[i]*B[i]를 최소로 해야 하는데 큰 B[i]에 작은 A[i]를 곱해주면 된다. 따라서 A와 B의 순서를 반대로 재배열해서 곱해주면 된다.
	qsort(A, length, sizeof(int), asc);		// A를 오름차순으로 재배열
	qsort(B, length, sizeof(int), desc);	// B를 내림차순으로 재배열
	int sum = 0;		// A[i]*B[i]들의 합
	for (int i = 0; i < length; i++) {
		sum += A[i] * B[i];
	}
	cout << sum << endl;
}