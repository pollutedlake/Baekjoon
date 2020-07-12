#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// 테스트 케이스
	cin >> testCase;
	while (testCase--) {
		int sum = 0;		// 짝수들의 합
		int min = 100;		// 짝수 중의 최솟값
		for (int i = 0; i < 7; i++) {
			int num;		// 입력받는 수
			cin >> num;
			if (num % 2 == 0) {		 // 짝수라면
				sum += num;		// 더하고
				if (min > num) {		// 최솟값인지 비교
					min = num;
				}
			}
		}
		cout << sum << " " << min << endl;		// 짝수의 합과 짝수 중 최솟값 출력
	}
}