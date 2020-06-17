#include<iostream>
#include<math.h>
using namespace std;

// 거리가 d라면 3가지로 범위를 나눌 수 있다.
// 1) d가 d의 제곱근*d의 제곱근과 같을 경우 d의 제곱근*2-1번 작동으로 갈 수 있다.
// 2) d가 1)보다 크고 d의 제곱근*(d의 제곰근+1)보다 작거나 같을 경우 d의 제곱근*2번 작동으로 갈 수 있다.
// 3) d가 2)보다 클 경우 d의 제곱근*2+1번 작동으로 갈 수 있다.

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase, x, y;		// 테스트 케이스 출발 지점, 도착 지점
	cin >> testCase;
	while (testCase--) {
		cin >> x >> y;
		int root = sqrt(y - x);		// 거리의 제곱근
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