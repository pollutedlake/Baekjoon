/*
파일 : 1010 다리 놓기
작성자 : 박상현
작성일 :2020.06.15
*/
#include<iostream>
using namespace std;

int combination[31][31];		// 조합배열

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// 테스트케이스
	cin >> testCase;
	for (int i = 1; i <= 30; i++) {		// 조합을 미리 계산해놓는다.
		for (int j = 0; j <= i / 2; j++) {		// nCr = nCn-r 이므로 nCn/2까지만 계산하면 된다.
			if (j == 1) {
				combination[i][j] = i;		// nC1 = n
				continue;
			}
			if (j == 0) {
				combination[i][j] = 1;		// nC0 = 1
				continue;
			}
			if (j > (i - 1) / 2) {		// nCr에서 r이 n/2보다 클 경우 nCn-r로 계산한다.
				combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][i - j - 1];
			}
			else {
				combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];		// nCr = n-1Cr-1 + n-1Cr
			}
		}
	}
	while (testCase--) {
		int n, m;		// 서쪽과 동쪽의 사이트의 개수 n, m
		cin >> n >> m;
		if (n > m / 2) {	// nCr에서 r이 n/2보다 클 경우 nCn-r로 계산한다.
			cout << combination[m][m - n] << endl;
		}
		else {
			cout << combination[m][n] << endl;		// mCn출력
		}
	}
}