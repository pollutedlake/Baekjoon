/*
���� : 1009 �л�ó��
�ۼ��� : �ڻ���
�ۼ��� :2020.06.11
*/
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// �׽�Ʈ���̽�
	cin >> testCase;
	int a, b;		// a�� b������ �Է��� �ޱ� ���� ����
	while (testCase--) {
		cin >> a >> b;
		switch (a % 10) {		// a�� 1�� �ڸ��� ���� ��츦 ������.
		case 0:		// 1�� �ڸ��� 0�ϰ�� �������� �ص� ���� �ڸ��� 0�̴�.
			cout << 10 << endl;
			break;
		case 1:		// 1�� �ڸ��� 1�� ��� �������� �ص� 1�� �ڸ��� 1�̴�.
			cout << 1 << endl;
			break;
		case 2:		// 2�� ��� 2, 4, 8, 6�� �ݺ��ȴ�.
			switch (b % 4) {
			case 1:
				cout << 2 << endl;
				break;
			case 2:
				cout << 4 << endl;
				break;
			case 3:
				cout << 8 << endl;
				break;
			case 0:
				cout << 6 << endl;
				break;
			}
			break;
		case 3:		// 3�� ��� 3, 9, 7, 1�� �ݺ��ȴ�.
			switch (b % 4) {
			case 1:
				cout << 3 << endl;
				break;
			case 2:
				cout << 9 << endl;
				break;
			case 3:
				cout << 7 << endl;
				break;
			case 0:
				cout << 1 << endl;
				break;
			}
			break;
		case 4:		// 4�� ��� 4, 6�� �ݺ��ȴ�.
			switch (b % 2) {
			case 1:
				cout << 4 << endl;
				break;
			case 0:
				cout << 6 << endl;
				break;
			}
			break;
		case 5:		// 5�� ��� �������� �ص� 1���ڸ��� 5�̴�.
			cout << 5 << endl;
			break;
		case 6:		// 6�� ��� �������� �ص� 1�� �ڸ��� 6�̴�.
			cout << 6 << endl;
			break;
		case 7:		// 7�� ��� 7, 9, 3, 1�� �ݺ��ȴ�.
			switch (b % 4) {
			case 1:
				cout << 7 << endl;
				break;
			case 2:
				cout << 9 << endl;
				break;
			case 3:
				cout << 3 << endl;
				break;
			case 0:
				cout << 1 << endl;
				break;
			}
			break;
		case 8:		// 8�� ��� 8, 4, 2, 6�� �ݺ��ȴ�.
			switch (b % 4) {
			case 1:
				cout << 8 << endl;
				break;
			case 2:
				cout << 4 << endl;
				break;
			case 3:
				cout << 2 << endl;
				break;
			case 0:
				cout << 6 << endl;
				break;
			}
			break;
		case 9:		// 9�� ��� 9, 1�� �ݺ��ȴ�.
			switch (b % 2) {
			case 1:
				cout << 9 << endl;
				break;
			case 0:
				cout << 1 << endl;
			}
			break;
		}
	}
}