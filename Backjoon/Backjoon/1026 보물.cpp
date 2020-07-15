/*
���� : 1026 ����.cpp
�ۼ��� : �ڻ���
�ۼ��� : 2020.07.15
*/
#include<iostream>
using namespace std;

int A[50];		// �迭 A
int B[50];		// �迭 B

int asc(const void* first, const void* second) {		// ��������
	return *(int*)first > * (int*)second;
}

int desc(const void* first, const void* second) {		// ��������
	return *(int*)first < *(int*)second;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int length;		// �迭�� ����
	cin >> length;
	for (int i = 0; i < length; i++) {		// A�� �Է¹޴´�.
		cin >> A[i];
	}
	for (int i = 0; i < length; i++) {		// B�� �Է¹޴´�.
		cin >> B[i];
	}
	// A[i]*B[i]���� ���� �ּҷ� �Ϸ��� A[i]*B[i]�� �ּҷ� �ؾ� �ϴµ� ū B[i]�� ���� A[i]�� �����ָ� �ȴ�. ���� A�� B�� ������ �ݴ�� ��迭�ؼ� �����ָ� �ȴ�.
	qsort(A, length, sizeof(int), asc);		// A�� ������������ ��迭
	qsort(B, length, sizeof(int), desc);	// B�� ������������ ��迭
	int sum = 0;		// A[i]*B[i]���� ��
	for (int i = 0; i < length; i++) {
		sum += A[i] * B[i];
	}
	cout << sum << endl;
}