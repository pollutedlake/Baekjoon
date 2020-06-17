/*
파일 : 1021 회전하는 큐
작성자 : 박상현
작성일 :2020.06.15
*/
#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned int n, f;
	cin >> n >> f;
	for (int i = 0; i < 100; i++) {
		if (((n / 100) * 100 + i) % f == 0) {		// n의 가장 뒤 두자리 수를 바꿔가면서 f로 나누어 떨어지는지 확인한다.
			if (i < 10) {		// i가 10보다 작다면 0을 출력하고 i를 출력한다.
				cout << 0;
			}
			cout << i << endl;
			break;
		}
	}
}