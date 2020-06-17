#include<iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, kjm, ihs;		// 참가자의 수, 김지민과 임한수가 1라운드에 받는 번호
	cin >> n >> kjm >> ihs;
	int round = 1;		// 김지민과 임한수가 만나는 라운드 수
	while ((kjm + 1) / 2 != (ihs + 1) / 2) {		// 김지민과 임한수가 만날 때까지
		if (n == 1) {		// 남은 참가자의 수가 1이 될때까지 반복된다면 만나지 않는다.
			cout << -1 << endl;
			return 0;
		}
		kjm = (kjm + 1) / 2;		// 김지민의 다음 라운드에 받을 번호
		ihs = (ihs + 1) / 2;		// 임한수의 다음 라운드에 받을 번호
		if (n % 2 == 0) {		// 참가자의 수가 짝수 일 때 다음 라운드에 진출할 수
			n /= 2;
		}
		else {		// 참가자의 수가 홀 수 일 때 다음라운드에 진출할 수
			n = n / 2 + 1;
		}
		round++;
	}
	cout << round << endl;
}