#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// �׽�Ʈ ���̽�
	cin >> testCase;
	while (testCase--) {
		int sum = 0;		// ¦������ ��
		int min = 100;		// ¦�� ���� �ּڰ�
		for (int i = 0; i < 7; i++) {
			int num;		// �Է¹޴� ��
			cin >> num;
			if (num % 2 == 0) {		 // ¦�����
				sum += num;		// ���ϰ�
				if (min > num) {		// �ּڰ����� ��
					min = num;
				}
			}
		}
		cout << sum << " " << min << endl;		// ¦���� �հ� ¦�� �� �ּڰ� ���
	}
}