#include<iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;		// 테스트 케이스
	cin >> testCase;
	while (testCase--) {
		string spread;		// 전파를 표현하는 문자열
		cin >> spread;
		bool pattern = true;		// 전파가 제시한 패턴인지에 대한 bool 변수
		int i, j;		// 반복 인덱스
		for (i = 0; i < spread.size(); i++) {		// 문자열의 크기만큼 반복
			if (spread.at(i) == '0') {		// i번째 문자가 0이면
				if (i == spread.size() - 1) {		// i가 마지막 문자라면
					pattern = false;		// NO [ex) 010, 0, ...]
					break;
				}
				if (spread.at(i + 1) != '1') {		// 0 다음 문자가 1이 아니라면
					if (i >= 2) {
						if (spread.at(i - 1) == '1' && spread.at(i - 2) == '1') {		// i-1번째와 i-2번째가 1이라면 [ex)10011001]
							i -= 2;	// 바로 전 위치부터 검사
							continue;
						}
					}
					pattern = false;		// i가 2보다 작다면 NO [ex) 00]
					break;
				}
				i = i + 1;		// 01패턴이 분석되면 다다음위치부터 검사
			}
			else {		// i번째 문자가 1이라면
				if (4 > spread.size() - i) {		// i번째 위치부터 1001이 들어갈 자리가 없다면 NO [ex) 1, 10, 100, 11, ...]
					pattern = false;
					break;
				}
				if (spread.at(i + 1) != '0' || spread.at(i + 2) != '0') {		// 다음위치와 다다음 위치가 0이아니라면 NO [ex) 1111, 1011, 1101, ...]
					pattern = false;
					break;
				}
				for (j = i + 3; j < spread.size(); j++) {		// i 다음 세번째 위치부터 0이아닌 위치 찾아 j에 저장
					if (spread.at(j) != '0') {
						break;
					}
					if (j == spread.size() - 1) {	// 끝까지 0일 경우 NO [ex) 1000, 10000, ...]
						pattern = false;
						break;
					}
				}
				if (j == spread.size() - 1) {		// j가 마지막 위치라면 YES [ex) ...1001, ...10001, ...]
					break;
				}
				for (j = j + 1; j < spread.size(); j++) {		// 1이 아닌 문자가 나올때까지 검사
					if (spread.at(j) != '1') {
						break;
					}
				}
				i = j - 1;		// 1이 아닌 문자가 나온 위치부터 다시 검사
			}
		}
		if (pattern) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}