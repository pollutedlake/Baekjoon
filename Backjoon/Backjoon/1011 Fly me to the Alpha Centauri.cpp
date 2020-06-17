#include<iostream>
#include<math.h>
using namespace std;

// �Ÿ��� d��� 3������ ������ ���� �� �ִ�.
// 1) d�� d�� ������*d�� �����ٰ� ���� ��� d�� ������*2-1�� �۵����� �� �� �ִ�.
// 2) d�� 1)���� ũ�� d�� ������*(d�� ������+1)���� �۰ų� ���� ��� d�� ������*2�� �۵����� �� �� �ִ�.
// 3) d�� 2)���� Ŭ ��� d�� ������*2+1�� �۵����� �� �� �ִ�.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase, x, y;		// �׽�Ʈ ���̽� ��� ����, ���� ����
	cin >> testCase;
	while (testCase--) {
		cin >> x >> y;
		int root = sqrt(y - x);		// �Ÿ��� ������
		if (root * root == (y - x)) {
			cout << root * 2 - 1 << endl;
		}
		else if (root * (root + 1) >= (y - x)) {
			cout << root * 2 << endl;
		}
		else {
			cout << root * 2 + 1 << endl;
		}
	}
}