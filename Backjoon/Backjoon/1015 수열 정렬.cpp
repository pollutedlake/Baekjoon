/*
���� : 1015 ���� ����.cpp
�ۼ��� : �ڻ���
�ۼ��� : 2020.07.12
*/
#include <iostream>
using namespace std;

int A[50];		// �迭 A
int B[50];		// �迭 B(�񳻸��������� ���ĵ� A)

int compare(const void* a, const void* b) {		// qsort ���� �� �Լ�
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	return num1 > num2;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int length;		// �迭�� ũ��
	cin >> length;
	for (int i = 0; i < length; i++) {		// A�� �Է¹ް� �׷��� B���� �־��ش�.
		cin >> A[i];
		B[i] = A[i];
	}
	qsort(B, length, sizeof(int), compare);		// B �񳻸��������� ����
	for (int i = 0; i < length; i++) {		// Ž���� ����Ž���� ���� ���̳� ���� ����� ������ P�� �������� ��� ���������� �ռ��� ���� ã�ƾ� �ϱ⿡ �տ������� Ž���Ѵ�.
		for (int j = 0; j < length; j++) {
			if (A[i] == B[j]) {		// ���� ���� ã���� �ߺ��ؼ� ã�� �ʰ� -1�� �ٲ��ְ� �ε��� ���
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