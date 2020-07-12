#include<iostream>
#include<algorithm>
using namespace std;

int square[50][50];		// 직사각형 배열

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;		// 직사각형의 행과 열 크기
	cin >> N >> M;
	string s;		// 한 행의 숫자들
	for (int i = 0; i < N; i++) {		// 직사각형 입력 받기
		cin >> s;
		for (int j = 0; j < M; j++) {
			square[i][j] = int(s.at(j));
		}
	}
	for (int i = min(N, M) - 1; i > 0; i--) {		// 나올 수 있는 정사각형의 최대 길이가 min(N, M)이다.
		for (int j = 0; j < N - i; j++) {
			for (int k = 0; k < M - i; k++) {
				if ((square[j][k] == square[j][k + i]) && (square[j][k] == square[j + i][k]) && (square[j][k] == square[j + i][k + i])) { // 각 꼭짓점의 값이 같은 정사각형을 찾으면 그 정사각형이 최대 크기이다.
					cout << (i + 1) * (i + 1) << endl;
					return 0;
				}
			}
		}
	}
	cout << 1 << endl;
}