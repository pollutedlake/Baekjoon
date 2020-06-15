/*
���� : 1010 �ٸ� ����
�ۼ��� : �ڻ���
�ۼ��� :2020.06.15
*/
#include<iostream>
using namespace std;

int combination[31][31];		// ���չ迭

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// �׽�Ʈ���̽�
	cin >> testCase;
	for (int i = 1; i <= 30; i++) {		// ������ �̸� ����س��´�.
		for (int j = 0; j <= i / 2; j++) {		// nCr = nCn-r �̹Ƿ� nCn/2������ ����ϸ� �ȴ�.
			if (j == 1) {
				combination[i][j] = i;		// nC1 = n
				continue;
			}
			if (j == 0) {
				combination[i][j] = 1;		// nC0 = 1
				continue;
			}
			if (j > (i - 1) / 2) {		// nCr���� r�� n/2���� Ŭ ��� nCn-r�� ����Ѵ�.
				combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][i - j - 1];
			}
			else {
				combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];		// nCr = n-1Cr-1 + n-1Cr
			}
		}
	}
	while (testCase--) {
		int n, m;		// ���ʰ� ������ ����Ʈ�� ���� n, m
		cin >> n >> m;
		if (n > m / 2) {	// nCr���� r�� n/2���� Ŭ ��� nCn-r�� ����Ѵ�.
			cout << combination[m][m - n] << endl;
		}
		else {
			cout << combination[m][n] << endl;		// mCn���
		}
	}
}