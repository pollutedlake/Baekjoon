/*
파일 : 1009 분산처리
작성자 : 박상현
작성일 :2020.06.11
*/
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// 테스트케이스
	cin >> testCase;
	int a, b;		// a의 b제곱의 입력을 받기 위한 변수
	while (testCase--) {
		cin >> a >> b;
		switch (a % 10) {		// a의 1의 자리에 따라 경우를 나눈다.
		case 0:		// 1의 자리가 0일경우 몇제곱을 해도 일의 자리가 0이다.
			cout << 10 << endl;
			break;
		case 1:		// 1의 자리가 1일 경우 몇제곱을 해도 1의 자리가 1이다.
			cout << 1 << endl;
			break;
		case 2:		// 2일 경우 2, 4, 8, 6이 반복된다.
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
		case 3:		// 3일 경우 3, 9, 7, 1이 반복된다.
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
		case 4:		// 4일 경우 4, 6이 반복된다.
			switch (b % 2) {
			case 1:
				cout << 4 << endl;
				break;
			case 0:
				cout << 6 << endl;
				break;
			}
			break;
		case 5:		// 5일 경우 몇제곱을 해도 1의자리가 5이다.
			cout << 5 << endl;
			break;
		case 6:		// 6일 경우 몇제곱을 해도 1의 자리가 6이다.
			cout << 6 << endl;
			break;
		case 7:		// 7일 경우 7, 9, 3, 1이 반복된다.
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
		case 8:		// 8일 경우 8, 4, 2, 6이 반복된다.
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
		case 9:		// 9일 경우 9, 1이 반복된다.
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