/*
���� : 1021 ȸ���ϴ� ť
�ۼ��� : �ڻ���
�ۼ��� :2020.06.15
*/
#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned int n, f;
	cin >> n >> f;
	for (int i = 0; i < 100; i++) {
		if (((n / 100) * 100 + i) % f == 0) {		// n�� ���� �� ���ڸ� ���� �ٲ㰡�鼭 f�� ������ ���������� Ȯ���Ѵ�.
			if (i < 10) {		// i�� 10���� �۴ٸ� 0�� ����ϰ� i�� ����Ѵ�.
				cout << 0;
			}
			cout << i << endl;
			break;
		}
	}
}